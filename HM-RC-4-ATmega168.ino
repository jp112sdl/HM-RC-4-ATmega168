//- -----------------------------------------------------------------------------------------------------------------------
// AskSin++
// 2016-10-31 papa Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
// 2020-09-15 jp112sdl Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
//- -----------------------------------------------------------------------------------------------------------------------

// define this to read the device id, serial and device type from bootloader section
// #define USE_OTA_BOOTLOADER

//#define DEVICE_CHANNEL_COUNT 3 // used for Device Model HM-RC-Key3-B

#define SIMPLE_CC1101_INIT
#define NORTC
#define NOCRC
#define SENSOR_ONLY
#define NDEBUG

#define EI_ATTINY24
#define EI_NOTPORTB
#define EI_NOTEXTERNAL
#include <EnableInterrupt.h>
#include <LowPower.h>


#include <AskSinPP.h>
#include <MultiChannelDevice.h>
#include <Button.h>
#include <Register.h>
#include "KeypadButton.h"
using namespace as;


#define LED_PIN           A4
#define LED_PIN2          A3
#define CONFIG_BUTTON_PIN A0
#define COL1_PIN          6
#define COL2_PIN          7
#define ROW1_PIN          9
#define ROW2_PIN          8
#define CC1101_PWR_PIN    5

#define NUM_COLS 2
#define NUM_ROWS 2

const uint8_t COL_PINS[2] = {COL1_PIN, COL2_PIN};
const uint8_t ROW_PINS[2] = {ROW1_PIN, ROW2_PIN};

#define PEERS_PER_CHANNEL 10

const struct DeviceInfo PROGMEM devinfo = {
  {0x00, 0x08, 0x02},     // Device ID
  "JPHMRC4001",           // Device Serial
  //{0x00, 0x1e},           // Device Model HM-RC-Key3-B
  {0x00, 0x08},           // Device Model HM-RC-4
  0x01,                   // Firmware Version
  as::DeviceType::Remote, // Device Type
  {0x00, 0x00}            // Info Bytes
};

typedef AvrSPI<10, 11, 12, 13> SPIType;
typedef Radio<SPIType, 2, CC1101_PWR_PIN> RadioType;
typedef DualStatusLed<LED_PIN, LED_PIN2> LedType;
typedef AskSin<LedType, IrqInternalBatt, RadioType> Hal;

DEFREGISTER(RemoteReg1, CREG_LONGPRESSTIME, CREG_AES_ACTIVE, CREG_DOUBLEPRESSTIME)
class RemoteList1 : public RegList1<RemoteReg1> {
  public:
    RemoteList1 (uint16_t addr) : RegList1<RemoteReg1>(addr) {}
    void defaults () {
      clear();
      longPressTime(1);
      // aesActive(false);
      // doublePressTime(0);
    }
};

class KeyPadRemoteChannel : public Channel<Hal, RemoteList1, EmptyList, DefList4, PEERS_PER_CHANNEL, List0>, public KeypadButton {
  private:
    uint8_t       repeatcnt;
  public:

    typedef Channel<Hal, RemoteList1, EmptyList, DefList4, PEERS_PER_CHANNEL, List0> BaseChannel;

    KeyPadRemoteChannel () : BaseChannel(), repeatcnt(0) {}
    virtual ~KeyPadRemoteChannel () {}

    KeypadButton& button () {
      return *(KeypadButton*)this;
    }

    uint8_t status () const {
      return 0;
    }

    uint8_t flags () const {
      return 0;
    }

    virtual void state(uint8_t s) {
      KeypadButton::state(s);
      RemoteEventMsg& msg = (RemoteEventMsg&)this->device().message();
      msg.init(this->device().nextcount(), this->number(), repeatcnt, (s == longreleased || s == longpressed), this->device().battery().low());
      if ( s == released || s == longreleased) {
        repeatcnt++;
      }
      else if (s == longpressed) {
        this->device().broadcastPeerEvent(msg, *this);
      }
    }

    bool configChanged() {
      //we have to add 300ms to the value set in CCU!
      uint16_t _longpressTime = 300 + (this->getList1().longPressTime() * 100);
      //DPRINT("longpressTime = ");DDECLN(_longpressTime);
      setLongPressTime(millis2ticks(_longpressTime));
      return true;
    }
};

typedef MultiChannelDevice<Hal, KeyPadRemoteChannel, 4> RemoteType;

Hal hal;
RemoteType sdev(devinfo, 0x20);
ConfigButton<RemoteType> cfgBtn(sdev);
KeyPad<RemoteType> mKeyPad(sdev);

void setup () {
  sdev.init(hal);

  hal.led.invert(true);
  hal.battery.init();
  hal.battery.low(23);
  hal.battery.critical(21);

  buttonISR(cfgBtn, CONFIG_BUTTON_PIN);
  sdev.initDone();
  KeyPadISR(mKeyPad, COL_PINS, ROW_PINS, NUM_COLS, NUM_ROWS);
}

class PowerOffAlarm : public Alarm {
  private:
    bool    timerActive;
  public:
    PowerOffAlarm () : Alarm(0), timerActive(false) {}
    virtual ~PowerOffAlarm () {}

    void activateTimer(bool en) {
      if (en == true && timerActive == false) {
        sysclock.cancel(*this);
        set(millis2ticks(5000));
        sysclock.add(*this);
      } else if (en == false) {
        sysclock.cancel(*this);
      }
      timerActive = en;
    }

    virtual void trigger(__attribute__((unused)) AlarmClock& clock) {
      powerOff();
    }

    void powerOff() {
      hal.led.ledOff();
      hal.radio.setIdle();
      LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
    }

} pwrOffAlarm;

void loop() {
  bool worked = hal.runready();
  bool poll = sdev.pollRadio();
  pwrOffAlarm.activateTimer( hal.activity.stayAwake() == false &&  worked == false && poll == false );

}
