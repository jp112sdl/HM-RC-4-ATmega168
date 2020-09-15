//- -----------------------------------------------------------------------------------------------------------------------
// AskSin++
// 2017-10-19 papa Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
//- -----------------------------------------------------------------------------------------------------------------------

#ifndef __REGISTER_H__
#define __REGISTER_H__

#include "ChannelList.h"
//#include "cm.h"

namespace as {

// Device Registers used in List0
#define DREG_BURSTRX    0x01
#define DREG_INTKEY     0x02
#define DREG_LEDMODE     0x05
#define DREG_DISPLAY     0x05 //added twice, it's more plausible in sketch
#define DREG_POWERSUPPLY 0x08
#define DREG_CYCLICINFOMSG     0x09
#define DREG_MASTER_ID1 0x0A
#define DREG_MASTER_ID2 0x0B
#define DREG_MASTER_ID3 0x0C
#define DREG_BACKONTIME 0x0e
#define DREG_SABOTAGEMSG     0x10
#define DREG_CYCLICINFOMSGDIS     0x11
#define DREG_LOWBATLIMIT     0x12
#define DREG_TRANSMITTRYMAX     0x14
#define DREG_CONFBUTTONTIME     0x15
#define DREG_LOCALRESETDISABLE 0x18
#define DREG_TPARAMS           0x1b
#define DREG_WAKEUPBEHAVIOUR   0x21
#define DREG_BUTTON_MODE       0x32  // iButton Mode - Remote or State
#define DREG_BUZZER_ENABLED    0x33  // enable Buzzer (used in HB-Devices)

// Channel Registers used in List1
#define CREG_EVENTFILTER 0x01
#define CREG_INTERVAL 0x02
#define CREG_LONGPRESSTIME 0x04
#define CREG_AES_ACTIVE 0x08
#define CREG_DOUBLEPRESSTIME 0x09
#define CREG_REFERENCE_RUNNING_TIME_TOP_BOTTOM_1 0x0b
#define CREG_REFERENCE_RUNNING_TIME_TOP_BOTTOM_2 0x0c
#define CREG_REFERENCE_RUNNING_TIME_BOTTOM_TOP_1 0x0d
#define CREG_REFERENCE_RUNNING_TIME_BOTTOM_TOP_2 0x0e
#define CREG_CHANGE_OVER_DELAY 0x0f
#define CREG_REFERENCE_RUN_COUNTER 0x10
#define CREG_MSGFORPOS  0x20
#define CREG_EVENTDELAYTIME 0x21
#define CREG_LEDONTIME 0x22
#define CREG_EVENTFILTERTIME 0x23
#define CREG_TRANSMITTRYMAX 0x30
#define CREG_LOADAPPEARBEHAVIOUR 0x31
#define CREG_OVERTEMPLEVEL 0x32
#define CREG_REDUCETEMPLEVEL 0x34
#define CREG_REDUCELEVEL 0x35
#define CREG_POWERUPACTION 0x56
#define CREG_STATUSINFO 0x57
#define CREG_CHARACTERISTIC 0x58
#define CREG_LOGICCOMBINATION 0x59
#define CREG_TX_MINDELAY 0x7b
#define CREG_TX_THRESHOLD_PERCENT 0xac
#define CREG_WATER_UPPER_THRESHOLD_CH 0x06
#define CREG_WATER_LOWER_THRESHOLD_CH 0x07
#define CREG_CASE_DESIGN 0x5a
#define CREG_CASE_HIGH_1 0x5e
#define CREG_CASE_HIGH_2 0x5f
#define CREG_FILL_LEVEL_1 0x62
#define CREG_FILL_LEVEL_2 0x63
#define CREG_CASE_WIDTH_1 0x66
#define CREG_CASE_WIDTH_2 0x67
#define CREG_CASE_LENGTH_1 0x6a
#define CREG_CASE_LENGTH_2 0x6b
#define CREG_MEASURE_LENGTH_1 0x6c
#define CREG_MEASURE_LENGTH_2 0x6d
#define CREG_USE_CUSTOM_CALIBRATION 0x6e
//POWER_METER REGS
#define CREG_AVERAGING              0x7a
#define CREG_TX_THRESHOLD_POWER_1   0x7c
#define CREG_TX_THRESHOLD_POWER_2   0x7d
#define CREG_TX_THRESHOLD_POWER_3   0x7e
#define CREG_TX_THRESHOLD_CURRENT_1 0x7f
#define CREG_TX_THRESHOLD_CURRENT_2 0x80
#define CREG_TX_THRESHOLD_VOLTAGE_1 0x81
#define CREG_TX_THRESHOLD_VOLTAGE_2 0x82
#define CREG_TX_THRESHOLD_FREQUENCY 0x83
#define CREG_COND_TX                0x84
#define CREG_COND_TX_DECISION_ABOVE 0x85
#define CREG_COND_TX_DECISION_BELOW 0x86
#define CREG_COND_TX_THRESHOLD_HI_1 0x87 
#define CREG_COND_TX_THRESHOLD_HI_2 0x88
#define CREG_COND_TX_THRESHOLD_HI_3 0x89 
#define CREG_COND_TX_THRESHOLD_HI_4 0x8a 
#define CREG_COND_TX_THRESHOLD_LO_1 0x8b
#define CREG_COND_TX_THRESHOLD_LO_2 0x8c
#define CREG_COND_TX_THRESHOLD_LO_3 0x8d
#define CREG_COND_TX_THRESHOLD_LO_4 0x8e

#define CREG_DATA_TRANSMISSION_CONDITION 0xb0
#define CREG_DATA_STABILITY_FILTER_TIME 0xb1
#define CREG_DATA_INPUT_PROPERTIES 0xb2
#define CREG_CHANNEL_FUNCTION 0x92

// Peer Registers used in List3
#define PREG_CTRAMPONOFF 0x01
#define PREG_CTDELAYONOFF 0x02
#define PREG_CTONOFF 0x03
#define PREG_CONDVALUELOW 0x04
#define PREG_CONDVALUEHIGH 0x05
#define PREG_ONDELAYTIME 0x06
#define PREG_ONTIME 0x07
#define PREG_OFFDELAYTIME 0x08
#define PREG_OFFTIME 0x09
#define PREG_ACTIONTYPE 0x0A
#define PREG_JTONOFF 0x0B
#define PREG_JTDELAYONOFF 0x0C
#define PREG_JTRAMPONOFF 0x0D
#define PREG_DELAYMODE 0x0E
#define PREG_OFFLEVEL 0x0F
#define PREG_ONMINLEVEL 0x10
#define PREG_ONLEVEL 0x11
#define PREG_RAMPSTARTSTEP 0x12
#define PREG_RAMPONTIME 0x13
#define PREG_RAMPOFFTIME 0x14
#define PREG_DIMMINLEVEL 0x15
#define PREG_DIMMAXLEVEL 0x16
#define PREG_DIMSTEP 0x17
#define PREG_OFFDELAYSTEP 0x18
#define PREG_OFFDELAYNEWTIME 0x19
#define PREG_OFFDELAYOLDTIME 0x1A
#define PREG_CTREPONOFF 0x1C
#define PREG_MAXTIMEFIRSTDIR 0x1D
#define PREG_JTREFONOFF 0x1E
#define PREG_DRIVINGMODE 0x1F
#define PREG_ELSEACTIONTYPE 0x26
#define PREG_ELSEJTONOFF 0x27
#define PREG_ELSEJTDELAYONOFF 0x28
#define PREG_ELSEJTRAMPONOFF 0x29
#define PREG_ACTTYPE 0x24
#define PREG_ACTNUM 0x25
#define PREG_ACTINTENS 0x2B

// Peer Registers used in List4
#define PREG_BURST_AES 0x01

// some shortcuts
#define MASTERID_REGS DREG_MASTER_ID1,DREG_MASTER_ID2,DREG_MASTER_ID3

#define CREG_REFERENCE_RUNNING_TIME_TOP_BOTTOM CREG_REFERENCE_RUNNING_TIME_TOP_BOTTOM_1,CREG_REFERENCE_RUNNING_TIME_TOP_BOTTOM_2
#define CREG_REFERENCE_RUNNING_TIME_BOTTOM_TOP CREG_REFERENCE_RUNNING_TIME_BOTTOM_TOP_1,CREG_REFERENCE_RUNNING_TIME_BOTTOM_TOP_2
#define CREG_CASE_HIGH CREG_CASE_HIGH_1,CREG_CASE_HIGH_2
#define CREG_FILL_LEVEL CREG_FILL_LEVEL_1,CREG_FILL_LEVEL_2
#define CREG_CASE_WIDTH CREG_CASE_WIDTH_1,CREG_CASE_WIDTH_2
#define CREG_CASE_LENGTH CREG_CASE_LENGTH_1,CREG_CASE_LENGTH_2
#define CREG_MEASURE_LENGTH CREG_MEASURE_LENGTH_1,CREG_MEASURE_LENGTH_2
#define CREG_TX_THRESHOLD_POWER CREG_TX_THRESHOLD_POWER_1,CREG_TX_THRESHOLD_POWER_2,CREG_TX_THRESHOLD_POWER_3
#define CREG_TX_THRESHOLD_CURRENT CREG_TX_THRESHOLD_CURRENT_1,CREG_TX_THRESHOLD_CURRENT_2
#define CREG_TX_THRESHOLD_VOLTAGE CREG_TX_THRESHOLD_VOLTAGE_1,CREG_TX_THRESHOLD_VOLTAGE_2
#define CREG_COND_TX_THRESHOLD_HI CREG_COND_TX_THRESHOLD_HI_1,CREG_COND_TX_THRESHOLD_HI_2,CREG_COND_TX_THRESHOLD_HI_3,CREG_COND_TX_THRESHOLD_HI_4
#define CREG_COND_TX_THRESHOLD_LO CREG_COND_TX_THRESHOLD_LO_1,CREG_COND_TX_THRESHOLD_LO_2,CREG_COND_TX_THRESHOLD_LO_3,CREG_COND_TX_THRESHOLD_LO_4

// This is only a helper class
class AskSinRegister {
public:
  static uint8_t getOffset(uint8_t reg,const uint8_t* reglist,uint8_t size) {
    for(uint8_t idx=0; idx<size; ++idx) {
    if(pgm_read_byte(reglist + idx) == reg) {
      return idx;
    }
  }
  return 0xff;
  }
  static uint8_t getRegister(uint8_t offset,const uint8_t* reglist,uint8_t size) {
    if (offset < size) {
      return pgm_read_byte(reglist + offset);
    }
    return 0xff;
  }
};

// This is a generic list using a Register class
template<class RegisterType>
class RegisterList : public BaseList {
public:
  static uint8_t getOffset (uint8_t reg) { return RegisterType::getOffset(reg); }
  static uint8_t getRegister (uint8_t offset) { return RegisterType::getRegister(offset); }
  static uint8_t size () { return RegisterType::getSize(); }

