/*
  File: D-15_v_1_0_e_1
  Behavior: 7-seg LED
  Ports used:

  Date: 2013/06/03 11:19:33

*/

#include <LiquidCrystal.h>

/*******************************************
    Variables: Constants
********************************************/

/*******************************************
    Variables: Non-constants
********************************************/

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);


/*******************************************
    Functions
********************************************/

/*******************************************
    Functions: Basics
********************************************/
//void setup() {
//  
//  // REF http://stackoverflow.com/questions/9217084/arduino-lcd-only-showing-black-boxes-on-bottom-row answered Feb 10 '12 at 13:10
//  delay(1000);
//  
//  lcd.begin(16, 2);
//  
////  lcd.setCursor(0, 0);
////  
//////  lcd.print("hello, world!");
//////  lcd.print("hello, world! Hello!!!");
////  lcd.print("Yeeeeeees!!");
//
//}
//
//void loop() {
//
//    lcd.setCursor(0, 0);
//  
////  lcd.print("hello, world!");
////  lcd.print("hello, world! Hello!!!");
//    lcd.print("Yeeeeeees!!");
//
//}

void setup()
{
  Serial.begin( 9600 );
  lcd.begin(16, 2);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.println( "hello world! OHH! ");
  delay(1000);
}
