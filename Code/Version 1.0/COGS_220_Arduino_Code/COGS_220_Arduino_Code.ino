/*
   COGS 220 - Robot Competition
   A mobile robot that can identify colored blocks and pick them up.
*/

//Import Servo library
#include <Servo.h>
#include <SPI.h>
#include <Pixy.h>

//Create the servo objects
Servo LeftWheel;
Servo RightWheel;
Pixy camera;

String readInstructions;

//Variables that store the servo pins
const int leftServoPin = 6;             //Pin #6
const int rightServoPin = 7;            //Pin #7
const int lineSensor = 5;

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
  Pixy.init();

  //Set the initial servo positions:
  LeftWheel.writeMicroseconds(1500);
  RightWheel.writeMicroseconds(1500);


  //Attach the servo objects to the servos on the respective pins
  LeftWheel.attach(leftServoPin);
  RightWheel.attach(rightServoPin);

  //Setting the Serial Monitor:
  //The Serial Monitor will be used to give commands to the robot and keep track of those commands.
  Serial.begin(9600);
  Serial.println("Instructions for the Robot: Enter value from 1000 to 2000");
}


void loop() {

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

    //Empty the command line for the next input
    readInstructions = "";
  }
}

//Drives towards the closest red block
void dtr() {
  
  //fetch all color blocks for further processing
  blocks = camera.getBlocks();

  //the largest block will be the target
  float sizes[];

  //use x-coordinate to guide
  float x[];

  //get all red blocks
  for (int i = 0; i < sizeOf(blocks); i++) {
    if (camera.blocks[i].signature == 1) {
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
    Drive(0, -direct/50, 10);
  } else {
    Drive(direct/50, 0, 10);
  }
}

//Drives towards the closest green block
void dtg() {
  
  //fetch all color blocks for further processing
  blocks = camera.getBlocks();

  //the largest block will be the target
  float sizes[];

  //use x-coordinate to guide
  float x[];

  //get all green blocks
  for (int i = 0; i < sizeOf(blocks); i++) {
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
    Drive(0, -direct/50, 10);
  } else {
    Drive(direct/50, 0, 10);
  }
}

//Drives towards the closest blue block
void dtb() {
  
  //fetch all color blocks for further processing
  blocks = camera.getBlocks();

  //the largest block will be the target
  float sizes[];

  //use x-coordinate to guide
  float x[];

  //get all blue blocks
  for (int i = 0; i < sizeOf(blocks); i++) {
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
    Drive(0, -direct/50, 10);
  } else {
    Drive(direct/50, 0, 10);
  }
}

//Drives towards the closest yellow block
void dty() {
  
  //fetch all color blocks for further processing
  blocks = camera.getBlocks();

  //the largest block will be the target
  float sizes[];

  //use x-coordinate to guide
  float x[];

  //get all yellow blocks
  for (int i = 0; i < sizeOf(blocks); i++) {
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
    Drive(0, -direct/50, 10);
  } else {
    Drive(direct/50, 0, 10);
  }
}

void detectWhite() {
  if (lineSensor.digitalRead() == HIGH) {
    Drive(-50, -50, 1);
  }
}

void Drive(float ls, float rs, float d) {
  /*
   * -50 < ls & rs < 50
   * d is in microseconds
   */
   LeftWheel.writeMicroseconds(1500 + 10 * ls);
   RightWheel.writeMicroseconds(1500 + 10 * ls);
   delay(d);
}

//helper function used to get the minimum index from a list
int getMax(int* array)
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
