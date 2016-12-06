// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  motor1.setSpeed(250);
  motor2.setSpeed(250);

}

void loop() {
 motor1.run(FORWARD);
 motor2.run(FORWARD);
}
