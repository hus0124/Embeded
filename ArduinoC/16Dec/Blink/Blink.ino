/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
/* blink elevation
 *  
  for(int i=0;i<20;i++){
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000-50*i);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000-50*i); // wait for a second
  }
  
  for(int j=0;j<20;j++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50*j);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50*j);  
  }
*/

/* blink x times

for (int i = 1; ; i++){
  if(i%10!=0){
  digitalWrite(9, 1);
  digitalWrite(13, 1);
  delay(500);
  digitalWrite(9, 0);
  digitalWrite(13, 0);
  delay(500);
  }
  else
  {for(int j=1;j<6;j++){
  digitalWrite(9, 1);
  digitalWrite(13, 1);
  delay(200);
  digitalWrite(9 , 0);
  digitalWrite(13, 0);
  delay(200);
  }
 }
delay(400);
}
*/

/* two each port 
digitalWrite(9, 1);
digitalWrite(13, 0);
delay(500);
digitalWrite(9, 0);
digitalWrite(13, 1);
delay(500);
*/

// 4 port each blink

//for(int i = 0; i < 4; i++){
//digitalWrite(8+i, 1);
//delay(400);
//digitalWrite(8+i, 0);
//delay(400);
//}

hus(9,10,11);
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
