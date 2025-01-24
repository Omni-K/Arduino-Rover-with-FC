// ---- Class TwoChannelJoyStick

#ifndef CLASSTwoChannelJoyStick_H
#define CLASSTwoChannelJoyStick_H

class TwoChannelJoyStick {
  public:
    TwoChannelJoyStick(byte ch1_pin, byte ch2_pin){
      pinMode(ch1_pin, INPUT);
      pinMode(ch2_pin, INPUT);
      _ch1_pin = ch1_pin;
      _ch2_pin = ch2_pin;
    }

    TwoChannelJoyStick(byte ch1_pin, byte ch2_pin, byte aux1_pin, byte aux2_pin){
      pinMode(ch1_pin, INPUT);
      pinMode(ch2_pin, INPUT);
      _ch1_pin = ch1_pin;
      _ch2_pin = ch2_pin;

      pinMode(aux1_pin, INPUT);
      pinMode(aux2_pin, INPUT);
      _aux1_pin = aux1_pin;
      _aux2_pin = aux2_pin;
    }

    int channel_1_8bit(){
      int ch1_servo = int(pulseIn(_ch1_pin, HIGH) - _mid);
      bool is_positve = ch1_servo >= 0;
      ch1_servo = abs(ch1_servo) - _mid_delta;
      
      if (ch1_servo < 0) ch1_servo = 0;
      if (ch1_servo > _pike) ch1_servo = _pike;
      int value = map(ch1_servo, 0, _pike, 0, 254);
      if (is_positve){
        return value;
      } else {
        return -value;
      }
    }

    int channel_2_8bit(){
      int ch2_servo = int(pulseIn(_ch2_pin, HIGH) - _mid);
      bool is_positve = ch2_servo >= 0;
      ch2_servo = abs(ch2_servo) - _mid_delta;
      
      if (ch2_servo < 0) ch2_servo = 0;
      if (ch2_servo > _pike) ch2_servo = _pike;
      int value = map(ch2_servo, 0, _pike, 0, 254);
      if (is_positve){
        return value;
      } else {
        return -value;
      }
    }

    bool aux1_on(){
      return analogRead(_aux1_pin) > 300;
    }

    bool aux2_on(){
      return analogRead(_aux2_pin) > 300;
    }

  private:
    byte _ch1_pin;
    byte _ch2_pin;
    byte _aux1_pin;
    byte _aux2_pin; 

    int _mid = 1500;
    int _high = 2000;
    int _low = 1000;
    int _mid_delta = 200;
    int _pike = _high-_mid-_mid_delta;
};
#endif