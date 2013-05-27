/*
  File: D_14_v_2_0_e_1
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

const int point = 5;

const int BT_1  = 4;

void setup()                    // run once, when the sketch starts
{
    Serial.begin(9600);           // set up Serial library at 9600 bps
    
  //  Serial.println("Hello world!");  // prints hello with ending line break 
    Serial.println("Hello, I'm Arduino!");  // prints hello with ending line break 
    
    pinMode(BT_1, INPUT);
  
}

void loop()                       // run over and over again
{
    while (digitalRead(BT_1) == LOW) {

        // REF conversion: http://stackoverflow.com/questions/7910339/how-to-convert-int-to-string-on-arduino answered Oct 27 '11 at 11:03
        Serial.println("I'm conting... => " + String(counter));
        
        counter += 1;
        
        delay(1000);

    }
    
    if (digitalRead(BT_1) == HIGH) {
        
        Serial.println("You pushed the button! I'll give you the bonus point of " + String(point));
        
        counter += point;
        
        Serial.println("The point is now... => " + String(counter));
      
    }
                                  // do nothing!
}
