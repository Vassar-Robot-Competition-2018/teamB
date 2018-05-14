const int LinePin = A0;
const int LinePin2 = A1;

//Camera recognnizes blue + Ir activates  = blue
//Camera doesn't recognize rbgy + Ir activates = white

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {

}

void checkBlock(){
  int Line1 = analogRead(LinePin);
  int Line2 = analogRead(LinePin2);
  //Serial.println(Line1);
  //Serial.println(Line2);
  if (Line1 <= 700 || Line2 <= 700){
    hold = 1;
  }
}

