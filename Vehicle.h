// ----- class Vehicle
#ifndef CLASSVehicle_H
#define CLASSVehicle_H

class Vehicle{
  #include "Wheel.h"
  public:
    Vehicle(byte w1_en, byte w1_pwm2, byte w1_pwm1, byte w2_en, byte w2_pwm2, byte w2_pwm1){
      Wheel _w_left(w1_en, w1_pwm2, w1_pwm1, "right");
      Wheel _w_right(w2_en, w2_pwm2, w2_pwm1, "left");

    }
    void fw(byte speed) {
      if (speed < 0) speed = abs(speed);
      _w_left.fw(speed);
      _w_right.fw(speed);
    }
    void free(){
      _w_left.free();
      _w_right.free();
    }
    void bw(byte speed) {
      if (speed < 0) speed = abs(speed);
      _w_left.bw(speed);
      _w_right.bw(speed);
    }
    void left_round(byte speed){
      if (speed < 0) speed = abs(speed);
      _w_left.bw(speed);
      _w_right.fw(speed);
    }
    void right_round(byte speed){
      if (speed < 0) speed = abs(speed);
      _w_left.fw(speed);
      _w_right.bw(speed);
    }
    void fw_left(byte speed, byte turn_influence){
      if (speed < 0) speed = abs(speed);
      if (turn_influence < 0) turn_influence = abs(turn_influence);
      _w_right.fw(speed);
      byte spd2 = byte(speed * float(254 - turn_influence)/254.0);
      _w_left.fw(spd2);
    }
    void fw_right(byte speed, byte turn_influence){
      if (speed < 0) speed = abs(speed);
      if (turn_influence < 0) turn_influence = abs(turn_influence);
      _w_left.fw(speed);
      byte spd2 = byte(speed * float(254 - turn_influence)/254.0);
      _w_right.fw(spd2);
    }
    void bw_left(byte speed, byte turn_influence){
      if (speed < 0) speed = abs(speed);
      if (turn_influence < 0) turn_influence = abs(turn_influence);
      _w_right.bw(speed);
      byte spd2 = byte(speed * float(254 - turn_influence)/254.0);
      _w_left.bw(spd2);
    }
    void bw_right(byte speed, byte turn_influence){
      if (speed < 0) speed = abs(speed);
      if (turn_influence < 0) turn_influence = abs(turn_influence);
      _w_left.bw(speed);
      byte spd2 = byte(speed * float(254 - turn_influence)/254.0);
      _w_right.bw(spd2);
    }

  private:
    Wheel _w_left;
    Wheel _w_right;
};

#endif