/*
   COGS 220 - Robot Competition
   A mobile robot that can identify colored blocks and pick them up.
*/

//Import Libraries
#include <Servo.h>

//Create the servo objects
Servo leftWheel;
Servo rightWheel;


//Arduino Pin Constants
const int leftServoPin = 7;             //Pin for left servo: Pin 7
const int rightServoPin = 8;            //Pin for right servo: Pin 8
const int LDPin = A0;                    //Connect the line-detecting IR to analog pin 1


//Global Variables
int blockDetected = 0;
int blockColor;
int desiredColor = 1;   //Red(1), Green(2), Blue(3), Yellow(4)
float directMovement;

void setup() {
  pinMode(3, INPUT);

  leftWheel.attach(leftServoPin);
  rightWheel.attach(rightServoPin);
}

void loop() {
  int sensor = analogRead(LDPin); //0 is no line, 1 is line
  int whiteLineDetect = map(sensor, 550, 950, 1, 100);

  if (whiteLineDetect >= 90) {
    driveReverse();
  }
  else if(whiteLineDetect < 90) {
    driveForwards();
  }
}

void driveForwards() {
  leftWheel.writeMicroseconds(1000);
  rightWheel.writeMicroseconds(2000);
  delay(100);
}

void driveReverse() {
  leftWheel.writeMicroseconds(2000);    //The robot reverses to the right
  rightWheel.writeMicroseconds(1000);
  delay(100);
}

void driveStop() {
  leftWheel.writeMicroseconds(1500);
  rightWheel.writeMicroseconds(1500);
  delay(100);
}

