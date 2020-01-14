void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
int touch = digitalRead(2);
Serial.println(touch);

if(touch==1){
 for(int i = 255; i >= 0; i--){
    
  analogWrite(10, i);
  analogWrite(9, 255);
  analogWrite(8, 255);
  delay(30);
 }
 delay(1);
 for(int i = 255; i >= 0; i--){ 
  analogWrite(9, i);
  analogWrite(8, 255);
  analogWrite(10, 255);
  delay(30); 
 }
 delay(1);
 for(int i = 255; i >= 0; i--){
  analogWrite(8, i);
  analogWrite(9, 255);
  analogWrite(10, 255);
  delay(30);
 }
 delay(1);
 for(int i = 0; i <3; i++){
  
  analogWrite(8, 0);
  analogWrite(9, 0);
  analogWrite(10, 0);
  delay(1000);
  analogWrite(8, 255);
  analogWrite(9, 255);
  analogWrite(10, 255);
  
 }
}
else{
  analogWrite(10, 255);
  analogWrite(9, 255);
  analogWrite(8, 255);
}
  delay(10);
  
  
}
