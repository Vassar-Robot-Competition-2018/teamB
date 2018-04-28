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

//Saves the current color RGB sees
int current = 0;

//am I holding a block???
int hold = 0;

//which quadrant did i start in???
int qua = 0;

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

//internal map variables
//Drive(10, 10, 10) = 6.1cm;
//Drive(1, 1, 1) = 0.061cm
const float unit = 0.061;
//width of body = 12.0cm
const float L = 12.0 / unit;
const float time_for_one_turn = L * PI;
//these will be reset every 50 counts
unsigned int timer = 0;
long ticks1 = 0; //left wheel
long ticks2 = 0; //right wheel
//cartesian coordinates tracking the location of robot, updated every 50 counts
double xPos = 0.0;
double yPos = 0.0;
//direction the head is pointing to, ranges from 0 to 2PI, increasing clockwise, used to update xPos and yPos
float directionTrack = 7*PI/4;
int amIHome = 1;

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
    while(start = 0) {
    Drive(50, 50, 1);
    uint16_t clear, red, green, blue;
    tcs.getRawData(&red, &green, &blue, &clear);
    if (red > 1500 && green < 1500 && blue < 1500) {
      setColor2(255, 0, 0);
      start = 1;
    } else if (green > 4000 && red < 4000 && blue < 3000) {
      setColor2(0, 255, 0);
      start = 2;
    } else if (blue > 3000 && red < 2000 && green < 4500) {
      setColor2(0, 0, 255);
      start = 3;
    } else if (red > 4000 && green > 3500 && blue < 3000) {
      setColor2(255, 255, 0);
      start = 4;
    } else if (red > 4000 && green > 4500 && blue > 4000) {
      setColor2(255, 255, 255);
      EscapeBack();
    }
    Serial.println("Meh");
    }*/

  testDrive();
  if(amIHome == 0) {
    homing();
  }
}

