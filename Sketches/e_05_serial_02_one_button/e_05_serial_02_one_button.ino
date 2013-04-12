/*
  File: e_05_serial_02_one_button.ino
  Behavior: Push the button; the message shows up
  Ports used:
        13  => Output
  Date: 2013/04/07 15:52:06
  Memo: Code changed to modelate the behavior(Banzi:41)
        1. Counter measure for the bouncing of the push switch

*/

/**********************************************
    Variables
***********************************************/
const int LED     = 13;    // Port 13 => Output (Connect the anode of the LED to this port)
const int BUTTON  = 7;    // Port 7 => Pin for the push button

int val            = 0;    // Keeps the state of the input pin, i.e. the pin 7
int old_val        = 0;    // Keeps the previous value of "val", i.e. the pin 7
int state          = 0;    // Keeps the state of the LED (0 => Off, 1 => On)

int message_state  = 0;

/**********************************************
    Badic methods
***********************************************/
void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  
//  Serial.println("Hello world!");  // prints hello with ending line break 
  Serial.println("Communicatin starts.");  // prints hello with ending line break 
  
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);

}

void loop()                       // run over and over again
{
                                  // do nothing!
    val = digitalRead(BUTTON);
    
    // Set the state
    if ((val == HIGH) && (old_val == LOW)) {
      
      state = 1 - state;
      
      delay(10);
      
    }
    
    // Store the value of "val"
    old_val = val;
    
    // Controll the LED
    if (state == 1) {
      
      digitalWrite(LED, HIGH);
      
      if (message_state == 0) {

          Serial.println("On!");  // prints hello with ending line break       
          
          message_state = 1;
        
      }
      
    } else {
      
      digitalWrite(LED, LOW);

      if (message_state == 1) {

          Serial.println("Off!");  // prints hello with ending line break       
          
          message_state = 0;
        
      }
      
    }//if (state == 1) {
                                  
}

/**********************************************
    Methods
***********************************************/

