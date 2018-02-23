//https://github.com/adafruit/Adafruit_TCS34725/blob/master/examples/colorview/colorview.ino

#include <Wire.h>
#include "Adafruit_TCS34725.h"


byte gammatable[256];

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
//  pinMode(SDA, OUTPUT);
//  pinMode(SCL, OUTPUT);
//  pinMode(sensorOut, INPUT);
  Serial.begin(9600);
  Serial.println("Color Test!");
  if (tcs.begin()){
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }

  //gamma table
  for (int i=0; i<256; i++) {
  float x = i;
  x /= 255;
  x = pow(x, 2.5);
  x *= 255;
    
  if (true) {
    gammatable[i] = 255 - x;
    } else {
      gammatable[i] = x;      
    }
    Serial.println(gammatable[i]);
  }
}

void loop() {
  uint16_t clearfilter, red, green, blue;
  delay(60);
  tcs.getRawData(&red,&green,&blue,&clearfilter);
  
  Serial.print("C:\t"); Serial.print(clearfilter);
  Serial.print("\tR:\t"); Serial.print(red);
  Serial.print("\tG:\t"); Serial.print(green);
  Serial.print("\tB:\t"); Serial.print(blue);

  uint32_t sum = clearfilter;
  float r, g, b;
  r = red / sum;
  g = green / sum;
  b = blue / sum;
  r *= 256; g *= 256; b *= 256;
  Serial.print("\t");
  Serial.print((int)r, HEX); Serial.print((int)g, HEX); Serial.print((int)b, HEX);
  Serial.println();
  Serial.print((int)r ); Serial.print(" "); Serial.print((int)g);Serial.print(" ");  Serial.println((int)b );
  
  delay(1000);
}
