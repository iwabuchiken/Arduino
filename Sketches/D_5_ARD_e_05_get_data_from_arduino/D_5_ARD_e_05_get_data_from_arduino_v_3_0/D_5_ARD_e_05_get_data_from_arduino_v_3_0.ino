/*
  File: D_5_ARD_e_05_get_data_from_arduino_v-3_0
  Behavior: 
  Ports used:
        13  => Output
  Date: 2013/04/12 11:35:31
  Memo: 

*/

/**********************************************
    Variables
***********************************************/
//int serialState = 0;
int avail = 0;
int nonavail = 0;
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
  
  Serial.flush();
  
}//void setup()

void loop()                       // run over and over again
{
    buttonListeners();
    
  if (Serial.available() > 0) {
      if (avail == 0) {

          Serial.flush();
      
          Serial.println("Serial available");
          
          String msg = Serial.readString();
          
//          Serial.println("msg=" + msg);
//          Serial.println("msg=" + msg + "(" + String.valueOf(millis()) + ")");          
          Serial.println("msg=" + msg + "(" + millis() + ")");          

          avail = 1;          
          nonavail = 0;
//          serialState = 1;

      }
//      Serial.flush();
//      
//      Serial.println("Serial available");
//      
//      String msg = Serial.readString();
//      
//      Serial.println("msg=" + msg);
    
    
  
  } else {
        if (nonavail == 0) {
          
          Serial.println("Serial not available");
          
          nonavail = 1;
          avail = 0;
          
        }
//      Serial.println("Serial not available");
    
//    serialState = 0;
    
  }
  
}//void loop()

/**********************************************
    Methods
***********************************************/
void buttonListeners() {
  
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

  
}//void buttonListeners() {
  
