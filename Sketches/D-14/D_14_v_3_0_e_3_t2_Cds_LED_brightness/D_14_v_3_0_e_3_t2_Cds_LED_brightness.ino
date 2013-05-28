/*
  File: D_14_v_3_0_e_3_t2_Cds_LED_brightness
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
int analog_output = 0;
int divider = 6;

char dtostrfbuffer[15];

/*****************************************
*  Variables: Const
******************************************/
const int LED = 9;
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
    analog_output = val / divider;
    
    Serial.print("val=");
    Serial.print(String(val) + "("); 
//    Serial.print(dtostrf((source_voltage * (val / 4)/ max_range), 4, 2, dtostrfbuffer)); 
    Serial.print(dtostrf((source_voltage * (analog_output)/ max_range), 4, 2, dtostrfbuffer)); 
    Serial.print(")");

    Serial.print("(analog_output="); 
//    Serial.print(dtostrf((source_voltage * (val / 4)/ max_range), 4, 2, dtostrfbuffer)); 
    Serial.print(String(analog_output)); 
    Serial.print("=");
    Serial.print(dtostrf((source_voltage * (analog_output)/ 255), 4, 2, dtostrfbuffer));
    Serial.println(")");
    
//    analogWrite(LED, val / 4);
    analogWrite(LED, analog_output);
    delay(10);
    
}//void loop()
