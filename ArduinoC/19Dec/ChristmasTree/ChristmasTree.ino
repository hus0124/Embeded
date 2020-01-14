void setup() {
  

}

void loop() {
  

}

void hus(int a, int b, int c){
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
}
