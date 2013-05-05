/*
  File: D_11_v_1_0_C_1_v_1
  Behavior: 7-seg LED
  Ports used:

  Date: 2013/05/04 12:08:42

*/

/*******************************************
    Variables: Constants
********************************************/
/* Segment: a,b,c  */
const int anode_pins[] = {6, 7, 8,
                          9, 10, 11,
                          12
                        };
                        
const int cathode_pins[] = {1, 2, 3};
  
const int number_of_anode_pins = sizeof(anode_pins) / sizeof(anode_pins[0]);
const int number_of_cathode_pins = sizeof(cathode_pins) / sizeof(cathode_pins[0]);

//const int wait_length = 500;
const int wait_length = 1;

//const int max_num = 1000;
const int max_num = 10000;

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

/*******************************************
    Variables: Non-constants
********************************************/
int numbers_to_display = 0; // LEDに表示する数字を保持する変数]


/*******************************************
    Functions
********************************************/
void set_numbers(int n) {
    numbers_to_display = n;
}

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

void display_numbers () {
    int n = numbers_to_display;  // number_to_displayの値を書き換えないために変数にコピー
    for (int i = 0; i < number_of_cathode_pins; i++) {
        digitalWrite(cathode_pins[i], HIGH);
        display_number(n % 10); // 最後の一桁を表示する
        delayMicroseconds(100);
        clear_segments();
        digitalWrite(cathode_pins[i], LOW);
        n = n / 10; // 10で割る
    }
}//void display_numbers (int n) {

/*******************************************
    Functions: Basics
********************************************/
// setup()　は，最初に一度だけ実行される
void setup() {
    for (int i = 0; i < number_of_anode_pins; i++) {
        pinMode(anode_pins[i], OUTPUT);  // anode_pinsを出力モードに設定する
    }
    for (int i = 0; i < number_of_cathode_pins; i++) {
        pinMode(cathode_pins[i], OUTPUT);  // cathode_pinを出力モードに設定する
//        digitalWrite(cathode_pins[i], HIGH);
        digitalWrite(cathode_pins[i], LOW);
    }
    
    // f = クロック周波数 / ( 2 * 分周比　*　( 1 + 比較レジスタの値))
    // 分周比=32, 比較レジスタの1値=255 -> f = 16000000 / (2 * 32 * 256) = 976 Hz
    OCR2A = 255; // 255クロックごとに割り込みをかける
    TCCR2B = 0b100; // 分周比を32に設定する
    bitWrite(TIMSK2, OCIE2A, 1); // TIMER2を
}//void setup()

void loop () {
    for (int i = 0; i < 10000; i++) {
      set_numbers(i);
      delay(1000);
    }
}//void loop()

ISR(TIMER2_COMPA_vect)
{
    display_numbers();
}
