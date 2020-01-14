//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
//  lcd.backlight();
//  lcd.setCursor(0,0);
//  lcd.print("Hello, world!");
//  lcd.setCursor(0,1);
//  lcd.print("Ywrobot Arduino!");

lcd.setCursor(0,0);
lcd.print(".        ");
delay(300);
lcd.setCursor(0,0);
lcd.print(" .       ");
delay(300);
lcd.setCursor(0,0);
lcd.print("  .      ");
delay(300);
lcd.setCursor(0,0);
lcd.print("   .     ");
delay(300);
lcd.print("    .    ");
delay(300);

int a=100;
lcd.setCursor(2,1); 
lcd.print(a);

}


void loop()
{
  
}
