int IRSensorPin = 4;

void setup() {
  Serial.begin(9600);

}

void loop() {
  CheckObject();
  if (CheckObject == TRUE) {
    //
  }
}

int CheckObject(){
  int val = digitalRead(IRSensorPin);
  if (val == 1) {
    return TRUE;
  } else return FALSE;
}

