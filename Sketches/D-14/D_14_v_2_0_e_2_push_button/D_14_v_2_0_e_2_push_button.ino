/*
  File: D_14_v_2_0_e_2
  Loc: Banzi.041
  
  Behavior: 
  Ports used:
        13  => Output
  Date: 2013/05/27 19:57:26
  
  Memo: Code changed to modelate the behavior(Banzi:41)
        1. Counter measure for the bouncing of the push switch
        C/P from: C:\WORKS\WS\Arduino\Sketches\e_05_serial\e_05_serial.ino

*/
/*****************************************
*  Variables: Non-const
******************************************/
int counter = 0;

int val = 0;
int old_val = 0;
int state = 0;

/*****************************************
*  Variables: Const
******************************************/
const int point = 5;

const int BT_1  = 4;

void setup()                    // run once, when the sketch starts
{
    Serial.begin(9600);           // set up Serial library at 9600 bps
    
  //  Serial.println("Hello world!");  // prints hello with ending line break 
    Serial.println("Started");  // prints hello with ending line break 
    
    pinMode(BT_1, INPUT);
  
}

void loop()                       // run over and over again
{
    val = digitalRead(BT_1);
    
    if ((val == HIGH) && (old_val == LOW)) {
        state = 1 - state;
        
        delay(10);
    }
    
    old_val = val;
    
    if (state == 1) {
        
        Serial.println("You pushed the button! I'll give you the bonus point of " + String(point));
        
        counter += point;
        
        Serial.println("The count is now... " + String(counter));
        
        delay(900);
        
    } else {
        
        counter += 1;
        
        Serial.println("I'm conting... => " + String(counter));
        
        delay(1000);
        
    }
    
    
//    while (digitalRead(BT_1) == LOW) {
//
//        // REF conversion: http://stackoverflow.com/questions/7910339/how-to-convert-int-to-string-on-arduino answered Oct 27 '11 at 11:03
//        Serial.println("I'm conting... => " + String(counter));
//        
//        counter += 1;
//        
//        delay(1000);
//
//    }
    
//    if (digitalRead(BT_1) == HIGH) {
//        
//        Serial.println("You pushed the button! I'll give you the bonus point of " + String(point));
//        
//        counter += point;
//        
//        Serial.println("The point is now... => " + String(counter));
//      
//    }
                                  // do nothing!
}//void loop()
