/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

// the loop routine runs over and over again forever:

  int max=0;
  int min=10000;
  int maxflag=0;
  int minflag=0;
  
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A1);

  if(sensorValue > 450) // 수위 조절 상황 시 센서 작동
  {                                                                      
    for(int i = 0; i < 4; i++){
      digitalWrite(8+i, 1);
      delay(300);
      digitalWrite(8+i, 0);
      delay(300);
    }
  }    
  
    if(max<sensorValue){
      max = sensorValue;
      maxflag=1;
      }
    if(min>sensorValue){
      min = sensorValue;
      minflag=1;
      }
  
  // print out the value you read:

    if(maxflag==1 || minflag==1){
      Serial.print("MIN_VALUE : ");
      Serial.println(min);
      Serial.print("MAX_VALUE : ");
      Serial.println(max);
      maxflag=0;
      minflag=0;
    }
  delay(1);
}
