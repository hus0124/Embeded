#include <HCSR04.h>

HCSR04 hc(5,6);//initialisation class HCSR04 (trig pin , echo pin)

void setup()
{ Serial.begin(9600); 
  pinMode(2, OUTPUT); // 소리 부저음 연결
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{ Serial.println( hc.dist() ); // hc.dist() 가 거리센서 함수
  delay(300);
  
  if(hc.dist() < 10){
    for(int i=8;i<=11;i++){
      digitalWrite(i, HIGH);
      delay(300);
      digitalWrite(i, LOW);
      delay(300);
    }
  float value = hc.dist(); // 거리값 저장
    
    digitalWrite(2, HIGH);
    delay(value*10);  // 거리가 길면 천천히 울리고 짧으면 빨리 울리게 함.
    digitalWrite(2, LOW);
    delay(value*10);
  

}//return curent distance in serial
}
