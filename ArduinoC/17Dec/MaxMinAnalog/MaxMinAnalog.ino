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
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  // int sensorValue = analogRead(A0);
  // print out the value you read:
  //Serial.println(sensorValue);
  // delay(500);        // delay in between reads for stability

  int val = 0;
  int sum = 0;
  int max = 0;
  int min = 10000;
  
  for(int i=0;i<20;i++)
  {
    val = analogRead(A0);
    if(max < val)
      max=val;
    if(min > val)
      min=val;
    sum += val;
    delay(25);
  }

  val=(sum-max-min)/18;
  Serial.println(val);
  delay(1);
}
