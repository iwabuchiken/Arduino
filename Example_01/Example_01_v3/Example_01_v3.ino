/*
  File: Example_01_v3
  Behavior: LED turns on and off, the interval gets longer, then back to the minimum length
  Ports used:
        13  => Output
  Date: 2013/04/07 15:16:07

*/

const int LED = 13;    // Port 13 => Output (Connect the anode of the LED to this port)

void setup()  
{
  
    pinMode(LED, OUTPUT);
    
}

void loop()
{
    for(int i = 1; i < 21; i++)
   { 
      digitalWrite(LED, HIGH);
      delay(i * 50);
  
      digitalWrite(LED, LOW);
      delay(i * 50);
   }
}
