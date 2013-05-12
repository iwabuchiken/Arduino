/*
  File: D-12_v-1_C-1_e-1
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
const int LED     = 13;    // Port 13 => Output (Connect the anode of the LED to this port)
const int BUTTON  = 7;    // Port 7 => Pin for the push button

int val            = 0;    // Keeps the state of the input pin, i.e. the pin 7

/**********************************************
    Badic methods
***********************************************/
void setup()                    // run once, when the sketch starts
{
  
    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT);

}

void loop()                       // run over and over again
{
                                  // do nothing!
    val = digitalRead(BUTTON);
    
    // Set the state
    if (val == HIGH) {
      
        digitalWrite(LED, HIGH);
      
    } else {
     
       digitalWrite(LED, LOW);
      
    }
}//void loop()

/**********************************************
    Methods
***********************************************/

