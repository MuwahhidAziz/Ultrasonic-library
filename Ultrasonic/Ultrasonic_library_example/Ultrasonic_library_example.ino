#include "Ultrasonic.h"
Ultrasonic sonar(3, 4, 20); // triggerPin, echoPin, temperature in celsius(type in current temperature in celsius or just enter 20)
float distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = sonar.getDistance(m); // getting distance from sensor in meters and storing its value in a variable
  // see Ultrasonic_length_units.h for other available units of length
  delay(1000);
}
