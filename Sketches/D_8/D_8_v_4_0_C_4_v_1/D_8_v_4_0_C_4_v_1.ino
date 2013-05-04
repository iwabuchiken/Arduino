/*
  File: D_8_v_4_0_C_4_v_1
  Behavior: 7-seg LED
  Ports used:

  Date: 2013/05/04 12:08:42

*/

/* Segment: a,b,c  */
const int anode_pins[] = {6, 7, 8,
                          9, 10, 11,
                          12
                        };
const int number_of_anode_pins = sizeof(anode_pins) / sizeof(anode_pins[0]);

const int LED_dp =  13;    // Port 13 => Output (Connect the anode of the LED to this port)

const int digit_1 =  1;    // Port 13 => Output (Connect the anode of the LED to this port)

const int digits[] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00100111, // 7
  0b01111111, // 8
  0b01101111, // 9
};
void setup()  
{
    for (int i = 0; i < number_of_anode_pins; i++) {
      pinMode(anode_pins[i], OUTPUT);  // anode_pinsを出力モードに設定する
    }
    
    pinMode(digit_1, OUTPUT);  // cathode_pinを出力モードに設定する
}

void loop()
{
    digitalWrite(digit_1, HIGH);
    
    for (int i = 0; i < 10; i++) {
        display_number(i);
  	delay(500);
    }  


}//void loop()

void display_number (int n) {
  for (int i = 0; i < number_of_anode_pins; i++) {
    digitalWrite(anode_pins[i], digits[n] & (1 << i) ? HIGH : LOW);
  }
}
