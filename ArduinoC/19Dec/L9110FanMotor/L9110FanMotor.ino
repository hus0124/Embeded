int INA = 6;  
int INB = 5;
//int dutylow = 0;
//int dutyhigh = 255;

void setup() 
{ 
pinMode(INA,OUTPUT); 
pinMode(INB,OUTPUT); 
} 

void loop() 
{ 
  
digitalWrite(INB,HIGH);
digitalWrite(INA,LOW); 
//delay(3000);

/*for(int i = dutylow; i < dutyhigh; i++){
analogWrite(INB,LOW);
analogWrite(INA,i);
delay(10);
} 
for(int i = dutyhigh; i < dutylow; i--){
analogWrite(INB,LOW);
analogWrite(INA,i);
delay(10);
}*/
} 
