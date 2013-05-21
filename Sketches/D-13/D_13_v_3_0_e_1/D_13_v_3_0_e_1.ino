/*
  File: D_13_v_3_0_e_1
  Behavior: 7-seg LED
  Ports used:

  Date: 2013/05/21 19:13:43

*/

/*******************************************
    Variables: Constants
********************************************/

const int BT_1  = 4;  // Turn the motor: Left
const int BT_2  = 5;  // Turn the motor: Right

const int BT_OUT_1  = 12;  // Left
const int BT_OUT_2  = 13;  // Right

/*******************************************
    Variables: Non-constants
********************************************/


/*******************************************
    Functions
********************************************/

/*******************************************
    Functions: Basics
********************************************/
// setup()　は，最初に一度だけ実行される
void setup() {
    
    pinMode(BT_1, INPUT);
    pinMode(BT_2, INPUT);
    
    pinMode(BT_OUT_1, OUTPUT);  
    pinMode(BT_OUT_2, OUTPUT);  
    
}//void setup()

void loop () {

    digitalWrite(BT_OUT_1, LOW);
    digitalWrite(BT_OUT_2, LOW);
    
    while (digitalRead(BT_1) == HIGH) {
      
        digitalWrite(BT_OUT_1, HIGH);
        digitalWrite(BT_OUT_2, LOW);      
    }
    
    while (digitalRead(BT_2) == HIGH) {
      
        digitalWrite(BT_OUT_1, LOW);
        digitalWrite(BT_OUT_2, HIGH);
    }
    
}//void loop()

