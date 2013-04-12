/*
  File: Example_03A
  Behavior: Push the button, and the LED keeps its changed state
  Ports used:
        13  => Output
  Date: 2013/04/07 15:52:06

*/

const int LED     = 13;    // Port 13 => Output (Connect the anode of the LED to this port)
const int BUTTON  = 7;    // Port 7 => Pin for the push button

int val            = 0;    // Keeps the state of the input pin, i.e. the pin 7
int state          = 0;    // Keeps the state of the LED (0 => Off, 1 => On)

void setup() {
  
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  
}

void loop() {
  
  val = digitalRead(BUTTON);
  
  if (val == HIGH) {
    
    state = 1 - state;
    
  }
  
  if (state == 1) {
    
    digitalWrite(LED, HIGH);    
    
  } else {
    
    digitalWrite(LED, LOW);
    
  }
}//void loop() {
