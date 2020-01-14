//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  Serial.begin(9600);

   
}

// **NOW LOADING** 15글자
void loop()
{
  char sentence[15] = {"**NOW LOADING**"};
  char sentence2[15] = {"**GNIDAOL WON**"};
  
    for(int i = 0; i < 16; i++){
      lcd.setCursor(i, 0);
      lcd.print(sentence);  // 적을 내용
      delay(200);
      lcd.setCursor(i,0);
      lcd.print("               ");
      delay(200);  
    } 

    for(int i = 0; i < 16; i++){
      lcd.setCursor(i, 1);
      lcd.print(sentence);  // 적을 내용
      delay(200);
      lcd.setCursor(i,1);
      lcd.print("               ");
      delay(200);  
    }

  
}
