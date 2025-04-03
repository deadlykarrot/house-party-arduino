#include <Servo.h> // use the library

Servo elementalServo1; // servo for the first elemental
Servo elementalServo2; // servo for the second elemental
Servo garageServo; // servo for the garage
Servo wallServo; // servo for the front wall
Servo finalServo; // servo that knocks Aelwyn over at the end.

// all figure pins are set to 4, until we decide which pins they actually go to.
const int buttPin = 4; // pin for the button at the end
const int aelwynPin1 = 4; // pin for setting Aelwyn up outside
const int adainePin1 = 4; // pin for setting Adaine up outside
const int webPin = 4; // pin for Aelwyn in the web
const int motorPin = 4; // pin for the motorcycle on the stairs with Adaine attached
// light up the current scene the user must assemble
bool lowerLit = false; // whether or not the lower floor (and motorcycle) are lit
bool upperLit = false; // whether or not the upper floor is lit
// use servos and walls to open the specific parts that are shown to the user
bool garageOpen = false; // whether or not the garage is open
bool lowerOpen = false; // whether or not the first floor is open
bool upperOpen = false; // whether or not the upper floor is open

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
