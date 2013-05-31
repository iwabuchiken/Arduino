/*
  File: D_14_v_4_0_e_2_ino
  Behavior: 7-seg LED
  Ports used:

  Date: 2013/05/31 14:31:17

*/

/*******************************************
    Variables: Constants
********************************************/
/* Segment: a,b,c  
  Arduino        Module
  6              1(Left most pin)
  7              2
  8              3
  9              4
  10              5
  11              
  12              

*/
const int anode_pins[] = {6, 7, 8,
                          9, 10, 11,
                          12
                        };
/*  1 => Unit
    2 => 10s
    3 => 100s
*/
const int cathode_pins[] = {1, 2, 3};

const int CDS  = 4;  // Button for input

int val_1            = 0;  // Value of the button

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

int val = 0;

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
    // Anode pins(i.e. number pins)
    for (int i = 0; i < number_of_anode_pins; i++) {
        pinMode(anode_pins[i], OUTPUT);  // anode_pinsを出力モードに設定する
    }
    
    // Cathode pins (i.e. 3 digit pins)
    for (int i = 0; i < number_of_cathode_pins; i++) {
        pinMode(cathode_pins[i], OUTPUT);  // cathode_pinを出力モードに設定する
//        digitalWrite(cathode_pins[i], HIGH);
        digitalWrite(cathode_pins[i], LOW);
    }
    
    // Input button
    pinMode(CDS, INPUT);
    
    // f = クロック周波数 / ( 2 * 分周比　*　( 1 + 比較レジスタの値))
    // 分周比=32, 比較レジスタの1値=255 -> f = 16000000 / (2 * 32 * 256) = 976 Hz
    OCR2A = 255; // 255クロックごとに割り込みをかける
    TCCR2B = 0b100; // 分周比を32に設定する
    bitWrite(TIMSK2, OCIE2A, 1); // TIMER2を
    
    // Serial com
    Serial.begin(9600);           // set up Serial library at 9600 bps
    
    Serial.println("Started");  // prints hello with ending line break 
    
}//void setup()

ISR(TIMER2_COMPA_vect)
{
    display_numbers();
}

void loop () {
    
    val = analogRead(CDS);
  
    set_numbers(val);
    
    delay(100);

}//void loop()

