/*
   COGS 220 - Robot Competition
   A mobile robot that can identify colored blocks and pick them up.
*/

//Import Servo library
#include <Servo.h>

//Create the servo objects
Servo LeftWheel;
Servo RightWheel;

String readInstructions;

//Variables that store the servo pins
const int leftServoPin = 6;             //Pin #6
const int rightServoPin = 7;            //Pin #7

void setup() {
  /*
     For continuous servos, the range of values (called microseconds) that the servo will accept is from 1000 to 2000.
     - 1000 is counter-clockwise at full speed
     - 1500 is no movement
     - 2000 is clockwise at full speed

     Right now, the code can only move forwards.
     By the way, auto-indent is Ctrl-t.
  */

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


