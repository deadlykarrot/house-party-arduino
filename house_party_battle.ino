#include <Servo.h> // use the library

Servo elementalServo; // servo for the elementals

Servo garageServo; // servo for the garage
Servo wallServo; // servo for the front wall
Servo finalServo; // servo that knocks Aelwyn over at the end.

// the pins for each switch, to access them more easily and change them quickly.
// all figure pins are set to 4, until we decide which pins they actually go to.
const int sisterPin1 = 13; // pin for setting Adaine and Aelwyn up outside
const int spiritPin = 2; // pin for setting up the spirit guardians
const int stairPin = 11; // pin for Aelwyn in the web and the cycle on the stairs with Adaine attached

const int sisterPin2 = 9; // pin for setting Adaine and Aelwyn up inside
const int buttPin = 4; // pin for the button at the end

// the values of the pins, to detect when things are placed upon them
int sisterVal1; // value for setting Adaine and Aelwyn up outside
int spiritVal; // value for setting up the spirit guardians
int stairVal; // value for Aelwyn in the web and the motorcycle on the stairs with Adaine

int sisterVal2; // value for setting Adaine and Aelwyn up inside
int buttVal; // value for the button at the end

// light up the current scene the user must assemble 
bool outerLit = true; // whether or not the outside area is lit
bool lowerLit = false; // whether or not the lower floor is lit
bool upperLit = false; // whether or not the upper floor is lit
const int outerLedPin = 10; // the pin for the lower floor LED(s)
const int lowerLedPin = 12; // the pin for the lower floor LED(s)
const int upperLedPin = 7; // the pin for the upper floor LED(s)
// use servos and walls to open the specific parts that are shown to the user
bool garageOpen = false; // whether or not the garage is open
bool lowerOpen = false; // whether or not the first floor is open
bool upperOpen = false; // whether or not the upper floor is open

int stage = 0; /* the current scene, as follows:
0 - beginning, user must set up Adaine and Aelwyn
1 - garage is open, user must place spirit guardians
2 - first floor is lit, user must set up web, Aelwyn, motorcycle, Adaine on motorcycle
3 - second floor is lit, user must set up Adaine and Aelwyn at the end
4 - Adaine and Aelwyn in place, user must press switch to end the sequence
5 - sequence is done, victory music plays
*/
void setup() {
  // put your setup code here, to run once: 
  Serial.begin(9600);
  Serial.println("test");
  // initialize switches
  pinMode(sisterPin1, INPUT); // set sister pin 1 to input
  pinMode(spiritPin, INPUT); // set spirit pin to input
  pinMode(stairPin, INPUT); // set stair pin to input
  pinMode(sisterPin2, INPUT); // set sister pin 2 to input
  pinMode(outerLedPin, OUTPUT); // set lower floor led pin to output
  pinMode(lowerLedPin, OUTPUT); // set lower floor led pin to output
  pinMode(upperLedPin, OUTPUT); // set upper floor led pin to output
  //elementalServo1.attach(4); // attach the servo for the second elemental
  //elementalServo1.write(0); // attach the servo for the second elemental
  //elementalServo2.attach(4); // attach the servo for the second elemental
  //elementalServo2.write(0); // attach the servo for the second elemental
  garageServo.attach(3); // attach the servo for the garage
  garageServo.write(0); // start at zero.
  
  elementalServo.attach(5); // servo for the front wall
  elementalServo.write(0); // start wall servo at zero
  //finalServo.attach(4); // attach final servo
  //finalServo.write(0); // start final servo at zero
  //Serial.println("test");
  delay(1000);

}

void loop() {
  //digitalWrite(lowerLedPin, HIGH);
  //digitalWrite(upperLedPin, LOW);
  //garageServo.write(0);
  //garageServo.write(180);
  
  
  //digitalWrite(upperLedPin, HIGH);
  //digitalWrite(lowerLedPin, LOW);
  //delay(1000);
  if (outerLit == true){
    digitalWrite(outerLedPin, HIGH);
  } else {
    digitalWrite(outerLedPin, LOW);
  }
  if (lowerLit == true){
    digitalWrite(lowerLedPin, HIGH);
  } else {
    digitalWrite(lowerLedPin, LOW);
  }
  if (upperLit == true){
    digitalWrite(upperLedPin, HIGH);
  } else {
    digitalWrite(upperLedPin, LOW);
  }
  delay(500);
  //garageServo.write(180);
  sisterVal1 = digitalRead(sisterPin1); // get the outside Adaine and Aelwyn value
  spiritVal = digitalRead(spiritPin); // get the spirit guardians value
  stairVal = digitalRead(stairPin); // get the web and cycle value
  
  sisterVal2 = digitalRead(sisterPin2); // get the inside Adaine and Aelwyn value
  buttVal = digitalRead(buttPin); // get the button value
  Serial.println("Sister val 1: " + String(sisterVal1));
  Serial.println("Spirit val: " + String(spiritVal));
  Serial.println("Stair val: " + String(stairVal));
  Serial.println("Sister val 2: " + String(sisterVal2));
  Serial.println("stage: " + String(stage));
  //delay(1000);
  
  //Serial.println(sisterVal1  );
  switch(stage){
    case 0: // beginning, user must set up Adaine and Aelwyn
      garageServo.write(0);
      outerLit = true;
      if (sisterVal1 == HIGH){ // when the button is pressed, go to the next stage.
        delay(100); // slight delay, so it's not too jarring and instant.
        // spin the elementals around here
        elementalServo.write(180);
        
        //garageServo.write(0);
        // lift the garage door, when finished change stage
        stage = 1;
      }
      break;
    case 1: // garage is open, user must place spirit guardians
      outerLit = true;
      garageServo.write(35);
      if (spiritVal == HIGH){ // when the button is pressed, go to the next stage.
        // lift up the lower floor door, then light up lower floor and change stage.
        elementalServo.write(0);
        stage = 2;
        lowerLit = true; // light up the lower floor
      }
      break;
    case 2: // first floor is open, user must set up web, Aelwyn, motorcycle, Adaine on motorcycle
      lowerLit = true;
      outerLit = false;
      garageServo.write(0);
      if (stairVal == HIGH){ // when the web and cycle combo are set up, go to the next stage.
        // lift up the upper floor door, dim the lower floor, then light up the upper floor and change stage.
        stage = 3;
        lowerLit = false; // dim the first floor
        upperLit = true; // light up the lower floor
      }
      break;
    case 3: // second floor is open, user must set up Adaine and Aelwyn at the end
      upperLit = true; 
      if (sisterVal2 == HIGH){ // when the button is pressed, go to the next stage.
        stage = 4;
      }
      break;
    case 4: // Adaine and Aelwyn in place, user must press switch to end the sequence
      if (sisterVal2 == HIGH && buttVal == HIGH){ // when the button is pressed, go to the next stage.
        stage = 5;
      }
      break;
    case 5: // sequence is done, victory music plays
      for (int i = 0; i < 10; i += 1){
        delay(100);
        digitalWrite(upperLedPin, HIGH);
        delay(100);
        digitalWrite(upperLedPin, LOW);
      }
      upperLit = false;
      break;
    default:
      break;
    
  }
  
}

