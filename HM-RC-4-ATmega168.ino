//- -----------------------------------------------------------------------------------------------------------------------
// AskSin++
// 2016-10-31 papa Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
// 2020-09-15 jp112sdl Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
//- -----------------------------------------------------------------------------------------------------------------------

// define this to read the device id, serial and device type from bootloader section
// #define USE_OTA_BOOTLOADER

//#define DEVICE_CHANNEL_COUNT 3 // used for Device Model HM-RC-Key3-B
#define EI_NOTPORTB
#define EI_NOTEXTERNAL
#include <EnableInterrupt.h>
#include <LowPower.h>
#include "AskSinPP.h"

using namespace as;

#include "Sign.h"
#include "MultiChannelDevice.h"
#include "Channel.h"
#include "ChannelList.h"
#include "Message.h"
#include "Register.h"
#include "Button.h"
#include "KeypadButton.h"
#include "Remote.h"

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
typedef Radio<SPIType, 2> RadioType;
typedef DualStatusLed<LED_PIN, LED_PIN2> LedType;
typedef AskSin<LedType, IrqInternalBatt, RadioType> Hal;

typedef RemoteChannel<Hal, PEERS_PER_CHANNEL, List0> ChannelType;
typedef MultiChannelDevice<Hal, ChannelType, 4> RemoteType;

Hal hal;
RemoteType sdev(devinfo, 0x20);
ConfigButton<RemoteType> cfgBtn(sdev);
KeyPad<RemoteType> mKeyPad(sdev);

void setup () {
  pinMode(CC1101_PWR_PIN, OUTPUT);
  digitalWrite(CC1101_PWR_PIN, LOW);

  sdev.init(hal);

  hal.led.invert(true);
  hal.battery.init();
  hal.battery.low(23);
  hal.battery.critical(21);

  buttonISR(cfgBtn, CONFIG_BUTTON_PIN);
  sdev.initDone();
  KeyPadISR(mKeyPad, COL_PINS, ROW_PINS, NUM_COLS, NUM_ROWS);
}

void loop() {
  bool worked = hal.runready();
  bool poll = sdev.pollRadio();
  if ( worked == false && poll == false ) {
    hal.activity.savePower<Hal>(hal);
  }
}
