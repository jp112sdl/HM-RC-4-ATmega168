//- -----------------------------------------------------------------------------------------------------------------------
// AskSin++
// 2017-04-12 papa Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
//- -----------------------------------------------------------------------------------------------------------------------

#ifndef __REMOTE_H__
#define __REMOTE_H__
namespace as {
  
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

template<class HALTYPE, int PEERCOUNT, class List0Type = List0, class List1Type = RemoteList1>
class RemoteChannel : public Channel<HALTYPE, List1Type, EmptyList, DefList4, PEERCOUNT, List0Type>, public KeypadButton {
  private:
    uint8_t       repeatcnt;
  public:

    typedef Channel<HALTYPE, List1Type, EmptyList, DefList4, PEERCOUNT, List0Type> BaseChannel;

    RemoteChannel () : BaseChannel(), repeatcnt(0) {}
    virtual ~RemoteChannel () {}

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
#ifdef __AVR_ATmega1284P__
        Serial.print("sendPeerEvent ch:"); Serial.println(this->number(), DEC);
        this->device().sendPeerEvent(msg, *this);
#endif
        repeatcnt++;
      }
      else if (s == longpressed) {
#ifdef __AVR_ATmega1284P__
        Serial.print("broadcastPeerEvent ch:"); Serial.println(this->number(), DEC);
#endif
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
}
#endif
