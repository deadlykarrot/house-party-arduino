#include <Servo.h> // use the library

Servo elementalServo1; // servo for the first elemental
Servo elementalServo2; // servo for the second elemental
Servo garageServo; // servo for the garage
Servo wallServo; // servo for the front wall
Servo finalServo; // servo that knocks Aelwyn over at the end.

// the pins for each switch, to access them more easily and change them quickly.
// all figure pins are set to 4, until we decide which pins they actually go to.
const int sisterPin1 = 4; // pin for setting Adaine and Aelwyn up outside
const int spiritPin = 4; // pin for setting up the spirit guardians
const int webPin = 4; // pin for Aelwyn in the web
const int cyclePin = 4; // pin for the motorcycle on the stairs with Adaine attached
const int sisterPin2 = 4; // pin for setting Adaine and Aelwyn up inside
const int buttPin = 4; // pin for the button at the end

// the values of the pins, to detect when things are placed upon them
int sisterVal1; // value for setting Adaine and Aelwyn up outside
int spiritVal; // value for setting up the spirit guardians
int webVal; // value for Aelwyn in the web
int cycleVal; // value for the motorcycle on the stairs with Adaine attached
int sisterVal2; // value for setting Adaine and Aelwyn up inside
int buttVal; // value for the button at the end

// light up the current scene the user must assemble
bool lowerLit = false; // whether or not the lower floor is lit
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
5 - sequence is done, victory music plays
*/
void setup() {
  // put your setup code here, to run once:
  pinMode(lowerLedPin, OUTPUT); // set lower floor led pin to output
  pinMode(upperLedPin, OUTPUT); // set upper floor led pin to output
}

void loop() {
  // put your main code here, to run repeatedly:
  sisterVal1 = digitalRead(sisterPin1); // get the outside Adaine and Aelwyn value
  spiritVal = digitalRead(spiritPin); // get the spirit guardians value
  webVal = digitalRead(webPin); // get the web value
  cycleVal = digitalRead(cyclePin); // get the motorcycle value
  sisterVal2 = digitalRead(sisterPin2); // get the inside Adaine and Aelwyn value
  buttVal = digitalRead(buttPin); // get the button value
  switch(stage){
    case 0: // beginning, user must set up Adaine and Aelwyn
      if (sisterVal == HIGH){ // when the button is pressed, go to the next stage.
        // spin the elementals around here
        // lift the garage door, when finished change stage
        stage = 1;
      }
    case 1: // garage is open, user must place spirit guardians
      if (spiritVal == HIGH){ // when the button is pressed, go to the next stage.
        // lift up the lower floor door, then light up lower floor and change stage.
        stage = 2;
        lowerLit = true; // light up the lower floor
      }
    case 2: // first floor is open, user must set up web, Aelwyn, motorcycle, Adaine on motorcycle
      if (webVal == HIGH && cycleVal == HIGH){ // when the web and cycle combo are set up, go to the next stage.
        // lift up the upper floor door, dim the lower floor, then light up the upper floor and change stage.
        stage = 3;
        lowerLit = false; // dim the first floor
        upperLit = true; // light up the lower floor
      }
    case 3: // second floor is open, user must set up Adaine and Aelwyn at the end
      if (sisterVal2 == HIGH){ // when the button is pressed, go to the next stage.
        stage = 4;
      }
    case 4: // Adaine and Aelwyn in place, user must press switch to end the sequence
      if (sisterVal2 == HIGH && buttVal == HIGH){ // when the button is pressed, go to the next stage.
        stage = 5;
      }
    case 5: // sequence is done, victory music plays
      // play music here
    default:
      break;
  }
}
