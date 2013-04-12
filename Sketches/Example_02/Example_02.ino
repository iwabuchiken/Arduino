/*
  File: Example_02
  Behavior: Use a button
  Ports used:
        13  => Output
  Date: 2013/04/07 15:52:06

*/

const int LED     = 13;    // Port 13 => Output (Connect the anode of the LED to this port)
const int BUTTON  = 7;    // Port 7 => Pin for the push button

int val            = 0;

void setup() {
  
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  
}

void loop() {
  
  val = digitalRead(BUTTON);
  
  if (val == HIGH) {
    
    digitalWrite(LED, HIGH);    
    
  } else {
    
    digitalWrite(LED, LOW);
    
  }
}//void loop() {
