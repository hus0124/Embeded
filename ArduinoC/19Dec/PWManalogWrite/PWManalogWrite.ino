

void setup() {
  // put your setup code here, to run once:
pinMode(3, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

for(int i = 0; i < 256; i++){
  analogWrite(3,i);
  analogWrite(9,i);
  analogWrite(10,i);
  analogWrite(11,i);
  delay(30);
}
for(int i= 255; i >= 0; i--){
  analogWrite(3,i);
  analogWrite(9,i);
  analogWrite(10,i);
  analogWrite(11,i);
  delay(30);
}
}
