/*
   COGS 220 - Robot Competition
   A mobile robot that can identify colored blocks and pick them up.
*/

//Import libraries
#include <Servo.h>
#include <SPI.h>
#include <Pixy.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"

//Create the servo objects
Servo LeftWheel;
Servo RightWheel;

//Create camera object
Pixy camera;

//Create RGB object
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

//This is used for testing
String readInstructions;



//am I holding a block???
int hold = 0;

//servos
//NOTE: DO NOT USE pin 0 or pin 1
const int leftServoPin = 5;             
const int rightServoPin = 7;            

//LEDs
const int LEDR = A7;
const int LEDG = A6;
const int LEDB = A5;
const int LEDR2 = A4;
const int LEDG2 = A3;
const int LEDB2 = A2;

//arms
Servo LeftArm;
Servo RightArm;
const int larmPin = 8;
const int rarmPin = 9;

void setup() {
   //initialize camera
  camera.init();

  //initialize RGB
  tcs.begin();

  //Set the initial servo positions:
  LeftWheel.writeMicroseconds(1500);
  RightWheel.writeMicroseconds(1500);

  //Set the initial LED configurations;
  setColor(0, 0, 0);
  setColor2(0, 0, 0);

  //set input and output pins
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDR2, OUTPUT);
  pinMode(LEDG2, OUTPUT);
  pinMode(LEDB2, OUTPUT);

  //Attach the servo objects to the servos on the respective pins
  LeftWheel.attach(leftServoPin);
  RightWheel.attach(rightServoPin);
  LeftArm.attach(larmPin);
  RightArm.attach(rarmPin);

  //Setting the Serial Monitor:
  //The Serial Monitor will be used to give commands to the robot and keep track of those commands.
  Serial.begin(9600);

}

void loop() {
  RGBNavigate();
}

