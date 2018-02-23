const int pin = A0;

//Camera recognnizes blue + Ir activates  = blue
//Camera doesn't recognize rbgy + Ir activates = white

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor = analogRead(pin);
  //Serial.println(sensor);

  int test = map(sensor, 900, 1050, 1, 100);

  if(test >= 60){
    Serial.println("T");
  }
  else if(test < 60){
    Serial.println("F");
  }
  
  //Serial.println(test);
  /*Serial.println(test);
  if (test >= 85) {
    Serial.println("no border");
  }
  else if (test < 85) {
    Serial.println("border");
  }
  */

}
