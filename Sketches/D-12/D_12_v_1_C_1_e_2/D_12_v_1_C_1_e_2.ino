/*
  File: D-12_v-1_C-1_e-2
  Behavior: Push the button; the message shows up
  Ports used:
        13  => Output
  Date: 2013/05/06 16:28:30
  Memo: Code changed to modelate the behavior(Banzi:41)
        1. Counter measure for the bouncing of the push switch

*/

/**********************************************
    Variables
***********************************************/
const int LED_1     = 13;    // Port 13 => Output (Connect the anode of the LED to this port)
const int LED_2     = 12;    // Port 13 => Output (Connect the anode of the LED to this port)
const int BUTTON_1  = 7;    // Port 7 => Pin for the push button
const int BUTTON_2  = 6;    // Port 6 => Pin for the push button

int val_1            = 0;    // Keeps the state of the input pin, i.e. the pin 7
int val_2            = 0;    // Keeps the state of the input pin, i.e. the pin 7

/**********************************************
    Badic methods
***********************************************/
void setup()                    // run once, when the sketch starts
{
  
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    
    pinMode(BUTTON_1, INPUT);
    pinMode(BUTTON_2, INPUT);
    
}

void loop()                       // run over and over again
{
                                  // do nothing!
    val_1 = digitalRead(BUTTON_1);
    val_2 = digitalRead(BUTTON_2);
    
    // Set the state
    if (val_1 == HIGH) {
      
        digitalWrite(LED_1, HIGH);
      
    } else {
     
       digitalWrite(LED_1, LOW);
      
    }
    
    if (val_2 == HIGH) {
      
        digitalWrite(LED_2, HIGH);
      
    } else {
     
       digitalWrite(LED_2, LOW);
      
    }
}//void loop()

/**********************************************
    Methods
***********************************************/

