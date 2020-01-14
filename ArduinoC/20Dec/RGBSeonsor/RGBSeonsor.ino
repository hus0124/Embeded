void setup() {
  Serial.begin(9600);
  pinMode(11,OUTPUT); //green
  pinMode(9,OUTPUT);  //blue
  pinMode(10,OUTPUT); //red
}

void loop() {

  int touch = digitalRead(2); // 2번 포트로 터치 센서
  Serial.println(touch);
  delay(300);

  analogWrite(9,255);
  analogWrite(10,255);
  analogWrite(11,255);
  
  if(touch == 1){
    turnRGB(10, 11, 9);
    delay(500);
    turnRGB(9, 11, 10);
    delay(500);
    turnRGB(11, 9, 10);
    delay(500);
  
    for(int i = 0; i < 3; i++){
      analogWrite(9,0);
      analogWrite(10,0);
      analogWrite(11,0);
      delay(500);
      analogWrite(9,255);
      analogWrite(10,255);
      analogWrite(11,255);
      delay(500);
    }
  }
}

void turnRGB(int a, int b, int c){  //a가 켜질 곳 b c는 나머지
    
  analogWrite(b, 255);
  analogWrite(c, 255);
  for (int i = 255; i > 0; i--){
    analogWrite(a, i);
    delay(30);
  }
   
}
