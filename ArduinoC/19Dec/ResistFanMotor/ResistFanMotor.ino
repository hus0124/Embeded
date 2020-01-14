
int val;
int val2;
int potpin = 0;
int INA = 6;  
int INB = 5;

void setup() {
  // put your setup code here, to run once:

  pinMode(INA,OUTPUT); 
  pinMode(INB,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  val = analogRead(potpin);
  val2 = mymap(val, 0, 1023, 0, 255);
  delay(15);

  analogWrite(INA,val2); 
  analogWrite(INB,0);
  
}

int mymap(int a, int b, int c, int d, int e){
  int ratio = (c-b+1)/(e-d+1);
  int result = a/ratio;
  return result;
}
