#include "Arduino.h"
#include "Ultrasonic.h"
#include "Ultrasonic_length_units.h"
Ultrasonic::Ultrasonic(int trig, int echo, long C){
  t = trig;
  e = echo;
  sped = sqrt(1.4 * 287.05 * (C + 273)); // sped = 331.5 + (0.6 * C);
}
Ultrasonic::Ultrasonic(int pos, int neg, int trig, int echo, long C){
  t = trig;
  e = echo;
  pinMode(pos, OUTPUT);
  pinMode(neg, OUTPUT);
  digitalWrite(pos, HIGH);
  digitalWrite(neg, LOW);
  sped = sqrt(1.4 * 287.05 * (C + 273)); // sped = 331.5 + (0.6 * C);
}
void Ultrasonic::init(){
  pinMode(t, OUTPUT);
  digitalWrite(t, LOW);
  delayMicroseconds(2);
  digitalWrite(t, HIGH);
  delayMicroseconds(10);
  digitalWrite(t, LOW);
  pinMode(e, INPUT);
  pulse = pulseIn(e, HIGH);
}
long Ultrasonic::getDistance(String unit){
  init();
  distance = (pulse * sped)/2;
  // General unit of length (SI unit)
  if (unit == m){
    d = distance;
  }
  // Other units of length
  else if (unit == in){
    d = (distance * 100) / 2.5;
  }
  else if (unit == ft){
    d = (distance * 100) / 30.43;
  }
  else if (unit == mi){
    d = (distance / 1000) / 1.64;
  }
  // Units of length greater than meter in order of decreasing power of 10 (prefixes)
  else if (unit == Em){
    d = (distance / 1000000000000000000);
  }
  else if (unit == Pm){
    d = (distance / 1000000000000000);
  }
  else if (unit == Tm){
    d = (distance / 1000000000000);
  }
  else if (unit == Gm){
    d = (distance / 1000000000);
  }
  else if (unit == Mm){
    d = (distance / 1000000);
  }
  else if (unit == km){
    d = (distance / 1000);
  }
  else if (unit == hm){
    d = (distance / 100);
  }
  else if (unit == dam){
    d = (distance / 10);
  }
  // Units of length less than meter in order of decreasing power of 10 (prefixes)
   else if (unit == am){
    d = (distance * 1000000000000000000);
  }
  else if (unit == fm){
    d = (distance * 1000000000000000);
  }
  else if (unit == pm){
    d = (distance * 1000000000000);
  }
  else if (unit == nm){
    d = (distance * 1000000000);
  }
  else if (unit == um){
    d = (distance * 1000000);
  }
  else if (unit == mm){
    d = (distance * 1000);
  }
  else if (unit == cm){
    d = (distance * 100);
  }
  else if (unit == dm){
    d = (distance * 10);
  }
  // In case of unknown or unavailable unit
  else {
    d = distance; 
  }
  return d;
}
