/*
  File: D_5_ARD_e_05_get_data_from_arduino
  Behavior: 
  Ports used:
        13  => Output
  Date: 2013/04/07 15:52:06
  Memo: Code changed to modelate the behavior(Banzi:41)
        1. Counter measure for the bouncing of the push switch

*/

/**********************************************
    Variables
***********************************************/
int serialState = 0;
int avail = 0;
int nonavail = 0;

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
    
    serialState = 0;
    
  }
  
}//void loop()

/**********************************************
    Methods
***********************************************/

