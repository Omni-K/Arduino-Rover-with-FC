#include "HardwareSerial.h"
#include "WString.h"
// ----- class Vehicle
#ifndef PrettySerialPrint_H
#define PrettySerialPrint_H

// простые
void pp(int value) {
  Serial.print(value);
}

void pp(float value) {
  Serial.print(value);
}

void pp(const char* value) {
  Serial.print(value);
}

void pp(bool value) {
  Serial.print(value ? "true" : "false");
}
//  с окончанием
void pp(int value, char end) {
  Serial.print(value);
  Serial.print(end);
}

void pp(float value, char end) {
  Serial.print(value);
  Serial.print(end);
}

void pp(const char* value, char end) {
  Serial.print(value);
  Serial.print(end);
}

void pp(bool value, char end) {
  Serial.print(value ? "true" : "false");
  Serial.print(end);
}

// принтЛН

void ppln(int value) {
  Serial.println(value);
}

void ppln(float value) {
  Serial.println(value);
}

void ppln(const char* value) {
  Serial.println(value);
}

void ppln(bool value) {
  Serial.println(value ? "true" : "false");
}

#endif