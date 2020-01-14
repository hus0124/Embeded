void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

int groundsensor = analogRead(0);
Serial.print("토질 측정:");
Serial.println(groundsensor);
delay(500);

if(groundsensor < 700){
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
}
else{
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}
}
