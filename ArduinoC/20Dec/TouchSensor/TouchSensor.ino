void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {
  int touch = digitalRead(2);
  Serial.println(touch);
  delay(500);

  if (touch==1)
  {
    hus(9,10,11);
  }

  delay(10);
}


void hus(int a, int b, int c){
  Serial.println("Start");
  int randnum;
  for(int j = 0; j < 5; j++){     //5번 fade
    for(int i = 0; i < 256; i++){ 
      analogWrite(a,i);
      analogWrite(b,i);
      analogWrite(c,i);
      delay(10); 
    }
  } 
  delay(100);


  
  for(int i = 0; i < 10; i++){ //10번 a,b,c 순서대로 in out
    digitalWrite(a, HIGH);
    delay(300);
    digitalWrite(b, HIGH);
    delay(300);
    digitalWrite(c, HIGH);
    delay(300);
    digitalWrite(a, LOW);
    delay(300);
    digitalWrite(b, LOW);
    delay(300);
    digitalWrite(c, LOW);
    delay(30);
  }

  delay(100);
  

  
  for(int i = 0; i < 20; i++){ //20번 
    randnum = random(3);  // 0~2 랜덤 선택.
    if(randnum == 0){     // a b c 순서 점멸
      digitalWrite(a, HIGH);
      delay(100);
      digitalWrite(a, LOW);
      delay(100);
      digitalWrite(b, HIGH);
      delay(100);
      digitalWrite(b, LOW);
      delay(100);
      digitalWrite(c, HIGH);
      delay(100);
      digitalWrite(c, LOW);
      delay(100);
    }
    else if(randnum == 1){  // b c a 순서 점멸
      digitalWrite(b, HIGH);
      delay(100);
      digitalWrite(b, LOW);
      delay(100);
      digitalWrite(c, HIGH);
      delay(100);
      digitalWrite(c, LOW);
      delay(100);
      digitalWrite(a, HIGH);
      delay(100);
      digitalWrite(a, LOW);
      delay(100);
    }

    else{                   // c a b 순서 점멸 
      digitalWrite(c, HIGH);
      delay(100);
      digitalWrite(c, LOW);
      delay(100);
      digitalWrite(a, HIGH);
      delay(100);
      digitalWrite(a, LOW);
      delay(100);
      digitalWrite(b, HIGH);
      delay(100);
      digitalWrite(b, LOW);
      delay(100);
    }
  }
  Serial.println("End");
}