//integrated drive-to
//input: one of the ints 1, 2, 3, or 4, representing colors red, green, blue, and yellow respectively
//output: drive towards the specified color
void dt(int cl) {
  
  uint16_t blocks;
  int targetIndex;
  int targetX;
  int direct;
  float w;
  float h;
  float wh;
  int siz;
  //float www;

  //fetch all color blocks for further processing
  blocks = camera.getBlocks();

  //the largest block will be the target
  float sizes[blocks];

  //use x-coordinate to guide
  float x[blocks];

  //float ww[blocks];

  //initialize both sizes and x to be all zeroes
  for (int i = 0; i < blocks; i++) {
    sizes[i] = 0;
    x[i] = 0;
    //ww[i] = 0;
  }

  if (blocks == 0 && hold == 0) {
    randomDrive();
    setColor(0, 0, 0);
  } else if (hold == 1) {
    Drive(30, 30, 1);
  } else {
    //get all blocks of the specified color
    for (int i = 0; i < blocks; i++) {
      w = (float)camera.blocks[i].width;
      h = (float)camera.blocks[i].height;
      siz = (camera.blocks[i].width * camera.blocks[i].height);
      wh = w / h;
      if ((camera.blocks[i].signature == cl) && (wh < 1.2) && (siz < 8000)) {
        sizes[i] = siz;
        x[i] = camera.blocks[i].x;
        //ww[i] = wh;
      }
    }

    targetIndex = getMax(sizes);
    targetX = x[targetIndex];
    direct = targetX - 159;
    //www = ww[getMax(sizes)];

    if (sizes[getMax(sizes)] >= 4000) {
      hold = 1;
    }

    //x ranges between 0 and 319, so midpoint is 159
    //store targetX-159 as reference for Drive()
    if (targetX == 0) {
      randomDrive();
    } else if (direct < 0 && (abs(direct) > 10)) {
      Drive((-direct * 50 / 159), 0, 10);
    } else if (direct > 0 && (abs(direct) > 10)) {
      Drive(0, direct * 50 / 159, 10);
    } else {
      Drive(30, 30, 10);
    }
    
    //set LED color
    switch (cl) {
      case 0:
        setColor(0, 0, 0);
        break;
      case 1: 
        setColor(255, 0, 0);
        break;
      case 2:
        setColor(0, 255, 0);
        break;
      case 3:
        setColor(0, 0, 255);
        break;
      case 4:
        setColor(0, 255, 255);
        break;
    }
  }

void Drive(float ls, float rs, float d) {
  /*
     -50 < ls & rs < 50
     d is in microseconds
  */
  ls = -ls;
  rs = rs;
  LeftWheel.writeMicroseconds(1500 + 10 * ls);
  RightWheel.writeMicroseconds(1500 + 10 * rs);
  delay(d);
  RGB();
}

void RandomDrive(){
  Drive(random(0,50), random(0,50), 10);
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


void RGB() {
  uint16_t clear, red, green, blue;

  tcs.getRawData(&red, &green, &blue, &clear);

  Serial.print("C:\t"); Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print(red);
  Serial.print("\tG:\t"); Serial.print(green);
  Serial.print("\tB:\t"); Serial.print(blue);
  Serial.print("\tS:\t"); Serial.print(current);

  Serial.println();


  if (red > 600 && green < 400 && blue < 400) {
    //setColor2(255, 0, 0);
    previous = current;
    current = RED;
    counter++;
    //randDrive();
  } else if (green > 1000 && red < 1000 && blue < 1000) {
    //setColor2(0, 255, 0);
    previous = current;
    current = GREEN;
    counter++;
    //randDrive();
  } else if (blue > 1000 && red < 1000 && green < 2100) {
    //setColor2(0, 0, 255);
    previous = current;
    current = BLUE;
    counter++;
    //randDrive();
  } else if (red > 1000 && green < 2500 && blue < 1000) {
    //setColor2(255, 255, 0);
    previous = current;
    current = YELLOW;
    counter++;
    //randDrive();
  } else if (red > 1500 && green > 2000 && blue > 1800) {
    setColor2(255, 255, 255);
    EscapeBack();
    counter++;
  }

  if (counter == 1){
    QUADRANT = current;
  }
} 

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

//same as setColor, except it's used for the second LED
void setColor2(int red, int green, int blue)
{
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  analogWrite(LEDR2, red);
  analogWrite(LEDG2, green);
  analogWrite(LEDB2, blue);
}

//rotate 45 degrees
//need to specify parameters by trials and errors
void rotate(){
  Drive(50,-30,1);
}

void RGBRandDrive(){
  int left = random(0,50);
  int right = random(0,50);
  Drive(left, right, 1);
}

//Rotate 90 degrees
void Turn(){
  Drive(50,0,1);
}

//RGB Navigation
int QUADRANT = 0;
int previous = 0;
int current = 0;
int RED = 1;
int GREEN = 2;
int BLUE = 4;
int YELLOW = 3;
int counter = 0;

void setQuadrant(){
    rotate();
    while (QUADRANT == 0){
      Drive(30,30,1);
    }
    //Serial.print("current:\t"); Serial.print(current);
}

int relation(){
  int Direction; //1 = turn right; 2 = turn left;
  if ((previous == RED && current == GREEN) || (previous == GREEN && current = YELLOW) 
  || (previous = YELLOW && current = BLUE) || (previous = BLUE && current = RED){
    return Direction = 1;
  } else return Direction = 2;
}

//setting previous and current states
void RGBNavigate(){
  setQuadrant();
  int color = QUADRANT;
  dt(color);
  
  while (hold == 1){
    if (current = QUADRANT){
      //drop the block
    } else {
      int CurrentCounter = counter;
      while (counter - CurrentCounter == 0){
        RGBRandDrive();
      }
      if (current == QUADRANT){
      //drop the block;
      } else if (previous == QUADRANT){
      Drive(-50,-50,3);
      //drop the block;
      } else if (5 - current == QUADRANT){
        int CurrentCounter = counter;
        if (relation() == 1){
          //turn right twice;
        } else {
          //turn left twice
        }
      } else if (5 - current != QUADRANT){
          if (relation() == 1){
          //turn right once
        } else {
          //turn left once
        }
      }
    }
  }
}


