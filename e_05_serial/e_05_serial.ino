/*
  File: e_05_serial.ino
  Behavior: Get a message from the Arduino
  Ports used:
        13  => Output
  Date: 2013/04/07 15:52:06
  Memo: Code changed to modelate the behavior(Banzi:41)
        1. Counter measure for the bouncing of the push switch

*/
void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  
//  Serial.println("Hello world!");  // prints hello with ending line break 
  Serial.println("Hello Ken!");  // prints hello with ending line break 
}

void loop()                       // run over and over again
{
                                  // do nothing!
}
