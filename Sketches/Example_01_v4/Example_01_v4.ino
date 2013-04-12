/*
  File: Example_01
  Behavior: LED turns on and off
  Ports used:
        13  => Output
  Date: 2013/04/07 15:16:07

*/
//ERROR => http://arduino.cc/forum/index.php/topic,28223.0.html
const int LED = 13;    // Port 13 => Output (Connect the anode of the LED to this port)

void setup()  
{
  
    pinMode(LED, OUTPUT);
    
}

void loop()
{
  
    digitalWrite(LED, HIGH);
    delay(1);

    digitalWrite(LED, LOW);
    delay(1);

}
