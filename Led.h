//- -----------------------------------------------------------------------------------------------------------------------
// AskSin++
// 2016-10-31 papa Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
//- -----------------------------------------------------------------------------------------------------------------------

#ifndef __STATUSLED_H__
#define __STATUSLED_H__

#include "Alarm.h"

namespace as {

class LedStates {
public:
  enum Mode { nothing=0, pairing=1,send=2, ack=3,
    nack=4, bat_low=5, welcome=6, key_long=7, failure=8 };

  struct BlinkPattern {
    uint8_t  length;
    uint8_t  duration;
    uint8_t  pattern[6];
  };

  static const BlinkPattern dual1[9] PROGMEM;
  static const BlinkPattern dual2[9] PROGMEM;
};

class Led : public Alarm, public LedStates {
private:
  BlinkPattern current;
  uint8_t step;   // current step in pattern
  uint8_t repeat; // current repeat of the pattern
  uint8_t pin;
  uint8_t inv;

  void copyPattern (Mode stat,const BlinkPattern* patt) {
    memcpy_P(&current,patt+stat,sizeof(BlinkPattern));
  }

  void next (AlarmClock& clock) {
    tick = decis2ticks(current.pattern[step++]);
    ((step & 0x01) == 0x01) ? ledOn() : ledOff();
    clock.add(*this);
  }

public:
  Led () : Alarm(0), step(0), repeat(0), pin(0), inv(false) {
    async(true);
  }
  virtual ~Led() {}

  void init (uint8_t p) {
    pin = p;
    pinMode(pin, OUTPUT);
    ledOff();
  }

  void invert (bool value) {
    inv = value;
  }

  bool invert () const {
    return inv;
  }

  void set(Mode stat,const BlinkPattern* patt) {
    sysclock.cancel(*this);
    ledOff();
    copyPattern(stat,patt);
    if( current.length > 0 ) {
      step = 0;
      repeat = 0;
      next(sysclock);
    }
  }

  void ledOff () {
    if( invert() == true ) {
      digitalWrite(pin, HIGH);
    }
    else {
      digitalWrite(pin, LOW);
    }
  }

  void ledOn () {
    if( invert() == true ) {
      digitalWrite(pin, LOW);
    }
    else {
      digitalWrite(pin, HIGH);
    }
  }

  void ledOn (uint32_t ticks) {
    if( active() == false && ticks > 0 ) {
      current.length = 2;
      current.duration = 1;
      current.pattern[0] = ticks2decis(ticks);
      current.pattern[1] = 0;
      // start the pattern
      step = repeat = 0;
      next(sysclock);
    }
  }

  bool active () const { return current.length != 0; }

  virtual void trigger (AlarmClock& clock) {
    ATOMIC_BLOCK( ATOMIC_RESTORESTATE ) {
      if( step < current.length ) {
        next(clock);
      }
      else {
        step = 0;
        if( current.duration == 0 || ++repeat < current.duration ) {
          next(clock);
        }
        else {
          ledOff();
          copyPattern(nothing,dual1);
        }
      }
    }
  }
};


template <uint8_t LEDPIN1,uint8_t LEDPIN2>
class DualStatusLed : public LedStates  {
private:
  Led led1;
  Led led2;
public:
  DualStatusLed () {}
  void init () { led1.init(LEDPIN1); led2.init(LEDPIN2); }
  bool active () const { return led1.active() || led2.active(); }
  void ledOn (uint32_t ticks) { led1.ledOn(ticks); led2.ledOn(ticks); }
  void ledOn (uint32_t ticks,uint32_t tacks) { led1.ledOn(ticks); led2.ledOn(tacks); }
  void set(Mode stat) { led1.set(stat,dual1); led2.set(stat,dual2); }
  void ledOn () { led1.ledOn(); led2.ledOn(); }
  void ledOff () { led1.ledOff(); led2.ledOff(); }
  void invert (bool value) { led1.invert(value); led2.invert(value); }
};


}

#endif
