//- -----------------------------------------------------------------------------------------------------------------------
// AskSin++
// 2016-10-31 papa Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
// 2020-09-14 jp112sdl Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
//- -----------------------------------------------------------------------------------------------------------------------

#ifndef __KEYPADBUTTON_H__
#define __KEYPADBUTTON_H__

namespace as {

class KeypadButton: public Alarm {

#define DEBOUNCETIME millis2ticks(50)

  public:
    enum States {
      invalid = 0,
      none = 1,
      released = 2,
      pressed = 3,
      debounce = 4,
      longpressed = 5,
      longreleased = 6,
    };

  protected:
    uint8_t  stat     : 3;
    uint8_t  pinstate : 1;

    uint16_t longpresstime;

  public:
    KeypadButton() : Alarm(0), stat(none), pinstate(false), longpresstime(millis2ticks(400)) { }
    virtual ~KeypadButton() {}

    void setLongPressTime(uint16_t t) {
      longpresstime = t;
    }

    virtual void trigger(AlarmClock& clock) {
      uint8_t  nextstate = invalid;
      uint16_t nexttick = 0;
      switch ( state() ) {
        case released:
        case longreleased:
          nextstate = none;
          break;

        case debounce:
          nextstate = pressed;
          if (pinstate == true) {
            // set timer for detect longpressed
            nexttick = longpresstime - DEBOUNCETIME;
          } else {
            nextstate = released;
            nexttick = DEBOUNCETIME;
          }
          break;

        case pressed:
        case longpressed:
          if ( pinstate == true) {
            nextstate = longpressed;
            nexttick = longpresstime;
          }
          break;
      }
      // reactivate alarm if needed
      if ( nexttick != 0 ) {
        tick = nexttick;
        clock.add(*this);
      }
      // trigger the state change
      if ( nextstate != invalid ) {
        state(nextstate);
      }
    }

    virtual void state(uint8_t s) {
      switch (s) {
          /*case released: DPRINTLN(F(" released")); break;
            case pressed: DPRINTLN(F(" pressed")); break;
            case debounce: DPRINTLN(F(" debounce")); break;
            case longpressed: DPRINTLN(F(" longpressed")); break;
            case longreleased: DPRINTLN(F(" longreleased")); break;
            default: DPRINTLN(F("")); break;*/
      }
      stat = s;
    }

    uint8_t state() const {
      return stat;
    }

    virtual void check(bool b) {
      uint8_t ps = b;
      if ( pinstate != ps ) {
        pinstate = ps;
        uint16_t nexttick = 0;
        uint8_t  nextstate = state();
        switch ( state() ) {
          case none:
            nextstate = debounce;
            nexttick = DEBOUNCETIME;
            break;

          case pressed:
          case longpressed:
            if (pinstate == false) {
              nextstate = state() == pressed ? released : longreleased;
              nexttick = DEBOUNCETIME;
            }
            break;
          default:
            break;
        }
        if ( nexttick != 0 ) {
          sysclock.cancel(*this);
          tick = nexttick;
          sysclock.add(*this);
        }
        if ( nextstate != state () ) {
          state(nextstate);
        }
      }
    }
};


template <class DEVTYPE>
class KeyPad {
  public:
    class ScanKeypadAlarm : public Alarm {
      public:
        KeyPad& mkb;
        ScanKeypadAlarm (KeyPad& _mkp) : Alarm(0), mkb(_mkp) {}
        virtual ~ScanKeypadAlarm () {}
        virtual void trigger(__attribute__((unused)) AlarmClock& clock) {
          mkb.scanKeypad();
        }
    };

  private:
    DEVTYPE& device;
    uint8_t colpin[8];
    uint8_t rowpin[8];
    uint8_t colcount;
    uint8_t rowcount;

    ScanKeypadAlarm scka;
    bool irqEnabled;

  public:
    KeyPad(DEVTYPE& dev) : device(dev), colcount(0), rowcount(0), scka(*this), irqEnabled(false) { }
    virtual ~KeyPad() {}

    void irq () {
      if (irqEnabled == true) {
        irqEnabled = false;
        scanKeypad();
      }
    }

    void scanKeypad() {
      uint8_t bnum = 0;

      for (uint8_t r = 0; r < rowcount; r++) {
        digitalWrite(rowpin[r], HIGH);
        for (uint8_t c = 0; c < colcount; c++) {
          if (digitalRead(colpin[c]) == LOW) {
            bnum = (rowcount * r) + (c + 1);
            break;
          }
        }
        digitalWrite(rowpin[r], LOW);
      }

      if (bnum > 0) {
        device.channel(bnum).check(true);
        sysclock.cancel(scka);
        scka.set(1);
        sysclock.add(scka);
      } else {
        for (uint8_t i = 0; i < 4; i++)
          device.channel(i + 1).check(false);
        irqEnabled = true;
      }

    }

    void init(const uint8_t * colpins, const uint8_t * rowpins, uint8_t numcols, uint8_t numrows) {
      this->colcount = numcols;
      this->rowcount = numrows;

      for (uint8_t i = 0; i < numcols; i++) {
        this->colpin[i] = colpins[i];
        pinMode(colpins[i], INPUT_PULLUP);
      }

      for (uint8_t i = 0; i < numrows; i++) {
        this->rowpin[i] = rowpins[i];
        pinMode(rowpin[i], OUTPUT);
        digitalWrite(rowpin[i], LOW);
      }

      //Enable ISR with a small delay
      _delay_ms(10);
      irqEnabled = true;
    }

};

#define KeyPadISR(btn, colpins, rowpins, numcols, numrows) class btn##ISRHandler { \
    public: \
      static void isr () { btn.irq(); } \
  }; \
  btn.init(colpins, rowpins, numcols, numrows); \
  for (uint8_t i = 0;i<numcols;i++) {\
    if( digitalPinToInterrupt(colpins[i]) == NOT_AN_INTERRUPT ) \
      enableInterrupt(colpins[i],btn##ISRHandler::isr,FALLING); \
    else \
      attachInterrupt(digitalPinToInterrupt(colpins[i]),btn##ISRHandler::isr,FALLING);\
  }
}

#endif
