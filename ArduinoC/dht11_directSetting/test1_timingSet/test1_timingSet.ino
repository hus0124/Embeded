void setup() {
  Serial.begin(9600);

}

void loop() {
  delay(2000); //2초마다 테스트
  int value[80];
  pinMode(7, OUTPUT);
  digitalWrite(7,LOW);
  delay(18);
  digitalWrite(7,HIGH);
  delayMicroseconds(30);
  
  pinMode(7, INPUT); //data 읽기
  int count=0;
  while(!digitalRead(7)){ // high값 80us 후
    count++;
  }
  count=0;
  while(digitalRead(7)){ // low값 50us 지속 후 dht11 응답 시작된다
    count++;
  }
  //data 보내기 시작
   for(int i=0; i<8; i++){
    count=0;
    while(!digitalRead(7)){ //low 값길이
      count++;
    }
    value[i*2]=count;
    count=0;
    while(digitalRead(7)){ //high 값길이.
      count++;
    }
    value[i*2+1]=count; // 홀수 번째 숫자 보고 0 아니면 1 판별 .
                        // count 5 or 6은 0비트 의미.  16, 17은 1비트 의미.
  }
  for(int i=0; i<16; i++){
    Serial.print(value[i]);Serial.print(" ");
  }
   Serial.println(""); 

  
}
