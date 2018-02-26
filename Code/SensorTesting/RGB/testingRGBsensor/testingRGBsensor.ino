/*
   COGS 220 - Robot Competition
   A mobile robot that can identify colored blocks and pick them up.
*/

//Import Servo library
#include <Servo.h>
#include <SPI.h>
#include <Pixy.h>
#include <avr/sleep.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"

//Create the servo objects
Servo LeftWheel;
Servo RightWheel;
Pixy camera;

String readInstructions;
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

//sensors & servos & LED & switch pins
//NOTE: DO NOT USE pin 0 or pin 1
const int leftServoPin = 6;             //Pin #6
const int rightServoPin = 7;            //Pin #7
//const int QREPin;
const int LEDR = A1;
const int LEDG = A2;
const int LEDB = A3;

void setup() {
  /*
     For continuous servos, the range of values (called microseconds) that the servo will accept is from 1000 to 2000.
     - 1000 is counter-clockwise at full speed
     - 1500 is no movement
     - 2000 is clockwise at full speed
     Right now, the code can only move forwards.
     By the way, auto-indent is Ctrl-t.
  */

  //initialize camera
  camera.init();

  //initialize RGB
  tcs.begin();

  //Set the initial servo positions:
  LeftWheel.writeMicroseconds(1500);
  RightWheel.writeMicroseconds(1500);

  //Set the initial LED configurations;
  setColor(0, 0, 0);

  //set input and output pins
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  //Attach the servo objects to the servos on the respective pins
  LeftWheel.attach(leftServoPin);
  RightWheel.attach(rightServoPin);

  //Setting the Serial Monitor:
  //The Serial Monitor will be used to give commands to the robot and keep track of those commands.
  Serial.begin(9600);
  //Serial.println("Instructions for the Robot: Enter value from 1000 to 2000");
}

void loop() {
  /*
    //Sets up the Serial Monitor
    while(Serial.available()){
    char c = Serial.read();
    readInstructions += c;
    delay(2);
    }

    //
    if(readInstructions.length() > 0){
    //Read the captured String
    Serial.println(readInstructions);
    //Convert from String to int
    int x = readInstructions.toInt();

    //If given proper input for servo microseconds
    if((x >= 1000) && (x <= 2000)){
      Serial.print("Servo Microseconds:");
      Serial.println(x);
      LeftWheel.writeMicroseconds(x);
      RightWheel.writeMicroseconds((2000 - x) + 1000);
    }

    //If given input outside of range
    else{
      Serial.print("Please type in a value that fits within the range of 1000 to 2000");
    }
    }

    //Empty the command line for the next input
    readInstructions = "";
  */

  /*
    //switch the robot on and off
    if (buttonPushed == 1) {
    sleep();
    } else {
    attachInterrupt(0, toggle, LOW);
    }
  */

  dtg();
  //RGB();

}


void RGB() {
  uint16_t clear, red, green, blue;

  tcs.getRawData(&red, &green, &blue, &clear);

  if (red > 6000 && green < 4000 && blue < 4000) {
    setColor(255, 0, 0);
  } else if (green > 10000 && red < 10000 && blue < 10000) {
    setColor(0, 255, 0);
  } else if (blue > 10000 && red < 5000) {
    setColor(0, 0, 255);
  } else if (red > 10000 && green > 10000 && blue < 10000) {
    setColor(255, 255, 0);
  } else if (red > 10000 && green > 10000 && blue > 10000) {
    setColor(255, 255, 255);
  } else {
    setColor(0, 0, 0);
  }
}

void colorCode() {

  uint16_t blocks;

  //fetch all color blocks for further processing
  blocks = camera.getBlocks();

  //get all red blocks
  for (int i = 0; i < sizeof(blocks); i++) {
    if (camera.blocks[i].signature == 10) {
      Serial.print("True");
    }
  }

  delay(200);
}




//Drives towards the closest red block
void dtr() {

  uint16_t blocks;
  int targetIndex;
  float targetX;
  float direct;

  //fetch all color blocks for further processing
  blocks = camera.getBlocks();

  //the largest block will be the target
  float sizes[sizeof(blocks)];

  //use x-coordinate to guide
  float x[sizeof(blocks)];

  //get all red blocks
  for (int i = 0; i < sizeof(blocks); i++) {
    if (camera.blocks[i].signature == 1) {
      sizes[i] = camera.blocks[i].width * camera.blocks[i].height;
      x[i] = camera.blocks[i].x;
    }
  }

  targetIndex = getMax(sizes);
  targetX = x[targetIndex];
  direct = targetX - 165;


  //x ranges between 0 and 329, so midpoint is 165
  //store targetX-165 as reference for Drive()
  if (direct < 0) {
    Drive(0, -direct * 50 / 165, 10);
  } else {
    Drive(direct * 50 / 165, 0, 10);
  }

  //set LED color
  setColor(255, 0, 0);
  Serial.print(direct);
}

