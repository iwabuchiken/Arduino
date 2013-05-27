/*
  File: D_14_v_3_0_e_1_Cds
  Loc: Banzi.054
  
  Behavior: 
  Ports used: A0 => Input

  Date: 2013/05/27 19:57:26
  
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
const int analog_input = 0;
const float source_voltage = 4.96;
const int max_range = 1023;

/*****************************************
*  Methods
******************************************/
void setup()                    // run once, when the sketch starts
{
    Serial.begin(9600);           // set up Serial library at 9600 bps
    
  //  Serial.println("Hello world!");  // prints hello with ending line break 
    Serial.println("Started");  // prints hello with ending line break 
  
}

void loop()                       // run over and over again
{
    val = analogRead(analog_input);
    
//    Serial.println("val=" + String(val * source_voltage / max_range));
    Serial.print("val=");
    Serial.println(dtostrf((val * source_voltage / max_range), 4, 2, dtostrfbuffer));
    
    delay(10);
    
}//void loop()