void testDrive() {
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(20, 40, 1);
  Drive(20, 40, 1);
  Drive(20, 40, 1);
  Drive(20, 40, 1);
  Drive(20, 40, 1);
  Drive(20, 40, 1);
  Drive(20, 40, 1);
  Drive(20, 40, 1);
  Drive(20, 40, 1);
  Drive(20, 40, 1);
  Drive(30, 20, 1);
  Drive(30, 20, 1);
  Drive(30, 20, 1);
  Drive(30, 20, 1);
  Drive(30, 20, 1);
  Drive(30, 20, 1);
  Drive(30, 20, 1);
  Drive(30, 20, 1);
  Drive(30, 20, 1);
  Drive(30, 20, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  Drive(50, 50, 1);
  amIHome = 0;
}

void homing() {
  float a, b, t;
  a = tanh(yPos/xPos);
  b = ((3*PI)/2) - a - directionTrack;
  t = time_for_one_turn * (b/(2*PI));
  Drive(50, -50, t);
  while(1) {
    Drive(0, 0, 1);
  }
}

void internalMapInc() {
  float angle = 0.0;
  //every 50 counts update location information
  if (timer >= 50) {
    angle = directionTrack - ((ticks2 - ticks1) / (2*L));
    if (angle < 0.0) {
      angle = angle + (2*PI);
    } else if (angle >= (2*PI)) {
      angle = angle - (2*PI);
    }
    
    //update xPos and yPos
    if (ticks2 > ticks1) {
      xPos = xPos + (((2*L*ticks1) / (ticks2 - ticks1)) + L) * sin((ticks2 - ticks1) / (4*L)) * cos(angle);
      yPos = yPos + (((2*L*ticks1) / (ticks2 - ticks1)) + L) * sin((ticks2 - ticks1) / (4*L)) * sin(angle);
    } else if (ticks1 > ticks2) {
      xPos = xPos + (((2*L*ticks2) / (ticks1 - ticks2)) + L) * sin((ticks1 - ticks2) / (4*L)) * cos(angle);
      yPos = yPos + (((2*L*ticks2) / (ticks1 - ticks2)) + L) * sin((ticks1 - ticks2) / (4*L)) * sin(angle);
    } else if (ticks1 == ticks2) {
      xPos = xPos + ticks1 * cos(angle);
      yPos = yPos + ticks1 * sin(angle);
    }

    //update directionTrack
    directionTrack = directionTrack - (ticks2 - ticks1) / L;
    if (directionTrack < 0.0) {
      directionTrack = directionTrack + (2*PI);
    } else if (directionTrack >= (2*PI)) {
      directionTrack = directionTrack - (2*PI);
    }
    
    //reset ticks and timer
    ticks1 = 0;
    ticks2 = 0;
    timer = 0;
  }
}

void disp() {
  if (current == 1) {
    setColor2(255, 0, 0);
  } else if (current == 2) {
    setColor2(0, 255, 0);
  } else if (current == 3) {
    setColor2(0, 0, 255);
  } else if (current == 4) {
    setColor2(255, 255, 0);
  } else {
    setColor2(0, 0, 0);
  }
}


void RGB() {
  uint16_t clear, red, green, blue;

  tcs.getRawData(&red, &green, &blue, &clear);

  /*
  Serial.print("C:\t"); Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print(red);
  Serial.print("\tG:\t"); Serial.print(green);
  Serial.print("\tB:\t"); Serial.print(blue);
  Serial.print("\tS:\t"); Serial.print(current);

  Serial.println();
  */

  if (red > 600 && green < 400 && blue < 400) {
    //setColor2(255, 0, 0);
    previous = current;
    current = 1;
    if (qua == 0) {
      qua = 1;
      previous = 1
      amIHome = 0;
    }
    //randDrive();
  } else if (green > 1000 && red < 1000 && blue < 700) {
    //setColor2(0, 255, 0);
    current = 2;
    if (qua == 0) {
      qua = 2;
      previous = 2
      amIHome = 0;
    }
    //randDrive();
  } else if (blue > 1000 && red < 1000 && green < 2100) {
    //setColor2(0, 0, 255);
    current = 3;
    if (qua == 0) {
      qua = 3;
      previous = 3
      amIHome = 0;
    }
    //randDrive();
  } else if (red > 1000 && green < 2500 && blue < 800) {
    //setColor2(255, 255, 0);
    current = 4;
    if (qua == 0) {
      qua = 4;
      previous = 4
      amIHome = 0;
    }
    //randDrive();
  } else if (red > 1400 && green > 1400 && blue > 1300) {
    EscapeBack();
  } //else {
  //setColor2(0, 0, 0);
  //}

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
    /*
    Serial.print("Direct:\t");
    Serial.print(direct);
    Serial.print("\t\t");
    Serial.print("targetX:\t");
    Serial.print(targetX);
    Serial.print("\t\t");
    Serial.print("Area:\t");
    Serial.print(sizes[targetIndex]);
    Serial.print("\t\t");
    Serial.print("blocks\t:");
    Serial.print(blocks);
    Serial.print("\t\t");
    Serial.print("hold\t:");
    Serial.print(hold);
    Serial.print("\t\t");
    Serial.print("www\t:");
    Serial.print(www);
    Serial.println();
    */    
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
  float sizes[blocks];

  //use x-coordinate to guide
  float x[blocks];

  if (blocks == 0) {
    randomDrive();
    setColor(0, 0, 0);
  } else {
    //initialize both sizes and x to be all zeroes
    for (int i = 0; i < blocks; i++) {
      sizes[i] = 0;
      x[i] = 0;
    }

    //get all red blocks
    for (int i = 0; i < blocks; i++) {
      if (camera.blocks[i].signature == 1) {
        sizes[i] = camera.blocks[i].width * camera.blocks[i].height;
        x[i] = camera.blocks[i].x;
      }
    }

    targetIndex = getMax(sizes);
    targetX = x[targetIndex];
    direct = targetX - 159;

    //x ranges between 0 and 319, so midpoint is 159
    //store targetX-159 as reference for Drive()
    if (direct > 0 && (abs(direct) > 10)) {
      Drive(0, direct * 50 / 159, 1);
    } else if (direct < 0 && (abs(direct) > 10)) {
      Drive((-direct * 50 / 159), 0, 1);
    } else {
      Drive(30, 30, 1);
    }
    //set LED color
    setColor(255, 0, 0);
  }

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
  float sizes[blocks];

  //use x-coordinate to guide
  float x[blocks];

  if (blocks == 0 && hold == 0) {
    randomDrive();
    setColor(0, 0, 0);
  } else if (hold == 1) {
    Drive(30, 30, 1);
  } else {
    //initialize both sizes and x to be all zeroes
    for (int i = 0; i < blocks; i++) {
      sizes[i] = 0;
      x[i] = 0;
    }

    //get all green blocks
    for (int i = 0; i < blocks; i++) {
      if (camera.blocks[i].signature == 2) {
        sizes[i] = camera.blocks[i].width * camera.blocks[i].height;
        x[i] = camera.blocks[i].x;
      }
    }

    

    targetIndex = getMax(sizes);
    targetX = x[targetIndex];
    direct = targetX - 159;

    if (sizes[getMax(sizes)] >= 10000) {
      hold = 1;
    }

    //x ranges between 0 and 319, so midpoint is 159
    //store targetX-159 as reference for Drive()
    if (direct < 0 && (abs(direct) > 10)) {
      Drive((-direct * 50 / 159), 0, 1);
    } else if (direct > 0 && (abs(direct) > 10)) {
      Drive(0, direct * 50 / 159, 1);
    } else {
      Drive(30, 30, 1);
    }

    //set LED color
    setColor(0, 255, 0);

  }
    /*
    Serial.print("Direct:\t");
    Serial.print(direct);
    Serial.print("\t\t");
    Serial.print("targetX:\t");
    Serial.print(targetX);
    Serial.print("\t\t");
    Serial.print("Area:\t");
    Serial.print(sizes[targetIndex]);
    Serial.print("\t\t");
    Serial.print("blocks\t:");
    Serial.print(blocks);
    Serial.print("\t\t");
    Serial.print("hold\t:");
    Serial.print(hold);
    Serial.println();
    */
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
  float sizes[blocks];

  //use x-coordinate to guide
  float x[blocks];

  if (blocks == 0) {
    randomDrive();
    setColor(0, 0, 0);
  } else {
    //initialize both sizes and x to be all zeroes
    for (int i = 0; i < blocks; i++) {
      sizes[i] = 0;
      x[i] = 0;
    }

    //get all blue blocks
    for (int i = 0; i < blocks; i++) {
      if (camera.blocks[i].signature == 3) {
        sizes[i] = camera.blocks[i].width * camera.blocks[i].height;
        x[i] = camera.blocks[i].x;
      }
    }

    targetIndex = getMax(sizes);
    targetX = x[targetIndex];
    direct = targetX - 159;

    //x ranges between 0 and 319, so midpoint is 159
    //store targetX-159 as reference for Drive()
    if (direct > 0 && (abs(direct) > 10)) {
      Drive(0, direct * 50 / 159, 1);
    } else if (direct < 0 && (abs(direct) > 10)) {
      Drive((-direct * 50 / 159), 0, 1);
    } else {
      Drive(30, 30, 1);
    }
    //set LED color
    setColor(0, 0, 255);
  }

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
  float sizes[blocks];

  //use x-coordinate to guide
  float x[blocks];

  if (blocks == 0) {
    randomDrive();
    setColor(0, 0, 0);
  } else {
    //initialize both sizes and x to be all zeroes
    for (int i = 0; i < blocks; i++) {
      sizes[i] = 0;
      x[i] = 0;
    }

    //get all yellow blocks
    for (int i = 0; i < blocks; i++) {
      if (camera.blocks[i].signature == 4) {
        sizes[i] = camera.blocks[i].width * camera.blocks[i].height;
        x[i] = camera.blocks[i].x;
      }
    }

    targetIndex = getMax(sizes);
    targetX = x[targetIndex];
    direct = targetX - 159;

    //x ranges between 0 and 319, so midpoint is 159
    //store targetX-159 as reference for Drive()
    if (direct > 0 && (abs(direct) > 10)) {
      Drive(0, direct * 50 / 159, 1);
    } else if (direct < 0 && (abs(direct) > 10)) {
      Drive((-direct * 50 / 159), 0, 1);
    } else {
      Drive(30, 30, 1);
    }
    //set LED color
    setColor(0, 255, 255);
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
  RightWheel.writeMicroseconds(1500 + 9.6 * rs);
  delay(d*100);
  timer = timer + d;
  ticks1 = ticks1 + ls * d;
  ticks2 = ticks2 + rs * d;
  internalMapInc();
  Serial.print(amIHome);
  Serial.print("\t");
  Serial.print(timer);
  Serial.print("\t");
  Serial.print(xPos);
  Serial.print("\t");
  Serial.print(yPos);
  Serial.print("\t");
  Serial.print(directionTrack);
  Serial.print("\t");
  Serial.print(ticks1);
  Serial.print("\t");
  Serial.print(ticks2);
  Serial.println();
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

void randomDrive() {
  Drive(random(0, 50), random(0, 50), 10);
}

void EscapeBack() {
  setColor2(255, 255, 255);
  hold = 0;
  Drive(-30, -30, 50);
  //turn a random degree to avoid hitting into the edge again
  int rand = 25;
  Drive(rand, -rand, 50);
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



