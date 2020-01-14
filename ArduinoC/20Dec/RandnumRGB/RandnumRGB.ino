void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(11,OUTPUT); //green
  pinMode(9,OUTPUT);  //blue
  pinMode(10,OUTPUT); //red
}

void loop() {
  // put your main code here, to run repeatedly:


 Serial.println("method 9 Start"); 
    turnRGB(9); //파랑 변화   
  
 Serial.println("method 10 Start"); 
    turnRGB(10);  // 빨강변화
    
 Serial.println("method 11 Start"); 
  
    turnRGB(11);  // 녹색변화
}

void turnRGB(int a){  //a가 켜질 곳. 랜덤 작동
 
 int randnum = random(2);
 Serial.println(randnum);
 if(randnum == 0){  // 점점 켜짐
   for (int i = 255; i >= 0; i--){
    analogWrite(a, i);
    delay(30);
   }
 }
 else {// randnum 1일 때 점점 꺼짐
   for (int i = 0; i < 256; i++){
    analogWrite(a, i);
    delay(30);
   }
 }  
}
