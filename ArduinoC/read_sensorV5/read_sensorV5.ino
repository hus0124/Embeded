#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
#include <SimpleDHT.h>

static const unsigned char crc8_table[256] =
{
     0,  94, 188, 226,  97,  63, 221, 131, 194, 156, 126,  32, 163, 253,  31,  65,
   157, 195,  33, 127, 252, 162,  64,  30,  95,   1, 227, 189,  62,  96, 130, 220,
    35, 125, 159, 193,  66,  28, 254, 160, 225, 191,  93,   3, 128, 222,  60,  98,
   190, 224,   2,  92, 223, 129,  99,  61, 124,  34, 192, 158,  29,  67, 161, 255,
    70,  24, 250, 164,  39, 121, 155, 197, 132, 218,  56, 102, 229, 187,  89,   7,
   219, 133, 103,  57, 186, 228,   6,  88,  25,  71, 165, 251, 120,  38, 196, 154,
   101,  59, 217, 135,   4,  90, 184, 230, 167, 249,  27,  69, 198, 152, 122,  36,
   248, 166,  68,  26, 153, 199,  37, 123,  58, 100, 134, 216,  91,   5, 231, 185,
   140, 210,  48, 110, 237, 179,  81,  15,  78,  16, 242, 172,  47, 113, 147, 205,
    17,  79, 173, 243, 112,  46, 204, 146, 211, 141, 111,  49, 178, 236,  14,  80,
   175, 241,  19,  77, 206, 144, 114,  44, 109,  51, 209, 143,  12,  82, 176, 238,
    50, 108, 142, 208,  83,  13, 239, 177, 240, 174,  76,  18, 145, 207,  45, 115,
   202, 148, 118,  40, 171, 245,  23,  73,   8,  86, 180, 234, 105,  55, 213, 139,
    87,   9, 235, 181,  54, 104, 138, 212, 149, 203,  41, 119, 244, 170,  72,  22,
   233, 183,  85,  11, 136, 214,  52, 106,  43, 117, 151, 201,  74,  20, 246, 168,
   116,  42, 200, 150,  21,  75, 169, 247, 182, 232,  10,  84, 215, 137, 107,  53
};



//---------------- 온습도계 dht11 관련변수------------------
int pinDHT11 = 2;
SimpleDHT11 dht11;
byte temperature; //온도
byte humidity; //습도
//--------------------------------------------------------


//--------------- 미세먼지 센서 관련 변수------------------
int measurePin = 0;
int ledPower = 4;
 
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
 
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

//------------------------------------------------------------


LiquidCrystal_PCF8574 lcd(0x3F);

//Custom Character #0
byte SpecialChar0[8]={  //지
 B00001,
 B11101,
 B01001,
 B01001,
 B11101,
 B10101,
 B10101,
 B00001
};

//Custom Character #1
byte SpecialChar1[8]={ //먼
 B11101,
 B10101,
 B10111,
 B10101,
 B11101,
 B00001,
 B10000,
 B11111
};

//Custom Character #2
byte SpecialChar2[8]={ //세
 B00001,
 B01011,
 B01111,
 B01011,
 B11111,
 B10111,
 B10111,
 B00001
};

//Custom Character #3
byte SpecialChar3[8]={ //미
 B00001,
 B11101,
 B10101,
 B10101,
 B10101,
 B10101,
 B11101,
 B00001
};

//Custom Character #4
byte SpecialChar4[8]={ //온도기호
 B00010,
 B00101,
 B00010,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000
};

//Custom Character #5
byte SpecialChar5[8]={ //습
 B00100,
 B01010,
 B10001,
 B11111,
 B01010,
 B01110,
 B01010,
 B01110
};

//Custom Character #6
byte SpecialChar6[8]={ //도
 B11111,
 B10000,
 B10000,
 B11111,
 B00000,
 B00100,
 B00100,
 B11111
};

//Custom Character #7
byte SpecialChar7[8]={ //온
 B01110,
 B10001,
 B10001,
 B01110,
 B00100,
 B11111,
 B10000,
 B11111
};

unsigned char data_format[5];

int i;
int count=15;     //sampling 15sec 
int level;