  operator GenericList () const {
    return GenericList(address(),size(),getRegister,getOffset);
  }

  RegisterList (uint16_t a) : BaseList(a) {}

  bool writeRegister (uint8_t reg, uint8_t value) const {
    uint8_t offset = RegisterType::getOffset(reg);
    if( offset != 0xff ) {
      return setByte(offset,value);
    }
    return false;
  }
  bool writeRegister (uint8_t reg, uint8_t mask,uint8_t shift,uint8_t value) const {
    uint8_t offset = RegisterType::getOffset(reg);
    if( offset != 0xff ) {
      return setByte(offset,value,mask<<shift,shift);
    }
    return false;
  }
  bool writeBit (uint8_t reg,uint8_t bitnum,bool value) const {
    uint8_t offset = RegisterType::getOffset(reg);
    if( offset != 0xff ) {
      return setBit(offset,0x01<<bitnum,value);
    }
    return false;
  }

  uint8_t readRegister (uint8_t reg,uint8_t value=0) const {
    uint8_t offset = RegisterType::getOffset(reg);
    if( offset != 0xff ) {
      value = getByte(offset);
    }
    return value;
  }
  uint8_t readRegister (uint8_t reg,uint8_t mask,uint8_t shift,uint8_t value=0) const {
    uint8_t offset = RegisterType::getOffset(reg);
    if( offset != 0xff ) {
      value = getByte(offset,mask<<shift,shift);
    }
    return value;
  }
  bool readBit (uint8_t reg,uint8_t bitnum,bool value=false) const {
    uint8_t offset = RegisterType::getOffset(reg);
    if( offset != 0xff ) {
      value = isBitSet(offset,0x01<<bitnum);
    }
    return value;
  }

  void clear () {
    BaseList::clear(0,RegisterType::getSize());
  }

