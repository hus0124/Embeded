#include <Servo.h>
#include <HCSR04.h>
Servo myservo; 
HCSR04 hc(5,6); // 5번 trig핀 6번 echo핀

int pushButton = 13;

void setup() {
  Serial.begin(9600);
  myservo.attach(3);  // 모터 3번
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(pushButton, INPUT);
  
}

void loop() {
  Serial.println( hc.dist() );
  delay(300);
  
  if(hc.dist() < 60){
      myservo.write(180);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      delay(1000);
  }    
  else{
      myservo.write(0);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      delay(1000);
  }
//  int buttonState = digitalRead(pushButton);
//  Serial.println(buttonState);
//  delay(1);
    
}
