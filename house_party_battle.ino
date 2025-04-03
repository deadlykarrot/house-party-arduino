#include <Servo.h> // use the library

Servo elementalServo1; // servo for the first elemental
Servo elementalServo2; // servo for the second elemental
Servo garageServo; // servo for the garage
Servo wallServo; // servo for the front wall
Servo finalServo; // servo that knocks Aelwyn over at the end.

// the pins for each switch, to access them more easily and change them quickly.
// all figure pins are set to 4, until we decide which pins they actually go to.
const int aelwynPin1 = 4; // pin for setting Aelwyn up outside
const int adainePin1 = 4; // pin for setting Adaine up outside
const int webPin = 4; // pin for Aelwyn in the web
const int cyclePin = 4; // pin for the motorcycle on the stairs with Adaine attached
int aelwynButt2; // value for setting Aelwyn up inside
int adaineButt2; // value for setting Adaine up inside
const int buttPin = 4; // pin for the button at the end

// the values of the pins, to detect when things are placed upon them
int aelwynVal1; // value for setting Aelwyn up outside
int adaineVal1; // value for setting Adaine up outside
int webVal; // value for Aelwyn in the web
int cycleVal; // value for the motorcycle on the stairs with Adaine attached
int aelwynVal2; // value for setting Aelwyn up inside
int adaineVal2; // value for setting Adaine up inside
int buttVal; // value for the button at the end

// light up the current scene the user must assemble
bool lowerLit = false; // whether or not the lower floor (and motorcycle) are lit
bool upperLit = false; // whether or not the upper floor is lit
const int lowerLedPin = 4; // the pin for the lower floor LED(s)
const int upperLedPin = 4; // the pin for the lower floor LED(s)
// use servos and walls to open the specific parts that are shown to the user
bool garageOpen = false; // whether or not the garage is open
bool lowerOpen = false; // whether or not the first floor is open
bool upperOpen = false; // whether or not the upper floor is open

int stage = 0; /* the current scene, as follows:
0 - beginning, user must set up Adaine and Aelwyn
1 - garage is open, user must place spirit guardians
2 - first floor is open, user must set up web, Aelwyn, motorcycle, Adaine on motorcycle
3 - second floor is open, user must set up Adaine and Aelwyn at the end
4 - Adaine and Aelwyn in place, user must press switch to end the sequence
*/
void setup() {
  // put your setup code here, to run once:
  pinMode(lowerLedPin, OUTPUT); // set lower floor led pin to output
  pinMode(upperLedPin, OUTPUT); // set upper floor led pin to output
}

void loop() {
  // put your main code here, to run repeatedly:
  aelwynVal1 = digitalRead(aelwynPin1); // get the outside Aelwyn value
  adaineVal1 = digitalRead(adainePin1); // get the outside Adaine value
  webVal = digitalRead(webPin); // get the web value
  cycleVal = digitalRead(cyclePin); // get the motorcycle value
  aelwynVal2 = digitalRead(aelwynPin2); // get the inside Aelwyn value
  adaineVal2 = digitalRead(adainePin2); // get the inside Adaine value
}
