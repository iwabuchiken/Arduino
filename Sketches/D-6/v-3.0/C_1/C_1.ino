/*
  File: C_1
  Behavior: LED turns on
  Ports used:
        13  => Output
  Date: 2013/04/28 16:53:37

*/

const int LED = 13;    // Port 13 => Output (Connect the anode of the LED to this port)

void setup()  
{
  
    pinMode(LED, OUTPUT);
    
}

void loop()
{
  
    digitalWrite(LED, HIGH);
    delay(500);

    digitalWrite(LED, LOW);
    delay(2000);
  
}
