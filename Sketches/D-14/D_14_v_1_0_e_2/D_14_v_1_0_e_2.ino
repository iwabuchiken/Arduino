/*
  File: D_14_v_1_0_e_2
  Behavior: Get a message from the Arduino
  Ports used:
        13  => Output
  Date: 2013/05/22 20:20:24
  Memo: Code changed to modelate the behavior(Banzi:41)
        1. Counter measure for the bouncing of the push switch
        C/P from: C:\WORKS\WS\Arduino\Sketches\e_05_serial\e_05_serial.ino

*/
/*****************************************
*  Variables
******************************************/
int counter = 0;

void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  
//  Serial.println("Hello world!");  // prints hello with ending line break 
  Serial.println("Hello, I'm Arduino!");  // prints hello with ending line break 
}

void loop()                       // run over and over again
{
    // REF conversion: http://stackoverflow.com/questions/7910339/how-to-convert-int-to-string-on-arduino answered Oct 27 '11 at 11:03
    Serial.println("I'm conting... => " + String(counter));
    
    counter += 1;
    
    delay(1000);
    
                                  // do nothing!
}