  void defaults () {
    clear();
  }

};


/*
const uint8_t SimpleRegisterRegister[4] PROGMEM = {0x01,0x02,0x55,0x56};
class SimpleRegister {
public:
  static uint8_t getOffset(uint8_t reg) { return AskSinRegister::getOffset(reg,SimpleRegisterRegister,getSize()); }
  static uint8_t getRegister(uint8_t offset) { return AskSinRegister::getRegister(offset,SimpleRegisterRegister,getSize()); }
  static uint8_t getSize () { return sizeof(SimpleRegisterRegister); }
};
*/

/*
class ShortLongRegister {
public:
  static uint8_t Register[4];
  static uint8_t getOffset(uint8_t reg) {
    if( reg & 0x80 ) {
    return sizeof(Register) + getOffset(reg & ~0x80);
  }
    return AskSinRegister::getOffset(reg,Register,sizeof(Register));
  }
  static uint8_t getRegister(uint8_t offset) {
    if( offset >= sizeof(Register) ) {
    return getRegister( offset - sizeof(Register) ) | 0x80;
  }
    return AskSinRegister::getRegister(offset,Register,sizeof(Register));
  }
  static uint8_t getSize () { return 2*sizeof(Register); }
};
uint8_t ShortLongRegister::Register[] = {DREG_INTKEY,LIST0_REGS};
*/

#define NUMARGS(...)  (sizeof((int[]){__VA_ARGS__})/sizeof(int))

#define DEFREGISTER(rgname,...) const uint8_t __##rgname##Register__[NUMARGS(__VA_ARGS__)] PROGMEM = {__VA_ARGS__}; \
  class rgname { public: \
  static uint8_t getOffset(uint8_t reg) { return AskSinRegister::getOffset(reg,__##rgname##Register__,sizeof(__##rgname##Register__)); } \
  static uint8_t getRegister(uint8_t offset) { return AskSinRegister::getRegister(offset,__##rgname##Register__,sizeof(__##rgname##Register__)); } \
  static uint8_t getSize () { return sizeof(__##rgname##Register__); } \
};

/*
#define DEFREGISTER2(rgname,...) const uint8_t __##rgname##Register__[NUMARGS(__VA_ARGS__)] PROGMEM = {__VA_ARGS__}; \
  class rgname { public: \
  static uint8_t getOffset(uint8_t reg) { \
    if( reg & 0x80 ) { \
    return sizeof(__##rgname##Register__) + getOffset(reg & ~0x80); \
  } \
    return AskSinRegister::getOffset(reg,__##rgname##Register__,sizeof(__##rgname##Register__)); \
  } \
  static uint8_t getRegister(uint8_t offset) { \
    if( offset >= sizeof(__##rgname##Register__) ) { \
    return getRegister( offset - sizeof(__##rgname##Register__) ) | 0x80; \
  } \
    return AskSinRegister::getRegister(offset,__##rgname##Register__,sizeof(__##rgname##Register__));  \
  } \
  static uint8_t getSize () { return 2*sizeof(__##rgname##Register__); } \
};
*/

template <class Register>
class RegList0 : public RegisterList<Register> {
public:
  RegList0(uint16_t a) : RegisterList<Register>(a) {}

  bool burstRx (bool v) const { return this->writeRegister(DREG_BURSTRX,v); }
  bool burstRx () const { return this->readRegister(DREG_BURSTRX,false); }
  bool intKeyVisible (bool v) const { return this->writeBit(DREG_INTKEY,7,v); }
  bool intKeyVisible () const { return this->readBit(DREG_INTKEY,7,false); }

  HMID masterid () const { return HMID(
    this->readRegister(DREG_MASTER_ID1),
    this->readRegister(DREG_MASTER_ID2),
    this->readRegister(DREG_MASTER_ID3));
  }
  void masterid (const HMID& mid) const {
    this->writeRegister(DREG_MASTER_ID1,mid.id0());
    this->writeRegister(DREG_MASTER_ID2,mid.id1());
    this->writeRegister(DREG_MASTER_ID3,mid.id2());
  };

  uint8_t powerSupply () const { return this->readRegister(DREG_POWERSUPPLY,0); }
  bool powerSupply (uint8_t value) const { return this->writeRegister(DREG_POWERSUPPLY,value); }
  
  bool wakeupBehaviourStatusSignalizationConfirmation(bool v) const { return this->writeRegister(DREG_WAKEUPBEHAVIOUR,0x01,0,v); }
  bool wakeupBehaviourStatusSignalizationConfirmation() const { return this->readRegister(DREG_WAKEUPBEHAVIOUR, 0x01,0,false); }
  bool wakeupBehaviourStatusMsgConfirmation(bool v) const { return this->writeRegister(DREG_WAKEUPBEHAVIOUR,0x01,1,v); }
  bool wakeupBehaviourStatusMsgConfirmation() const { return this->readRegister(DREG_WAKEUPBEHAVIOUR, 0x01,1,false); }
  bool wakeupBehaviourStatusMsgResistance(bool v) const { return this->writeRegister(DREG_WAKEUPBEHAVIOUR,0x01,2,v); }
  bool wakeupBehaviourStatusMsgResistance() const { return this->readRegister(DREG_WAKEUPBEHAVIOUR, 0x01,2,false); }
  
  bool displayInverting(bool v) const { return this->writeRegister(DREG_DISPLAY,0x01,6,v); }
  bool displayInverting() const { return this->readRegister(DREG_DISPLAY, 0x01,6,false); }
  bool statusMessageTextAlignmentLeftAligned(bool v) const { return this->writeRegister(DREG_DISPLAY,0x01,7,v); }
  bool statusMessageTextAlignmentLeftAligned() const { return this->readRegister(DREG_DISPLAY, 0x01,7,false); }
  
  uint8_t ledMode () const { return this->readRegister(DREG_LEDMODE,0x03,6,1); }
  bool ledMode (uint8_t value) const { return this->writeRegister(DREG_LEDMODE,0x03,6,value); }
  bool cycleInfoMsg () const { return this->readRegister(DREG_CYCLICINFOMSG,false); }
  bool cycleInfoMsg (bool value) const { return this->writeRegister(DREG_CYCLICINFOMSG,value); }
  uint8_t transmitDevTryMax () const { uint8_t v = this->readRegister(DREG_TRANSMITTRYMAX,6); return v == 0 ? 1 : v; }
  bool transmitDevTryMax (uint8_t value) const { return this->writeRegister(DREG_TRANSMITTRYMAX,value); }
  bool sabotageMsg () const { return this->readRegister(DREG_SABOTAGEMSG,true); }
  bool sabotageMsg (bool value) const { return this->writeRegister(DREG_SABOTAGEMSG,value); }
  uint8_t cyclicInfoMsgDis () const { return this->readRegister(DREG_CYCLICINFOMSGDIS,0); }
  bool cyclicInfoMsgDis (uint8_t value) const { return this->writeRegister(DREG_CYCLICINFOMSGDIS,value); }
  uint8_t lowBatLimit () const { return this->readRegister(DREG_LOWBATLIMIT,0); }
  bool lowBatLimit (uint8_t value) const { return this->writeRegister(DREG_LOWBATLIMIT,value); }
  uint8_t tParamSelect () const { return this->readRegister(DREG_TPARAMS,3); }
  bool tParamSelect (uint8_t value) const { return this->writeRegister(DREG_TPARAMS,value); }
    
  uint8_t confButtonTime () const { return this->readRegister(DREG_CONFBUTTONTIME,0); }
  bool confButtonTime (uint8_t value) const { return this->writeRegister(DREG_CONFBUTTONTIME,value); }
  bool localResetDisable (bool v) const { return this->writeBit(DREG_LOCALRESETDISABLE,0,v); }
  bool localResetDisable () const { return this->readBit(DREG_LOCALRESETDISABLE,0,false); }

  uint8_t backOnTime () const { return this->readRegister(DREG_BACKONTIME,3); }
  bool backOnTime (uint8_t value) const { return this->writeRegister(DREG_BACKONTIME,value); }

  uint8_t buttonMode () const { return this->readRegister(DREG_BUTTON_MODE,0); }
  bool buttonMode (uint8_t value) const { return this->writeRegister(DREG_BUTTON_MODE,value); }

  bool buzzerEnabled (bool v) const { return this->writeBit(DREG_BUZZER_ENABLED,0,v); }
  bool buzzerEnabled () const { return this->readBit(DREG_BUZZER_ENABLED,0,false); }
};

template <class Register>
class RegList2 : public RegisterList<Register> {
public:
  RegList2 (uint16_t addr) : RegisterList<Register>(addr) {}

  bool    ADDRESS_SENDER_HIGH_BYTE(uint8_t index,uint8_t value) const { return this->writeRegister(1+(index*7), value); }
  uint8_t ADDRESS_SENDER_HIGH_BYTE(uint8_t index)               const { return this->readRegister (1+(index*7), 0); }
  bool    ADDRESS_SENDER_MID_BYTE (uint8_t index,uint8_t value) const { return this->writeRegister(2+(index*7), value); }
  uint8_t ADDRESS_SENDER_MID_BYTE (uint8_t index)               const { return this->readRegister (2+(index*7), 0); }
  bool    ADDRESS_SENDER_LOW_BYTE (uint8_t index,uint8_t value) const { return this->writeRegister(3+(index*7), value); }
  uint8_t ADDRESS_SENDER_LOW_BYTE (uint8_t index)               const { return this->readRegister (3+(index*7), 0); }

  bool    ADDRESS_RECEIVER_HIGH_BYTE(uint8_t index,uint8_t value) const { return this->writeRegister(4+(index*7), value); }
  uint8_t ADDRESS_RECEIVER_HIGH_BYTE(uint8_t index)               const { return this->readRegister (4+(index*7), 0); }
  bool    ADDRESS_RECEIVER_MID_BYTE (uint8_t index,uint8_t value) const { return this->writeRegister(5+(index*7), value); }
  uint8_t ADDRESS_RECEIVER_MID_BYTE (uint8_t index)               const { return this->readRegister (5+(index*7), 0); }
  bool    ADDRESS_RECEIVER_LOW_BYTE (uint8_t index,uint8_t value) const { return this->writeRegister(6+(index*7), value); }
  uint8_t ADDRESS_RECEIVER_LOW_BYTE (uint8_t index)               const { return this->readRegister (6+(index*7), 0); }

  bool    BROADCAST_BEHAVIOR (uint8_t index,uint8_t value) const { return this->writeRegister(7+(index*7), value); }
  uint8_t BROADCAST_BEHAVIOR (uint8_t index)               const { return this->readRegister (7+(index*7), 0); }
};


template <class Register>
class RegList1 : public RegisterList<Register> {
public:
  RegList1(uint16_t a) : RegisterList<Register>(a) {}

  bool msgForPosC(uint8_t v) const { return this->writeRegister(CREG_MSGFORPOS,0x03,2,v); }
  uint8_t msgForPosC() const { return this->readRegister(CREG_MSGFORPOS,0x03,2,0); }
  bool msgForPosB(uint8_t v) const { return this->writeRegister(CREG_MSGFORPOS,0x03,4,v); }
  uint8_t msgForPosB() const { return this->readRegister(CREG_MSGFORPOS,0x03,4,0); }
  bool msgForPosA(uint8_t v) const { return this->writeRegister(CREG_MSGFORPOS,0x03,6,v); }
  uint8_t msgForPosA() const { return this->readRegister(CREG_MSGFORPOS,0x03,6,0); }

  bool eventDelaytime(uint8_t v) const { return this->writeRegister(CREG_EVENTDELAYTIME,v); }
  uint8_t eventDelaytime() const { return this->readRegister(CREG_EVENTDELAYTIME,0); }
  bool ledOntime(uint8_t v) const { return this->writeRegister(CREG_LEDONTIME,v); }
  uint8_t ledOntime() const { return this->readRegister(CREG_LEDONTIME,100); }
  bool eventFilterTime(uint8_t v) const { return this->writeRegister(CREG_EVENTFILTERTIME,v); }
  uint8_t eventFilterTime() const { return this->readRegister(CREG_EVENTFILTERTIME,5); }
  bool transmitTryMax(uint8_t v) const { return this->writeRegister(CREG_TRANSMITTRYMAX,v); }
  uint8_t transmitTryMax() const { uint8_t v = this->readRegister(CREG_TRANSMITTRYMAX,6); return v == 0 ? 1 : v;}
  bool loadAppearBehaviour(uint8_t v) const { return this->writeRegister(CREG_LOADAPPEARBEHAVIOUR,v); }
  uint8_t loadAppearBehaviour() const { uint8_t v = this->readRegister(CREG_LOADAPPEARBEHAVIOUR,0); return v > 3 ? 3 : v;}

  uint8_t longPressTime () const { return this->readRegister(CREG_LONGPRESSTIME,0x0f,4,1); }
  bool longPressTime (uint8_t v) const { return this->writeRegister(CREG_LONGPRESSTIME,0x0f,4,v); }
  uint8_t doublePressTime () const { return this->readRegister(CREG_DOUBLEPRESSTIME,0x0f,0,0); }
  bool doublePressTime (uint8_t v) const { return this->writeRegister(CREG_DOUBLEPRESSTIME,0x0f,0,v); }

  bool refRunningTimeTopBottom (uint16_t value) const {
    return this->writeRegister(CREG_REFERENCE_RUNNING_TIME_TOP_BOTTOM_1, (value >> 8) & 0xff) &&
        this->writeRegister(CREG_REFERENCE_RUNNING_TIME_TOP_BOTTOM_2, value & 0xff);
  }
  uint16_t refRunningTimeTopBottom () const {
    return (this->readRegister(CREG_REFERENCE_RUNNING_TIME_TOP_BOTTOM_1,0) << 8) +
        this->readRegister(CREG_REFERENCE_RUNNING_TIME_TOP_BOTTOM_2,0);
  }
  bool refRunningTimeBottomTop (uint16_t value) const {
    return this->writeRegister(CREG_REFERENCE_RUNNING_TIME_BOTTOM_TOP_1, (value >> 8) & 0xff) &&
        this->writeRegister(CREG_REFERENCE_RUNNING_TIME_BOTTOM_TOP_2, value & 0xff);
  }
  uint16_t refRunningTimeBottomTop () const {
    return (this->readRegister(CREG_REFERENCE_RUNNING_TIME_BOTTOM_TOP_1,0) << 8) +
        this->readRegister(CREG_REFERENCE_RUNNING_TIME_BOTTOM_TOP_2,0);
  }
  bool changeOverDelay(uint8_t v) const { return this->writeRegister(CREG_CHANGE_OVER_DELAY,v); }
  uint8_t changeOverDelay() const { return this->readRegister(CREG_CHANGE_OVER_DELAY,0); }
  bool refRunCounter(uint8_t v) const { return this->writeRegister(CREG_REFERENCE_RUN_COUNTER,v); }
  uint8_t refRunCounter() const { return this->readRegister(CREG_REFERENCE_RUN_COUNTER,0); }

  uint8_t eventFilterPeriod () const { return this->readRegister(CREG_EVENTFILTER,0x0f,0,1); }
  bool eventFilterPeriod (uint8_t v) const { return this->writeRegister(CREG_EVENTFILTER,0x0f,0,v); }
  uint8_t eventFilterNumber () const { return this->readRegister(CREG_EVENTFILTER,0x0f,4,1); }
  bool eventFilterNumber (uint8_t v) const { return this->writeRegister(CREG_EVENTFILTER,0x0f,4,v); }

  uint8_t minInterval () const { return this->readRegister(CREG_INTERVAL,0x07,0,4); }
  bool minInterval (uint8_t v) const { return this->writeRegister(CREG_INTERVAL,0x07,0,v); }
  bool captureWithinInterval () const { return this->readBit(CREG_INTERVAL,3,false); }
  bool captureWithinInterval (bool v) const { return this->writeBit(CREG_INTERVAL,3,v); }
  uint8_t brightnessFilter () const { return this->readRegister(CREG_INTERVAL,0x0f,4,7); }
  bool brightnessFilter (uint8_t v) const { return this->writeRegister(CREG_INTERVAL,0x0f,4,v); }

  bool powerUpAction () const { return this->readBit(CREG_POWERUPACTION,0,false); }
  bool powerUpAction (bool v) const { return this->writeBit(CREG_POWERUPACTION,0,v); }

  uint8_t statusInfoMinDly () const { return this->readRegister(CREG_STATUSINFO,0x1f,0,4); }
  bool statusInfoMinDly (uint8_t v) { return this->writeRegister(CREG_STATUSINFO,0x1f,0,v); }
  uint8_t statusInfoRandom () const { return this->readRegister(CREG_STATUSINFO,0x07,5,1); }
  bool statusInfoRandom (uint8_t v) { return this->writeRegister(CREG_STATUSINFO,0x07,5,v); }

  uint8_t overTempLevel () const { return this->readRegister(CREG_OVERTEMPLEVEL,80); }
  bool overTempLevel (uint8_t v) const { return this->writeRegister(CREG_OVERTEMPLEVEL,v); }
  uint8_t reduceTempLevel () const { return this->readRegister(CREG_REDUCETEMPLEVEL,75); }
  bool reduceTempLevel (uint8_t v) const { return this->writeRegister(CREG_REDUCETEMPLEVEL,v); }
  uint8_t reduceLevel () const { return this->readRegister(CREG_REDUCELEVEL,80); }
  bool reduceLevel (uint8_t v) const { return this->writeRegister(CREG_REDUCELEVEL,v); }

  bool characteristic () const { return this->readBit(CREG_CHARACTERISTIC,0,true); }
  bool characteristic (bool v) const { return this->writeBit(CREG_CHARACTERISTIC,0,v); }
  uint8_t logicCombination () const { return this->readRegister(CREG_LOGICCOMBINATION,0x1f,0,1); }
  bool logicCombination (uint8_t v) { return this->writeRegister(CREG_LOGICCOMBINATION,0x1f,0,v); }

  uint8_t txMindelay () const { return this->readRegister(CREG_TX_MINDELAY,0x7f,0,8); }
  bool txMindelay (uint8_t v) { return this->writeRegister(CREG_TX_MINDELAY,0x7f,0,v); }
  uint8_t txThresholdPercent () const { return this->readRegister(CREG_TX_THRESHOLD_PERCENT,0); }
  bool txThresholdPercent (uint8_t v) const { return this->writeRegister(CREG_TX_THRESHOLD_PERCENT,v); }
  uint8_t waterUpperThreshold () const { return this->readRegister(CREG_WATER_UPPER_THRESHOLD_CH,0xff); }
  bool waterUpperThreshold (uint8_t v) const { return this->writeRegister(CREG_WATER_UPPER_THRESHOLD_CH,v); }
  
  uint8_t waterLowerThreshold () const { return this->readRegister(CREG_WATER_LOWER_THRESHOLD_CH,0xff); }
  bool waterLowerThreshold (uint8_t v) const { return this->writeRegister(CREG_WATER_LOWER_THRESHOLD_CH,v); }
  
  uint8_t caseDesign () const { return this->readRegister(CREG_CASE_DESIGN,0); }
  bool caseDesign (uint8_t v) const { return this->writeRegister(CREG_CASE_DESIGN,v); }
  
  bool caseHigh (uint16_t value) const {
   return this->writeRegister(CREG_CASE_HIGH_1, (value >> 8) & 0xff) &&
     this->writeRegister(CREG_CASE_HIGH_2, value & 0xff);
  }
  uint16_t caseHigh () const {
   return (this->readRegister(CREG_CASE_HIGH_1,0) << 8) +
     this->readRegister(CREG_CASE_HIGH_2,0);
  }

  bool caseWidth (uint16_t value) const {
   return this->writeRegister(CREG_CASE_WIDTH_1, (value >> 8) & 0xff) &&
     this->writeRegister(CREG_CASE_WIDTH_2, value & 0xff);
  }
  uint16_t caseWidth () const {
   return (this->readRegister(CREG_CASE_WIDTH_1,0) << 8) +
     this->readRegister(CREG_CASE_WIDTH_2,0);
  }
 
  bool caseLength (uint16_t value) const {
   return this->writeRegister(CREG_CASE_LENGTH_1, (value >> 8) & 0xff) &&
     this->writeRegister(CREG_CASE_LENGTH_2, value & 0xff);
  }
  uint16_t caseLength () const {
   return (this->readRegister(CREG_CASE_LENGTH_1,0) << 8) +
     this->readRegister(CREG_CASE_LENGTH_2,0);
  }
  
  bool measureLength (uint16_t value) const {
   return this->writeRegister(CREG_MEASURE_LENGTH_1, (value >> 8) & 0xff) &&
     this->writeRegister(CREG_MEASURE_LENGTH_2, value & 0xff);
  }
  uint16_t measureLength () const {
   return (this->readRegister(CREG_MEASURE_LENGTH_1,0) << 8) +
     this->readRegister(CREG_MEASURE_LENGTH_2,0);
  }
 
  bool fillLevel (uint16_t value) const {
   return this->writeRegister(CREG_FILL_LEVEL_1, (value >> 8) & 0xff) &&
     this->writeRegister(CREG_FILL_LEVEL_2, value & 0xff);
  }
  uint16_t fillLevel () const {
   return (this->readRegister(CREG_FILL_LEVEL_1,0) << 8) +
     this->readRegister(CREG_FILL_LEVEL_2,0);
  }
 
  bool useCustomCalibration () const { return this->readBit(CREG_USE_CUSTOM_CALIBRATION,0,true); }
  bool useCustomCalibration (bool v) const { return this->writeBit(CREG_USE_CUSTOM_CALIBRATION,0,v); }
  
  uint8_t averaging () const { return this->readRegister(CREG_AVERAGING,0); }
  bool averaging (uint8_t v) const { return this->writeRegister(CREG_AVERAGING,v); }

  bool txThresholdPower (uint32_t value) const {
   return
     this->writeRegister(CREG_TX_THRESHOLD_POWER_1, (value >> 16) & 0xff) &&
     this->writeRegister(CREG_TX_THRESHOLD_POWER_2, (value >>  8) & 0xff) &&
     this->writeRegister(CREG_TX_THRESHOLD_POWER_3, (value      ) & 0xff);
  }
  uint32_t txThresholdPower () const {
   return
     ((uint32_t)this->readRegister(CREG_TX_THRESHOLD_POWER_1,0) << 16) |
     ((uint32_t)this->readRegister(CREG_TX_THRESHOLD_POWER_2,0) <<  8) |
     ((uint32_t)this->readRegister(CREG_TX_THRESHOLD_POWER_3,0)      );
  }
  
  bool txThresholdCurrent (uint16_t value) const {
   return
     this->writeRegister(CREG_TX_THRESHOLD_CURRENT_1, (value >> 8) & 0xff) &&
     this->writeRegister(CREG_TX_THRESHOLD_CURRENT_2, (value     ) & 0xff);
  }
  uint16_t txThresholdCurrent () const {
   return
    (this->readRegister(CREG_TX_THRESHOLD_CURRENT_1,0) << 8) |
    (this->readRegister(CREG_TX_THRESHOLD_CURRENT_2,0)     );
  }
  
 bool txThresholdVoltage (uint16_t value) const {
   return
     this->writeRegister(CREG_TX_THRESHOLD_VOLTAGE_1, (value >> 8) & 0xff) &&
     this->writeRegister(CREG_TX_THRESHOLD_VOLTAGE_2, (value     ) & 0xff);
  }
  uint16_t txThresholdVoltage () const {
   return
     (this->readRegister(CREG_TX_THRESHOLD_VOLTAGE_1,0) << 8) |
     (this->readRegister(CREG_TX_THRESHOLD_VOLTAGE_2,0)     );
  }
  
  uint8_t txThresholdFrequency () const { return this->readRegister(CREG_TX_THRESHOLD_FREQUENCY,0); }
  bool txThresholdFrequency (uint8_t v) const { return this->writeRegister(CREG_TX_THRESHOLD_FREQUENCY,v); }

  uint8_t condTxDecisionAbove () const { return this->readRegister(CREG_COND_TX_DECISION_ABOVE,0xff); }
  bool condTxDecisionAbove (uint8_t v) const { return this->writeRegister(CREG_COND_TX_DECISION_ABOVE,v); }
  
  uint8_t condTxDecisionBelow () const { return this->readRegister(CREG_COND_TX_DECISION_BELOW,0xff); }
  bool condTxDecisionBelow (uint8_t v) const { return this->writeRegister(CREG_COND_TX_DECISION_BELOW,v); }
    
  bool condTxFalling () const { return this->readRegister(CREG_COND_TX,0x01,0,false); }
  bool condTxFalling (uint8_t v) { return this->writeRegister(CREG_COND_TX,0x01,0,v); }
  
  bool condTxRising () const { return this->readRegister(CREG_COND_TX,0x02,0,false); }
  bool condTxRising (uint8_t v) { return this->writeRegister(CREG_COND_TX,0x02,0,v); }
  
  bool condTxCyclicBelow () const { return this->readRegister(CREG_COND_TX,0x04,0,false); }
  bool condTxCyclicBelow (uint8_t v) { return this->writeRegister(CREG_COND_TX,0x04,0,v); }
  
  bool condTxCyclicAbove () const { return this->readRegister(CREG_COND_TX,0x08,0,false); }
  bool condTxCyclicAbove (uint8_t v) { return this->writeRegister(CREG_COND_TX,0x08,0,v); }  
    
  bool condTxThresholdHi (uint32_t value) const {
   return 
     this->writeRegister(CREG_COND_TX_THRESHOLD_HI_1, (value >> 24) & 0xff) &&
     this->writeRegister(CREG_COND_TX_THRESHOLD_HI_2, (value >> 16) & 0xff) &&
     this->writeRegister(CREG_COND_TX_THRESHOLD_HI_3, (value >>  8) & 0xff) &&
     this->writeRegister(CREG_COND_TX_THRESHOLD_HI_4, (value      ) & 0xff);
  }
  uint32_t condTxThresholdHi () const {
   return
     ((uint32_t)this->readRegister(CREG_COND_TX_THRESHOLD_HI_1,0) << 24) | 
     ((uint32_t)this->readRegister(CREG_COND_TX_THRESHOLD_HI_2,0) << 16) |
     ((uint32_t)this->readRegister(CREG_COND_TX_THRESHOLD_HI_3,0) <<  8) | 
     ((uint32_t)this->readRegister(CREG_COND_TX_THRESHOLD_HI_4,0)      );
  }
  
  bool condTxThresholdLo (uint32_t value) const {
   return 
     this->writeRegister(CREG_COND_TX_THRESHOLD_LO_1, (value >> 24) & 0xff) &&
     this->writeRegister(CREG_COND_TX_THRESHOLD_LO_2, (value >> 16) & 0xff) &&
     this->writeRegister(CREG_COND_TX_THRESHOLD_LO_3, (value >>  8) & 0xff) &&
     this->writeRegister(CREG_COND_TX_THRESHOLD_LO_4, (value      ) & 0xff);
  }
  uint32_t condTxThresholdLo () const {
   return 
     ((uint32_t)this->readRegister(CREG_COND_TX_THRESHOLD_LO_1,0) << 24) |
     ((uint32_t)this->readRegister(CREG_COND_TX_THRESHOLD_LO_2,0) << 16) |
     ((uint32_t)this->readRegister(CREG_COND_TX_THRESHOLD_LO_3,0) <<  8) |
     ((uint32_t)this->readRegister(CREG_COND_TX_THRESHOLD_LO_4,0)      );
  }
    
  uint8_t dataTransmissionCondtion() const { return this->readRegister(CREG_DATA_TRANSMISSION_CONDITION,0); }
  bool dataTransmissionCondtion(uint8_t v) const { return this->writeRegister(CREG_DATA_TRANSMISSION_CONDITION,v); }
  
  uint8_t dataStabilityFilterTime () const { return this->readRegister(CREG_DATA_STABILITY_FILTER_TIME,0); }
  bool dataStabilityFilterTime (uint8_t v) const { return this->writeRegister(CREG_DATA_STABILITY_FILTER_TIME,v); }
      
  bool dataInputPropertieIn0 () const { return this->readRegister(CREG_DATA_INPUT_PROPERTIES,0x01,0,false); }
  bool dataInputPropertieIn0 (uint8_t v) { return this->writeRegister(CREG_DATA_INPUT_PROPERTIES,0x01,0,v); }
  
  bool dataInputPropertieIn1 () const { return this->readRegister(CREG_DATA_INPUT_PROPERTIES,0x02,0,false); }
  bool dataInputPropertieIn1 (uint8_t v) { return this->writeRegister(CREG_DATA_INPUT_PROPERTIES,0x02,0,v); }
  
  bool dataInputPropertieIn2 () const { return this->readRegister(CREG_DATA_INPUT_PROPERTIES,0x04,0,false); }
  bool dataInputPropertieIn2 (uint8_t v) { return this->writeRegister(CREG_DATA_INPUT_PROPERTIES,0x04,0,v); }
  
  bool dataInputPropertieIn3 () const { return this->readRegister(CREG_DATA_INPUT_PROPERTIES,0x08,0,false); }
  bool dataInputPropertieIn3 (uint8_t v) { return this->writeRegister(CREG_DATA_INPUT_PROPERTIES,0x08,0,v); }
  
  bool dataInputPropertieIn4 () const { return this->readRegister(CREG_DATA_INPUT_PROPERTIES,0x10,0,false); }
  bool dataInputPropertieIn4 (uint8_t v) { return this->writeRegister(CREG_DATA_INPUT_PROPERTIES,0x10,0,v); }
  
  bool dataInputPropertieIn5 () const { return this->readRegister(CREG_DATA_INPUT_PROPERTIES,0x20,0,false); }
  bool dataInputPropertieIn5 (uint8_t v) { return this->writeRegister(CREG_DATA_INPUT_PROPERTIES,0x20,0,v); }
  
  bool dataInputPropertieIn6 () const { return this->readRegister(CREG_DATA_INPUT_PROPERTIES,0x40,0,false); }
  bool dataInputPropertieIn6 (uint8_t v) { return this->writeRegister(CREG_DATA_INPUT_PROPERTIES,0x40,0,v); }
  
  bool dataInputPropertieIn7 () const { return this->readRegister(CREG_DATA_INPUT_PROPERTIES,0x80,0,false); }
  bool dataInputPropertieIn7 (uint8_t v) { return this->writeRegister(CREG_DATA_INPUT_PROPERTIES,0x80,0,v); }

  uint8_t channelFunction () const { return this->readRegister(CREG_CHANNEL_FUNCTION,0); }
  bool channelFunction (uint8_t v) const { return this->writeRegister(CREG_CHANNEL_FUNCTION,v); }
};


template <class Register>
class RegList3 : public RegisterList<Register> {
public:
  RegList3(uint16_t a) : RegisterList<Register>(a) {}

  uint8_t ctRampOn () const { return this->readRegister(PREG_CTRAMPONOFF,0x0f,0); }
  bool ctRampOn (uint8_t v) const { return this->writeRegister(PREG_CTRAMPONOFF,0x0f,0,v); }
  uint8_t ctRampOff () const { return this->readRegister(PREG_CTRAMPONOFF,0x0f,4); }
  bool ctRampOff (uint8_t v) const { return this->writeRegister(PREG_CTRAMPONOFF,0x0f,4,v); }
  uint8_t ctDlyOn () const { return this->readRegister(PREG_CTDELAYONOFF,0x0f,0); }
  bool ctDlyOn (uint8_t v) const { return this->writeRegister(PREG_CTDELAYONOFF,0x0f,0,v); }
  uint8_t ctDlyOff () const { return this->readRegister(PREG_CTDELAYONOFF,0x0f,4); }
  bool ctDlyOff (uint8_t v) const { return this->writeRegister(PREG_CTDELAYONOFF,0x0f,4,v); }
  uint8_t ctOn () const { return this->readRegister(PREG_CTONOFF,0x0f,0); }
  bool ctOn (uint8_t v) const { return this->writeRegister(PREG_CTONOFF,0x0f,0,v); }
  uint8_t ctOff () const { return this->readRegister(PREG_CTONOFF,0x0f,4); }
  bool ctOff (uint8_t v) const { return this->writeRegister(PREG_CTONOFF,0x0f,4,v); }
  uint8_t ctRepOn () const { return this->readRegister(PREG_CTREPONOFF,0x0f,0); }
  bool ctRepOn (uint8_t v) const { return this->writeRegister(PREG_CTREPONOFF,0x0f,0,v); }
  uint8_t ctRepOff () const { return this->readRegister(PREG_CTREPONOFF,0x0f,4); }
  bool ctRepOff (uint8_t v) const { return this->writeRegister(PREG_CTREPONOFF,0x0f,4,v); }

  uint8_t ctValLo() const { return this->readRegister(PREG_CONDVALUELOW,0x32); }
  bool ctValLo(uint8_t v) const { return this->writeRegister(PREG_CONDVALUELOW,v); }
  uint8_t ctValHi() const { return this->readRegister(PREG_CONDVALUEHIGH,0x64); }
  bool ctValHi(uint8_t v) const { return this->writeRegister(PREG_CONDVALUEHIGH,v); }
  uint8_t onDly() const { return this->readRegister(PREG_ONDELAYTIME,0x00); }
  bool onDly(uint8_t v) const { return this->writeRegister(PREG_ONDELAYTIME,v); }
  uint8_t onTime() const { return this->readRegister(PREG_ONTIME,0xff); }
  bool onTime(uint8_t v) const { return this->writeRegister(PREG_ONTIME,v); }
  uint8_t offDly() const { return this->readRegister(PREG_OFFDELAYTIME,0x00); }
  bool offDly(uint8_t v) const { return this->writeRegister(PREG_OFFDELAYTIME,v); }
  uint8_t offTime() const { return this->readRegister(PREG_OFFTIME,0xff); }
  bool offTime(uint8_t v) const { return this->writeRegister(PREG_OFFTIME,v); }

  uint8_t actionType() const { return this->readRegister(PREG_ACTIONTYPE,0x0f,0); }
  bool actionType(uint8_t v) const { return this->writeRegister(PREG_ACTIONTYPE,0x0f,0,v); }
  bool multiExec() const { return this->readBit(PREG_ACTIONTYPE,5,false); }
  bool multiExec(bool v) const { return this->writeBit(PREG_ACTIONTYPE,5,v); }
  bool offTimeMode() const { return this->readBit(PREG_ACTIONTYPE,6,false); }
  bool offTimeMode(bool v) const { return this->writeBit(PREG_ACTIONTYPE,6,v); }
  bool onTimeMode() const { return this->readBit(PREG_ACTIONTYPE,7,false); }
  bool onTimeMode(bool v) const { return this->writeBit(PREG_ACTIONTYPE,7,v); }

  /*uint8_t jtOn () const { return this->readRegister(PREG_JTONOFF,0x0f,0,AS_CM_JT_OFFDELAY); }
  bool jtOn (uint8_t v) const { return this->writeRegister(PREG_JTONOFF,0x0f,0,v); }
  uint8_t jtOff () const { return this->readRegister(PREG_JTONOFF,0x0f,4,AS_CM_JT_ONDELAY); }
  bool jtOff (uint8_t v) const { return this->writeRegister(PREG_JTONOFF,0x0f,4,v); }
  uint8_t jtDlyOn () const { return this->readRegister(PREG_JTDELAYONOFF,0x0f,0,AS_CM_JT_REFON); }
  bool jtDlyOn (uint8_t v) const { return this->writeRegister(PREG_JTDELAYONOFF,0x0f,0,v); }
  uint8_t jtDlyOff () const { return this->readRegister(PREG_JTDELAYONOFF,0x0f,4,AS_CM_JT_REFOFF); }
  bool jtDlyOff (uint8_t v) const { return this->writeRegister(PREG_JTDELAYONOFF,0x0f,4,v); }
  uint8_t jtRampOn () const { return this->readRegister(PREG_JTRAMPONOFF,0x0f,0,AS_CM_JT_ON); }
  bool jtRampOn (uint8_t v) const { return this->writeRegister(PREG_JTRAMPONOFF,0x0f,0,v); }
  uint8_t jtRampOff () const { return this->readRegister(PREG_JTRAMPONOFF,0x0f,4,AS_CM_JT_OFF); }
  bool jtRampOff (uint8_t v) const { return this->writeRegister(PREG_JTRAMPONOFF,0x0f,4,v); }
  uint8_t jtRefOn () const { return this->readRegister(PREG_JTREFONOFF,0x0f,0,AS_CM_JT_RAMPON); }
  bool jtRefOn (uint8_t v) const { return this->writeRegister(PREG_JTREFONOFF,0x0f,0,v); }
  uint8_t jtRefOff () const { return this->readRegister(PREG_JTREFONOFF,0x0f,4,AS_CM_JT_RAMPOFF); }
  bool jtRefOff (uint8_t v) const { return this->writeRegister(PREG_JTREFONOFF,0x0f,4,v); }*/

  bool offDelayBlink() const { return this->readBit(PREG_DELAYMODE,5,0); }
  bool offDelayBlink(bool v) const { return this->writeBit(PREG_DELAYMODE,5,v); }
  bool onLevelPrio() const { return this->readBit(PREG_DELAYMODE,6,0); }
  bool onLevelPrio(bool v) const { return this->writeBit(PREG_DELAYMODE,6,v); }
  bool onDelayMode() const { return this->readBit(PREG_DELAYMODE,7,0); }
  bool onDelayMode(bool v) const { return this->writeBit(PREG_DELAYMODE,7,v); }

  uint8_t offLevel() const { return this->readRegister(PREG_OFFLEVEL,0x00); }
  bool offLevel(uint8_t v) const { return this->writeRegister(PREG_OFFLEVEL,v); }
  uint8_t onMinLevel() const { return this->readRegister(PREG_ONMINLEVEL,20); }
  bool onMinLevel(uint8_t v) const { return this->writeRegister(PREG_ONMINLEVEL,v); }
  uint8_t onLevel() const { return this->readRegister(PREG_ONLEVEL,200); }
  bool onLevel(uint8_t v) const { return this->writeRegister(PREG_ONLEVEL,v); }
  uint8_t maxTimeFirstDir() const { return this->readRegister(PREG_MAXTIMEFIRSTDIR,254); }
  bool maxTimeFirstDir(uint8_t v) const { return this->writeRegister(PREG_MAXTIMEFIRSTDIR,v); }
  uint8_t drivingMode() const { return this->readRegister(PREG_DRIVINGMODE,0); }
  bool drivingMode(uint8_t v) const { return this->writeRegister(PREG_DRIVINGMODE,v); }

  uint8_t rampStartStep() const { return this->readRegister(PREG_RAMPSTARTSTEP,10); }
  bool rampStartStep(uint8_t v) const { return this->writeRegister(PREG_RAMPSTARTSTEP,v); }
  uint8_t rampOnTime() const { return this->readRegister(PREG_RAMPONTIME,0x00); }
  bool rampOnTime(uint8_t v) const { return this->writeRegister(PREG_RAMPONTIME,v); }
  uint8_t rampOffTime() const { return this->readRegister(PREG_RAMPOFFTIME,0x00); }
  bool rampOffTime(uint8_t v) const { return this->writeRegister(PREG_RAMPOFFTIME,v); }
  uint8_t dimMinLevel() const { return this->readRegister(PREG_DIMMINLEVEL,0x00); }
  bool dimMinLevel(uint8_t v) const { return this->writeRegister(PREG_DIMMINLEVEL,v); }
  uint8_t dimMaxLevel() const { return this->readRegister(PREG_DIMMAXLEVEL,200); }
  bool dimMaxLevel(uint8_t v) const { return this->writeRegister(PREG_DIMMAXLEVEL,v); }
  uint8_t dimStep() const { return this->readRegister(PREG_DIMSTEP,0x05); }
  bool dimStep(uint8_t v) const { return this->writeRegister(PREG_DIMSTEP,v); }
  uint8_t offDelayStep() const { return this->readRegister(PREG_OFFDELAYSTEP,0x0a); }
  bool offDelayStep(uint8_t v) const { return this->writeRegister(PREG_OFFDELAYSTEP,v); }
  uint8_t offDelayNewTime() const { return this->readRegister(PREG_OFFDELAYNEWTIME,0x05); }
  bool offDelayNewTime(uint8_t v) const { return this->writeRegister(PREG_OFFDELAYNEWTIME,v); }
  uint8_t offDelayOldTime() const { return this->readRegister(PREG_OFFDELAYOLDTIME,0x05); }
  bool offDelayOldTime(uint8_t v) const { return this->writeRegister(PREG_OFFDELAYOLDTIME,v); }

  uint8_t elseActionType() const { return this->readRegister(PREG_ELSEACTIONTYPE,0x0f,0); }
  bool elseActionType(uint8_t v) const { return this->writeRegister(PREG_ELSEACTIONTYPE,0x0f,0,v); }
  bool elseOffTimeMode() const { return this->readBit(PREG_ELSEACTIONTYPE,6,false); }
  bool elseOffTimeMode(bool v) const { return this->writeBit(PREG_ELSEACTIONTYPE,6,v); }
  bool elseOnTimeMode() const { return this->readBit(PREG_ELSEACTIONTYPE,7,false); }
  bool elseOnTimeMode(bool v) const { return this->writeBit(PREG_ELSEACTIONTYPE,7,v); }

  uint8_t elseJtOn () const { return this->readRegister(PREG_ELSEJTONOFF,0x0f,0); }
  bool elseJtOn (uint8_t v) const { return this->writeRegister(PREG_ELSEJTONOFF,0x0f,0,v); }
  uint8_t elseJtOff () const { return this->readRegister(PREG_ELSEJTONOFF,0x0f,4); }
  bool elseJtOff (uint8_t v) const { return this->writeRegister(PREG_ELSEJTONOFF,0x0f,4,v); }
  uint8_t elseJtDlyOn () const { return this->readRegister(PREG_ELSEJTDELAYONOFF,0x0f,0); }
  bool elseJtDlyOn (uint8_t v) const { return this->writeRegister(PREG_ELSEJTDELAYONOFF,0x0f,0,v); }
  uint8_t elseJtDlyOff () const { return this->readRegister(PREG_ELSEJTDELAYONOFF,0x0f,4); }
  bool elseJtDlyOff (uint8_t v) const { return this->writeRegister(PREG_ELSEJTDELAYONOFF,0x0f,4,v); }
  uint8_t elseJtRampOn () const { return this->readRegister(PREG_ELSEJTRAMPONOFF,0x0f,0); }
  bool elseJtRampOn (uint8_t v) const { return this->writeRegister(PREG_ELSEJTRAMPONOFF,0x0f,0,v); }
  uint8_t elseJtRampOff () const { return this->readRegister(PREG_ELSEJTRAMPONOFF,0x0f,4); }
  bool elseJtRampOff (uint8_t v) const { return this->writeRegister(PREG_ELSEJTRAMPONOFF,0x0f,4,v); }

  uint8_t actType() const { return this->readRegister(PREG_ACTTYPE,0x00); }
  bool actType(uint8_t v) const { return this->writeRegister(PREG_ACTTYPE,v); }
  uint8_t actNum() const { return this->readRegister(PREG_ACTNUM,0x00); }
  bool actNum(uint8_t v) const { return this->writeRegister(PREG_ACTNUM,v); }
  uint8_t actIntens() const { return this->readRegister(PREG_ACTINTENS,0x00); }
  bool actIntens(uint8_t v) const { return this->writeRegister(PREG_ACTINTENS,v); }

};


template <class Register>
class RegList4 : public RegisterList<Register> {
public:
  RegList4(uint16_t a) : RegisterList<Register>(a) {}

  bool burst() const { return peerNeedsBurst(); }

  bool peerNeedsBurst(bool v) const { return this->writeRegister(PREG_BURST_AES,0x01,0,v); }
  bool peerNeedsBurst() const { return this->readRegister(PREG_BURST_AES,0x01,0,false); }

  bool expectAES(bool v) const { return this->writeRegister(PREG_BURST_AES,0x01,7,v); }
  bool expectAES() const { return this->readRegister(PREG_BURST_AES,0x01,7,false); }
};


template <class PeerListType>
class ShortLongList : public BaseList{
public:
  typedef PeerListType PeerList;
  ShortLongList(uint16_t a) : BaseList(a) {}

  const PeerList sh () const { return PeerList(this->address()); }
  const PeerList lg () const { return PeerList(this->address() + PeerList::size() ); }

  static uint8_t getOffset(uint8_t reg) {
    if( reg & 0x80 ) {
      return PeerList::size() + getOffset(reg & ~0x80);
    }
    return PeerList::getOffset(reg);
  }
  static uint8_t getRegister(uint8_t offset) {
    if( offset >= PeerList::size() ) {
      return getRegister( offset - PeerList::size() ) | 0x80;
    }
    return PeerList::getRegister(offset);
  }
  static uint8_t size () { return 2*PeerList::size(); }

  operator GenericList () const {
    return GenericList(address(),size(),getRegister,getOffset);
  }

};

DEFREGISTER(DefaultRegisterList0,DREG_INTKEY,MASTERID_REGS)
typedef RegList0<DefaultRegisterList0> DefList0;

DEFREGISTER(DefaultRegisterList1,CREG_AES_ACTIVE)
typedef RegList1<DefaultRegisterList1> DefList1;

DEFREGISTER(DefaultRegisterList4,PREG_BURST_AES)
typedef RegList4<DefaultRegisterList4> DefList4;

}

#endif
