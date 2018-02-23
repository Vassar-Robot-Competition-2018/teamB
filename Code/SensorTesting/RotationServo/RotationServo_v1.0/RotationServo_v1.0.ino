//Web Page
//https://www.zipwhip.com/blog/manual-control-of-a-servo-on-the-arduino-for-the-zipwhip-textspresso-machine/

int ROTATION_PIN = 5;

int lenPeriod = 20 * 1000;
int lenPulse = 0;
int lenPulseStart;
int lenPulseEnd = 2.0 * 1000;
int lenPulseStep = 0.01 * 1000;

String readInstructions;

void setup() {
  pinMode(ROTATION_PIN, OUTPUT);
  lenPulse = lenPulseStart + lenPulseStep;
  Serial.begin(9600);
}

/*
void loop() {
  while(Serial.available()) {
    char c = Serial.read();
    readInstructions += c;
    delay(2);
  }
  Serial.println(readInstructions);
  int x = readInstructions.toInt();
  Angle(x);
  readInstructions = "";
}
*/

void loop () {
  while(Serial.available()){
    readInstructions = Serial.readString();
    Serial.println(readInstructions);
    lenPulseStart = readInstructions.toInt();
    lenPulse += lenPulseStep;
    
    while (lenPulse = lenPulseStart) {
      digitalWrite(ROTATION_PIN, HIGH);
      delayMicroseconds(lenPulseEnd - lenPulseStart);
      digitalWrite(ROTATION_PIN, LOW);
      delayMicroseconds(lenPeriod - lenPulseEnd);
    }
  
    lenPulseStep = lenPulseStep * -1;
    lenPulse += lenPulseStep;
    
    delay(2 * 1000);
  }
}
