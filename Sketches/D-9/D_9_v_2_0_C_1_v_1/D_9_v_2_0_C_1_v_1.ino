/*
  File: D_9_v_2_0_C_1_v_1
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

const int wait_length = 3;

//const int turn_on_pins[] = {6, 11, 12};
//int turn_on_pins[] = {6, 11, 12};

//const int LED_dp =  13;    // Port 13 => Output (Connect the anode of the LED to this port)

void setup()
{
//    turn_on_pins[0] = random(number_of_anode_pins) + 6;
    
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
    for (int i = 0; i < number_of_cathode_pins; i++) {
        digitalWrite(cathode_pins[i], HIGH);  // 表示桁を選択
        digitalWrite(turn_on_pins[i], HIGH); // 表示するセグメントのアノードをHIGHにする
        delay(3);  // 明るさ調整用。点滅しない程度に。
        digitalWrite(turn_on_pins[i], LOW); // アノードをすべてLOWにする
        digitalWrite(cathode_pins[i], LOW); // 選択したカソードをHIGHにする
    }
}//void loop()

