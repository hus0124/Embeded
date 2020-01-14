void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int soundsensor = analogRead(0);
  Serial.println(soundsensor);
  delay(500);

  
}
