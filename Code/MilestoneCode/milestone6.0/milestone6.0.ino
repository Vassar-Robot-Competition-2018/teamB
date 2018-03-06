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

//sensors & servos & LED & switch pins
//NOTE: DO NOT USE pin 0 or pin 1
const int leftServoPin = 6;             //Pin #6
const int rightServoPin = 7;            //Pin #7
//const int QREPin;
const int LEDR = A7;
const int LEDG = A6;
const int LEDB = A5;
const int LEDR2 = A4;
const int LEDG2 = A3;
const int LEDB2 = A2;

int PREVIOUS =100;
int STATE = 100;
const int STATE_RED = 101;
const int STATE_GREEN = 102;
const int STATE_YELLOW = 103;
const int STATE_BLUE = 104;
const int STATE_WHITE = 105;
const int STATE_NULL = 106;

int counter = 0;

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
  pinMode(LEDR2, OUTPUT);
  pinMode(LEDG2, OUTPUT);
  pinMode(LEDB2, OUTPUT);

  setColor2(STATE_NULL);

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

   
    //Drive(50,50,1);
    RGB();
    
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
      Drive(0, direct * 50/159, 1);
    } else if (direct < 0 && (abs(direct) > 10)) {
      Drive((-direct * 50/159), 0, 1);
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

  if (blocks == 0) {
    randomDrive();
    setColor(0, 0, 0);
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
      Drive(0, 0, 1000);
    }

    //x ranges between 0 and 319, so midpoint is 159
    //store targetX-159 as reference for Drive()
    if (direct > 0 && (abs(direct) > 10)) {
      Drive(0, direct * 50/159, 1);
    } else if (direct < 0 && (abs(direct) > 10)) {
      Drive((-direct * 50/159), 0, 1);
    } else {
      Drive(30, 30, 1);
    }
    //set LED color
    setColor(0, 255, 0); 
  }
  
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
  Serial.println();
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
      Drive(0, direct * 50/159, 1);
    } else if (direct < 0 && (abs(direct) > 10)) {
      Drive((-direct * 50/159), 0, 1);
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
      Drive(0, direct * 50/159, 1);
    } else if (direct < 0 && (abs(direct) > 10)) {
      Drive((-direct * 50/159), 0, 1);
    } else {
      Drive(30, 30, 1);
    }
    //set LED color
    setColor(0, 255, 255); 
  }
  
}

void Drive(float ls, float rs, float d) {
  /*
   * -50 < ls & rs < 50
   * d is in microseconds
   */
   ls = -ls;
   rs = rs;
   LeftWheel.writeMicroseconds(1500 + 10 * ls);
   RightWheel.writeMicroseconds(1500 + 10 * rs);
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

void randomDrive() {
  Drive(random(0, 25), random(0, 25), 10);
}

void randomDrive2() {
  Drive(30, random(0, 50), 10);
}

void EscapeBack(){
  Drive(-50, -50, 100);
  //turn a random degree to avoid hitting into the edge again
  int rand = random(0, 50);
  Drive(rand, -rand, 100);
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

void RGB() {
  while (counter < 3) {
    uint16_t clear, red, green, blue;
    tcs.getRawData(&red, &green, &blue, &clear);

    randomDrive2();
    
    Serial.print("C:\t"); Serial.print(clear);
    Serial.print("\tR:\t"); Serial.print(red);
    Serial.print("\tG:\t"); Serial.print(green);
    Serial.print("\tB:\t"); Serial.print(blue);
    Serial.print("\tState:\t"); Serial.print(STATE);
    Serial.print("\tCounter:\t"); Serial.print(counter);
    //Serial.println();
    //delay(60);
    if (red > 1100 && green < 700 && blue < 700) {
      setState(255, 0, 0);
      //setColor2(STATE_RED);
      Serial.print("\tCounter:\t"); Serial.print(counter);
      if (STATE != PREVIOUS) counter++;
    } else if (green > 2400 && red < 2000 && blue < 2000) {
      setState(0, 255, 0);
      //setColor2(STATE_GREEN);
      Serial.print("\tCounter:\t"); Serial.print(counter);
      if (STATE != PREVIOUS) counter++;
    } else if (blue > 2000 && red < 1500 && green < 3100) {
      setState(0, 0, 255);
      //setColor2(STATE_BLUE);
      if (STATE != PREVIOUS) counter++;
    } else if (red > 2000 && green < 4000 && blue < 2000) {
      setState(255, 255, 0);
      //setColor2(STATE_YELLOW);
      if (STATE != PREVIOUS) counter++;
    } else if (red > 3000 && green > 4000 && blue > 4000) {
      setColor2(STATE_WHITE);
      EscapeBack();
    }
    
    while (counter = 2) {
      //Serial.print("\tCounter:\t"); Serial.print(counter);
      //Serial.println("\tState:\t"); Serial.print(STATE);
      setColor2(STATE);
    }
  }
  
  if (counter == 3) {
    randomDrive2();
    setColor2(STATE);
    counter = 1;
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

void setColor2(int STATE) {
  int red = 0;
  int green = 0;
  
  int blue = 0;
  if (STATE == STATE_RED) {
    red = 255;
  } else if (STATE == STATE_GREEN) {
    green = 255;
  } else if (STATE == STATE_BLUE) {
    blue = 255;
  } else if (STATE == STATE_YELLOW) {
    red = 255;
    green = 255;
  } else if (STATE == STATE_WHITE) {
    red = 255;
    green = 255;
    blue = 255;
  } else if (STATE == STATE_NULL) {
    red = 0;
    green = 0;
    blue = 0;
  }
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  analogWrite(LEDR2, red);
  analogWrite(LEDG2, green);
  analogWrite(LEDB2, blue); 
}

//red = 255, 0 , 0
//green = 0, 255, 0
//blue = 0, 0, 255
//yellow = 255, 255, 0
//white = 255,255,255

void setState (int red, int green, int blue) {
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  if (red == 0 && green == 0 && blue != 0) {
    PREVIOUS = STATE;
    STATE = STATE_YELLOW;
  } else if (red == 0) {
    PREVIOUS = STATE;
    STATE = STATE_RED;
  } else if (green == 0) { 
    PREVIOUS = STATE;
    STATE = STATE_GREEN;
  } else if (blue == 0) {
    PREVIOUS = STATE;
    STATE = STATE_BLUE;
  } else if (red == 0 && green == 0 && blue == 0){
    PREVIOUS = STATE;
    STATE = STATE_WHITE;
  }
}
