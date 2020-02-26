void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

int readBitValue(){   // 비트 읽어 0 또는 1 판단
  int count = 0;
  int err = 0;
  
  while(!digitalRead(7)){ // 센서가 high값 출력되는 순간 찾아서
    delayMicroseconds(1);
    count++;
    if( count > 100){
      err = 3;
      break;
    }
  }
  
  if(err==0){
  while(digitalRead(7)){ // high값 유지되는 시간 측정
    delayMicroseconds(1);
    count++;
    if (count > 140){
      err = 4;
      break;
    }
  }
     
  // 70us 이면 1 이고 26~28us 이면 0 이다
  if(err==0){
  if (count > 60)
    return 1;
  else 
    return 0;  
  } else {return err;}//if(err==0)
  }else{return err;}
}

void loop() {
  // put your main code here, to run repeatedly:
int humidity = 0;
int temperature = 0;
int sensorValue[40];

//1. OUTPUT 전환 후 LOW 신호만 주고 딜레이 없어야 함
  delay(2000);
  pinMode(7, OUTPUT);
    
//2. low (0v)로 떨어뜨려 18ms 유지

  digitalWrite(7, LOW);
  delay(18);

//3. 다시 high 로 20~40us 유지. MCU 세팅 완료.

  digitalWrite(7, HIGH);
  delayMicroseconds(30);  // 적당한 값 세팅 필요

//4. input 모드로 dht11 응답 받을 준비

  pinMode(7, INPUT);
  int count = 0;
  int err = 0;
  
  while(!digitalRead(7)){ // 계속 읽다 HIGH, true, 1 인 지점 시작
    count++;
    if(count > 100){
    err = 1;
    break;
    }
  }
                        
  if (err==0){                       

  count = 0;
  while(digitalRead(7)){   // 계속 LOW 인 지점 시작
                          // dht11 값 보내기 시작됨
  count++;
   
    if(count > 100){
      err = 2;
      break;
    }
  }
  if(err==0){
    

    for(int i = 0; i < 40; i++){
      int count_a = 0;
      int count_b = 0;
      while(!digitalRead(7)){
        count_a++;
      }
      while(digitalRead(7)){
        count_b++;
      }
      if(count_b>=16)
      sensorValue[i] = 1;
      if(count_b<=6)
      sensorValue[i] = 0;
    }

  //값 만들기 위한 변수 준비

  byte highHumi = 0;
  for ( int i = 0; i < 8; i++){
    highHumi+=sensorValue[i];
    if(i!=7){
    highHumi = highHumi<<1;  //왼쪽으로 1 bit 밀겠다
  } 
  }
  
  
  
  byte lowHumi = 0;
  for ( int i = 8; i < 16; i++){
    lowHumi+=sensorValue[i];
    if(i!=15){
    lowHumi = lowHumi<<1;  //왼쪽으로 1 bit 밀겠다
  } 
  }
  
  
  
  byte highTemp = 0;
  for ( int i = 16; i < 24; i++){
    highTemp+=sensorValue[i];
    if(i!=23){
    highTemp = highTemp<<1;  //왼쪽으로 1 bit 밀겠다
  } 
  }
  
  

  byte lowTemp = 0;
  for ( int i = 24; i < 32; i++){
    lowTemp+=sensorValue[i];
    if(i!=31){
    lowTemp = lowTemp<<1;  //왼쪽으로 1 bit 밀겠다
  } 
  }
  
 
  
  byte checkSum = 0;
  for ( int i = 32; i < 40; i++){
    checkSum+=sensorValue[0];
    if(i!=39){
    checkSum = checkSum<<1;  //왼쪽으로 1 bit 밀겠다
  }}

  // 온습도 만들기

  humidity = highHumi;
  temperature = highTemp;

 } // if(err==0) 
}
 Serial.print("humi:"); 
 Serial.println(humidity);
 Serial.print("temp:"); 
 Serial.println(temperature);
 Serial.print("error:");
 Serial.println(err);
 
 for(int i=0; i<40; i++){
    if(i%8==0) Serial.print(" ");
    Serial.print(sensorValue[i]);
    
  }
  Serial.println(" "); 
}
