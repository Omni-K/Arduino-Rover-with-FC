// ------------------------------------------------------------- CLASSES
#include "Wheel.h"
#include "TwoChannelJoyStick.h"
#include "Vehicle.h"


// ------------------------------------------------------------- ПРЕДУСТАНОВКИ И ПЕРЕМЕННЫЕ
//byte pwm_pins[] = {3, 5, 6, 9, 10, 11};

Wheel left_wheel(7, 8, 9);
Vehicle car(7, 8, 9, 4, 3, 2);
TwoChannelJoyStick pult(10, 11, A0, A1);

/*
void w(int en, int pwm2, int pwm1){
  Serial.println(String(en) + "\t" + String(pwm2) + "\t" + String(pwm1));
  digitalWrite(7, en);
  if (pwm2 > 1){
    analogWrite(8, pwm2);
  } else {
    digitalWrite(8, pwm2);
  }

  if (pwm1 > 1){
    analogWrite(9, pwm1);
  } else {
    digitalWrite(9, pwm1);
  }
}
*/
// ------------------------------------------------------------- SETUP
void setup() {
  Serial.begin(9600);

}
// ------------------------------------------------------------- LOOP
int m = 1;
void loop() {
  loop_control();
}

void loop_control(){

}
/*
void loop_2(){
  Serial.println("SPEED UP FW");
  for (int i = 0; i<256; i++){
    left_wheel.fw(i);
    delay(33);
  }
  delay(1000);
  Serial.println("SPEED DOWN FW");
  for (int i = 0; i<256; i++){
    left_wheel.fw(255-i);
    delay(33);
  }
  delay(1000);
  Serial.println("SPEED DOWN BW");
  for (int i = 0; i<256; i++){
    left_wheel.bw(255-i);
    delay(33);
  }
  delay(1000);
  Serial.println("SPEED DOWN BW");
  for (int i = 1; i<256; i++){
    left_wheel.bw(i);
    delay(33);
  }
  
}
void loop_1(){
  //w(1, 1, 1);
  
  for (int b1 = 0; b1 <2; b1++){
    for (int b2 = 0; b2 <2; b2++){
      for (int b3 = 0; b3 <2; b3++){
        w(b1, b2, b3);
        Serial.println(String(b1) + "\t" + String(b2) + "\t" + String(b3));
        delay(1000);
  }
  }
  }
  
  delay(5000);
  //w(0, 0, 1);
  delay(2000);
  for (int spd = 0; spd < 260/16; spd++){
    //w(0, 0, 255-spd*16);
    delay(500);
  }
  delay(100);
  //w(0,1,0);
  delay(1000);
  for (int spd = 0; spd < 260/5; spd++){
    //w(0, 1, spd);
    delay(100);
  }
  delay(3333);
  m++;
}
*/

