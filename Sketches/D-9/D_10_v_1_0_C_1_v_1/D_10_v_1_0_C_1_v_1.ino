/*
  File: D_10_v_1_0_C_1_v_1
  Behavior: 7-seg LED
  Ports used:

  Date: 2013/05/04 12:08:42

*/

/* Segment: a,b,c  */
const int anode_pins[] = {6, 7, 8,
                          9, 10, 11,
                          12
                        };
                        
const int cathode_pins[] = {1, 2, 3};
  
const int number_of_anode_pins = sizeof(anode_pins) / sizeof(anode_pins[0]);
const int number_of_cathode_pins = sizeof(cathode_pins) / sizeof(cathode_pins[0]);

const int wait_length = 500;

const int max_num = 1000;

//const int LED_dp =  13;    // Port 13 => Output (Connect the anode of the LED to this port)

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

void display_number (int n) {
    for (int i = 0; i < number_of_anode_pins; i++) {
      digitalWrite(anode_pins[i], digits[n] & (1 << i) ? HIGH : LOW);
    }
}

void clear_segments() {
    for (int j = 0; j < number_of_anode_pins; j++) {
      digitalWrite(anode_pins[j], LOW);
    }
}

void display_numbers (int n) {
    for (int i = 0; i < number_of_cathode_pins; i++) {
      digitalWrite(cathode_pins[i], LOW);
      display_number(n % 10); // 最後の一桁を表示する
      delay(1);
      clear_segments();
      digitalWrite(cathode_pins[i], HIGH);
      n = n / 10; // 10で割る
    }
}//void display_numbers (int n) {

void setup()
{
    for (int i = 0; i < number_of_anode_pins; i++) {
        pinMode(anode_pins[i], OUTPUT);  // anode_pinsを出力モードに設定する
    }
    
    for (int i = 0; i < number_of_cathode_pins; i++) {
        pinMode(cathode_pins[i], OUTPUT);  // cathode_pinを出力モードに設定する
//        digitalWrite(cathode_pins[i], HIGH);
        digitalWrite(cathode_pins[i], LOW);
    }

}//void setup()

void loop()
{
  
    for (int i = 0; i < max_num; i++) {
      display_numbers(i);
    }
    
}//void loop()

