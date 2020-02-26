#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13, OUTPUT);
BTSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
while(BTSerial.available()){
  byte data = BTSerial.read();
  Serial.write(data);
  
  if(data=='1'){
    digitalWrite(13, HIGH);
  }
  else if(data=='0'){
    digitalWrite(13, LOW);
  }
}

while(Serial.available()){
  byte data = Serial.read();
  BTSerial.write(data);
  
  if(data=='1'){
    digitalWrite(13, HIGH);
  }
  else if(data=='0'){
    digitalWrite(13, LOW);
  }
}
}
