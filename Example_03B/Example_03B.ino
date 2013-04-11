/*
  File: Example_03B
  Behavior: Push the button, and the LED keeps its changed state
  Ports used:
        13  => Output
  Date: 2013/04/07 15:52:06
  Memo: Code changed to modelate the behavior(Banzi:38)

*/

const int LED     = 13;    // Port 13 => Output (Connect the anode of the LED to this port)
const int BUTTON  = 7;    // Port 7 => Pin for the push button

int val            = 0;    // Keeps the state of the input pin, i.e. the pin 7
int old_val        = 0;    // Keeps the previous value of "val", i.e. the pin 7
int state          = 0;    // Keeps the state of the LED (0 => Off, 1 => On)

void setup() {
  
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  
}

void loop() {
  // Read the state of the button
  val = digitalRead(BUTTON);
  
  // Set the state
  if ((val == HIGH) && (old_val == LOW)) {
    
    state = 1 - state;
    
  }
  
  // Store the value of "val"
  old_val = val;
  
  // Controll the LED
  if (state == 1) {
    
    digitalWrite(LED, HIGH);
    
  } else {
    
    digitalWrite(LED, LOW);
    
  }//if (state == 1) {
  
}//void loop() {
