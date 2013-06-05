/*
  File: D_15_v_2_0_e_1_print_number
  Behavior: 7-seg LED
  Ports used:

  Date: 2013/06/03 16:08:31

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
void setup() {
  lcd.begin(16, 2);
  
  lcd.print("hello, world!");
}

void loop() {

//    lcd.setCursor(0, 1);
//    
//    lcd.print(millis()/1000);

}

