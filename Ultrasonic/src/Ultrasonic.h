#ifndef ULTRASONIC_H
#define ULTRASONIC_H
#include "Arduino.h"
#include "Ultrasonic_length_units.h"
class Ultrasonic {
  public:
  Ultrasonic(int trig, int echo, long C);
  Ultrasonic(int pos, int neg, int trig, int echo, long C);
  long getDistance(String unit);
  private:
  void init();
  int t, e;
  float pulse, distance, d;
  float sped; // speed
};
#endif
