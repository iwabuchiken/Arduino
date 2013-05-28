/*
  File: D_14_v_2_0_e_2
  Loc: Banzi.55
  
  Behavior: 
  Ports used:
        13  => Output
  Date: 2013/05/28 11:36:26
  
  Memo: 

*/
/*****************************************
*  Variables: Non-const
******************************************/
int val = 0;
char dtostrfbuffer[15];

/*****************************************
*  Variables: Const
******************************************/
const int LED = 13;
const int analog_read = 0;

const float source_voltage = 4.96;
const int max_range = 1023;

/*****************************************
*  Methods: Basics
******************************************/
void setup()                    // run once, when the sketch starts
{
    Serial.begin(9600);           // set up Serial library at 9600 bps
    
  //  Serial.println("Hello world!");  // prints hello with ending line break 
    Serial.println("Started");  // prints hello with ending line break 
    
    pinMode(LED, OUTPUT);
  
}

void loop()                       // run over and over again
{
    val = analogRead(analog_read);

    Serial.print("val=");
    Serial.println(String(val)); 
//    Serial.println(dtostrf((val * source_voltage / max_range), 4, 2, dtostrfbuffer));
    
    digitalWrite(LED, HIGH);
    delay(val);
    
    digitalWrite(LED, LOW);
    delay(val);
    
}//void loop()
