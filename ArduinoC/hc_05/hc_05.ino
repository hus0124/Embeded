#include <SoftwareSerial.h>
//HC-05 AT MODE
SoftwareSerial BTSerial(2, 3);   //bluetooth module Tx: Digital 2 Rx: Digital 3

void setup() {
 
  Serial.begin(9600);  // 시리얼 모니터 보드레이트 값
  BTSerial.begin(9600); // HC-05의 보드레이트 기본값
 
}

void loop() {
  if (BTSerial.available())
    Serial.write(BTSerial.read());
  if (Serial.available())
    BTSerial.write(Serial.read());
 
}
