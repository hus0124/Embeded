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
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  
  // print out the value you read:
                                                                  
  if(sensorValue > 100)
  {                                                                      
    for(int i = 0; i < 4; i++){
      digitalWrite(8+i, 1);
      delay(300);
      digitalWrite(8+i, 0);
      delay(300);
    }
  }

  int waterarr[20];

  for(int i=0;i<20;i++){
    waterarr[i]=sensorValue2;
  }

  for(int i=0;i<20;i++){
    Serial.println(waterarr[i]);
  }
  
  if(sensorValue2 > 450)
  {                                                                      
    for(int i = 0; i < 4; i++){
      digitalWrite(8+i, 1);
      delay(300);
      digitalWrite(8+i, 0);
      delay(300);
    }
  }

  delay(1000);
}