void setup() {
  int error;
  pinMode(ledPower,OUTPUT);
  Serial.begin(115200);
  //Serial.println("LCD...");
  while (! Serial);
  //Serial.println("Dose: check for LCD");
  
  Wire.begin();
  Wire.beginTransmission(0x3F);
  error = Wire.endTransmission();
  //Serial.print("Error: ");
  //Serial.print(error);

  if (error == 0) {
    //Serial.println(": LCD found.");

  } else {
    //Serial.println(": LCD not found.");
  } // if

  lcd.begin(16, 2); // initialize the lcd

  lcd.createChar(0, SpecialChar0);
  lcd.createChar(1, SpecialChar1);
  lcd.createChar(2, SpecialChar2);
  lcd.createChar(3, SpecialChar3);
  lcd.createChar(4, SpecialChar4);
  lcd.createChar(5, SpecialChar5);
  lcd.createChar(6, SpecialChar6);
  lcd.createChar(7, SpecialChar7);
  
  lcd.setBacklight(255);
  lcd.home(); lcd.clear();

  lcd.write(byte(7));  //온
  lcd.write(byte(6));  //도
  lcd.print(":");
  lcd.setCursor(5, 0); 
  lcd.write(byte(4));   //온도기호
  lcd.print("C");
  
  lcd.setCursor(9, 0);  // (칸수, 라인)
  lcd.write(byte(5));  //습
  lcd.write(byte(6));  //도
  lcd.print(":");
  lcd.setCursor(14, 0); 
  lcd.print("%");

  
  lcd.setCursor(0, 1);
  lcd.write(byte(3));  //미
  lcd.write(byte(2));  //세
  lcd.write(byte(1));  //먼
  lcd.write(byte(0));  //지
  lcd.print(":"); 
  lcd.setCursor(8, 1); 
  lcd.print(",Max=999");
 
}

void loop() {
    
    int result=0;
    int i;
   
    if(count==15)
    {
      for(i=0; i<10; i++){
        result=read_dht11();
        if(result==0)break;
        delay(100); 
       }

      level=0;
      for(i=0; i<20; i++)
      {
        level+=read_dust();  //측정값이 불안함으로 20회 측정후
      }
      level= level/20;        //평균처리
      count=0;
        
    lcd.setCursor(3, 0);
    lcd.print("  ");
    lcd.setCursor(3, 0);
    lcd.print((int)temperature);
    
    lcd.setCursor(12, 0);
    lcd.print("  ");
    lcd.setCursor(12, 0);
    lcd.print((int)humidity);

    lcd.setCursor(5, 1);
    lcd.print("   ");                //깨끗하게 지우고
    //level=(level-60)/8;                //데이터 시트상에는 최소값이 0.59V(120) 인데 실 측정값 0.3V(60)이다, 그리고 최대값은 3.5V(868)인데 나올까?
    lcd.setCursor(5, 1);
    lcd.print(level);
    }

    count++;;
    //Serial.println("Serial Commucation Test Data Format !!");
    data_format[0]=temperature;
    data_format[1]=humidity;
    data_format[2]=(uint16_t)level>>8;;
    data_format[3]=((uint16_t)level);
    data_format[4]=crc_8( data_format , 4 ) ;

    if(Serial.available())
    {
      char command = Serial.read();
      if(command =='R')
      {
        Serial.write(data_format,5);  
      }
    }
    

    delay(1000); //일단은 15초에 한번씩 읽자!  1sec * 15

}

int read_dht11()  //온습도계
{
  // 측정값 temperature, humidity 는 전역변수로
  
  // start working...
  //Serial.println("=================================");
  //Serial.println("Sample DHT11...");

  // read without samples
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  { //에러일 경우
    //Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return -1;
  }

  //Serial.print("Sample OK: ");
  //Serial.print((int)temperature); Serial.print(" *C, "); 
  //Serial.print((int)humidity); Serial.println(" H");
  return 0;
  
}

int read_dust()
{
  digitalWrite(ledPower,LOW); // power on the LED
  delayMicroseconds(samplingTime);
 
  voMeasured = analogRead(measurePin); // read the dust value
 
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH); // turn the LED off
  delayMicroseconds(sleepTime);
 
  // 0 - 3.3V mapped to 0 - 1023 integer values
  // recover voltage
  calcVoltage = voMeasured * (5.0 / 1024);
 
  dustDensity = 0.17 * calcVoltage - 0.1;
 
  //Serial.print("Raw Signal Value (0-1023): ");
 // Serial.print(voMeasured);
  
  //Serial.print(" - Voltage: ");
  //Serial.print(calcVoltage);
 
  //Serial.print(" - Dust Density: ");
  //Serial.println(dustDensity);

  return voMeasured;
}

unsigned char crc_8( unsigned char *data , int size )  
{  
    int lp;
    unsigned char crc8=0;
   
    for( lp = 0; lp < size; lp++ ) crc8 = crc8_table[ crc8 ^ data[lp] ] ;
    return crc8; 
}
