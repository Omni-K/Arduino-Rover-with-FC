// class Wheel
#ifndef CLASSWHEEL_H
#define CLASSWHEEL_H

class Wheel {
  public:
    Wheel(){
      _en_pin = 7;
      _pwml2_pin = 8;
      _pwml1_pin = 9;
      _side = "right";
    }
    Wheel(byte en_pin, byte pwml2_pin, byte pwml1_pin){
      _en_pin = en_pin;
      _pwml2_pin = pwml2_pin;
      _pwml1_pin = pwml1_pin;
      _side = "right";
      init_pins();
    }

    Wheel(byte en_pin, byte pwml2_pin, byte pwml1_pin, String side){
      _en_pin = en_pin;
      _pwml2_pin = pwml2_pin;
      _pwml1_pin = pwml1_pin;
      _side = side;
      if (_side != "right" or _side != "left"){
        _side = "right";
      }
      init_pins();
    }

    void free(){
      Serial.println("free");
      digitalWrite(_en_pin, 1);
      digitalWrite(_pwml2_pin, 1);
      digitalWrite(_pwml1_pin, 1);
    }

    void stop(){
      Serial.println("stop");
      digitalWrite(_en_pin, 0);
      digitalWrite(_pwml2_pin, 1);
      digitalWrite(_pwml1_pin, 1);
    }

    void fw(byte speed){
      Serial.println("fw ("+String(speed)+")");
      if (speed > 254) {
        speed = 254;
      }
      if (_side == "right") {
        cw(speed);
      } else {
        ccw(speed);
      }
    }

    void bw(byte speed){
      Serial.println("bw ("+String(speed)+")");
      if (speed > 254) {
        speed = 254;
      }
      if (_side == "right") {
        ccw(speed);
      } else {
        cw(speed);
      }
    }


  private:
    byte _en_pin;
    byte _pwml2_pin;
    byte _pwml1_pin;
    bool _side = "right";

    void init_pins(){
      pinMode(_en_pin, OUTPUT);
      pinMode(_pwml2_pin, OUTPUT);
      pinMode(_pwml1_pin, OUTPUT);
      //byte pwm_pins[] = {3, 5, 6, 9, 10, 11};
    }

    void ccw(byte speed){
      digitalWrite(_en_pin, 0);
      digitalWrite(_pwml2_pin, 0);
      analogWrite(_pwml1_pin, speed);
    }
    void cw(byte speed){
      digitalWrite(_en_pin, 0);
      digitalWrite(_pwml2_pin, 1);
      analogWrite(_pwml1_pin, 255-speed);
    }
};
#endif