//Drives towards the closest green block
void dtg() {

  uint16_t blocks;
  int targetIndex;
  float targetX;
  float direct;

  //fetch all color blocks for further processing
  blocks = camera.getBlocks();

  //the largest block will be the target
  float sizes[sizeof(blocks)];

  //use x-coordinate to guide
  float x[sizeof(blocks)];

  //get all green blocks
  for (int i = 0; i < sizeof(blocks); i++) {
    if (camera.blocks[i].signature == 2) {
      sizes[i] = camera.blocks[i].width * camera.blocks[i].height;
      x[i] = camera.blocks[i].x;
    }
  }

  targetIndex = getMax(sizes);
  targetX = x[targetIndex];

  //x ranges between 0 and 329, so midpoint is 165
  //store targetX-165 as reference for Drive()
  direct = targetX - 165;

  if (direct < 0) {
    Drive(0, -direct * 50 / 165, 10);
  } else {
    Drive(direct * 50 / 165, 0, 10);
  }

  //set LED color
  setColor(0, 255, 0);
}

//Drives towards the closest blue block
void dtb() {

  uint16_t blocks;
  int targetIndex;
  float targetX;
  float direct;

  //fetch all color blocks for further processing
  blocks = camera.getBlocks();

  //the largest block will be the target
  float sizes[sizeof(blocks)];

  //use x-coordinate to guide
  float x[sizeof(blocks)];

  //get all blue blocks
  for (int i = 0; i < sizeof(blocks); i++) {
    if (camera.blocks[i].signature == 3) {
      sizes[i] = camera.blocks[i].width * camera.blocks[i].height;
      x[i] = camera.blocks[i].x;
    }
  }

  targetIndex = getMax(sizes);
  targetX = x[targetIndex];

  //x ranges between 0 and 329, so midpoint is 165
  //store targetX-165 as reference for Drive()
  direct = targetX - 165;

  if (direct < 0) {
    Drive(0, -direct * 50 / 165, 10);
  } else {
    Drive(direct * 50 / 165, 0, 10);
  }

  //set LED color
  setColor(0, 0, 255);
}

//Drives towards the closest yellow block
void dty() {

  uint16_t blocks;
  int targetIndex;
  float targetX;
  float direct;

  //fetch all color blocks for further processing
  blocks = camera.getBlocks();

  //the largest block will be the target
  float sizes[sizeof(blocks)];

  //use x-coordinate to guide
  float x[sizeof(blocks)];

  //get all yellow blocks
  for (int i = 0; i < sizeof(blocks); i++) {
    if (camera.blocks[i].signature == 4) {
      sizes[i] = camera.blocks[i].width * camera.blocks[i].height;
      x[i] = camera.blocks[i].x;
    }
  }

  targetIndex = getMax(sizes);
  targetX = x[targetIndex];

  //x ranges between 0 and 329, so midpoint is 165
  //store targetX-165 as reference for Drive()
  direct = targetX - 165;

  if (direct < 0) {
    Drive(0, -direct * 50 / 165, 10);
  } else {
    Drive(direct * 50 / 165, 0, 10);
  }

  //set LED color
  setColor(255, 255, 0);
}

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
  Drive (-50, -50, 100);
}

//detect Dark vs. Light objects
//lower number (lower than 3000) means light objects
/*
  int readQR(){

  pinMode( QREPin, OUTPUT );
  digitalWrite( QREPin, HIGH );
  delayMicroseconds(10);
  pinMode( QREPin, INPUT );

  long TIME = micros();

  //time how long the input is HIGH, but quit after 3ms.
  while(digitalRead(QREPin) == HIGH && micros() - TIME < 3000) {
    int diff = micros() - TIME;
    printf("HIGH input lasts %d", diff);
    return diff;
  }
  }
*/

//enter color satuations to display different colors
//red = 255, 0 , 0
//green = 0, 255, 0
//blue = 0, 0, 255
//yellow = 255, 255, 0
void setColor(int red, int green, int blue)
{
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  analogWrite(LEDR, red);
  analogWrite(LEDG, green);
  analogWrite(LEDB, blue);
}
