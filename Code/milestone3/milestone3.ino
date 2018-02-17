//Import Libraries
#include <Servo.h>
#include <SPI.h>
#include <Pixy.h>
#include <avr/sleep.h>

//Create the servo objects
Servo LeftWheel;
Servo RightWheel;
Pixy camera;

//NOTE: DO NOT USE pin 0 or pin 1
const int leftServoPin = A2;             //Pin for left servo: Pin #6
const int rightServoPin = A3;            //Pin for right servo: Pin #7
const int QREPin = A0;                  //Pin for line-detecting sensor: Analog Pin A0

//Global Variables
int LDSensor;                //Create variable for line-detecting sensor
int cameraColor;
bool test2 = false;

void Drive(float ls, float rs, float d) {
  /*
     -50 < ls & rs < 50
     d is in microseconds
  */
  LeftWheel.writeMicroseconds(1500 + 10 * ls);
  RightWheel.writeMicroseconds(1500 + -10 * rs);
  delay(d);
}

//helper function used to get the minimum index from a list
int getMax(float* array)
{
  int maxIndex = 0;
  int size = sizeof(array);
  int maximum = array[0];
  for (int i = 0; i < size; i++)
  {
    if (array[i] > maximum) {
      maximum = array[i];
      maxIndex = i;
    }
  }
  return maxIndex;
}

void EscapeBack() {
  //a for loop might be necessary
  Drive (-30, -50, 100);    //Robot should back up in a curve
}

void setup() {
  //initialize camera
  camera.init();

  //Set the initial servo positions:
  LeftWheel.writeMicroseconds(1500);
  RightWheel.writeMicroseconds(1500);

  //Attach the servo objects to the servos on the respective pins
  LeftWheel.attach(leftServoPin);
  RightWheel.attach(rightServoPin);

  //Serial.begin(9600);
}

void loop() {
  cameraColorID();
}

void cameraColorID() {

  uint16_t blocks;
  int targetIndex;
  float targetX;
  float direct;


  LDSensor = analogRead(QREPin);
  int signalLD = map(LDSensor, 900, 1050, 1, 100);
  int test;
  if (signalLD >= 30) {
    test = 0;
    //return FALSE;
    //Serial.println("White tape not detected");
  }
  else if (signalLD < 30) {
    test = 1;
    //return TRUE;
    //Serial.println("White Tape not detected");
  }


  //fetch all color blocks for further processing
  blocks = camera.getBlocks();

  //the largest block will be the target
  float sizes[sizeof(blocks)];

  //use x-coordinate to guide
  float x[sizeof(blocks)];

//  //get all red blocks
//  for (int i = 0; i < sizeof(blocks); i++) {
//    if (test == 1) {
//      test2 = true;
//    }
//    else if(test == 0){
//      test2 = false;
//    }
//  }

  if(test == true){
    //Serial.println("f");
    EscapeBack();
  }
  else if(test == false){
    //Serial.println("t");
    Drive(40, 40, 10);
  }

}

