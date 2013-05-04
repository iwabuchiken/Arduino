/*
  File: D_8_v_4_0_C_3_v_2
  Behavior: 7-seg LED
  Ports used:

  Date: 2013/05/04 12:08:42

*/

/* Segment: a,b,c  */
const int LED_a =  6;    // Port 13 => Output (Connect the anode of the LED to this port)
const int LED_b =  7;    // Port 13 => Output (Connect the anode of the LED to this port)
const int LED_c =  8;    // Port 13 => Output (Connect the anode of the LED to this port)

const int LED_d =  9;    // Port 13 => Output (Connect the anode of the LED to this port)
const int LED_e =  10;    // Port 13 => Output (Connect the anode of the LED to this port)
const int LED_f =  11;    // Port 13 => Output (Connect the anode of the LED to this port)

const int LED_g  =  12;    // Port 13 => Output (Connect the anode of the LED to this port)
const int LED_dp =  13;    // Port 13 => Output (Connect the anode of the LED to this port)

const int digit_1 =  1;    // Port 13 => Output (Connect the anode of the LED to this port)
const int digit_2 =  2;    // Port 13 => Output (Connect the anode of the LED to this port)
const int digit_3 =  3;    // Port 13 => Output (Connect the anode of the LED to this port)
const int unit_num[3] = {1, 2, 3};

int          digit_num = 0;

const int delayTime = 1;

int flag          = 1;

int theNumber      = 401;

int d1;  // Unit digit
int d2;  // Tens digit
int d3;  // Hundreds digit

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
	pinMode(LED_a, OUTPUT);
	pinMode(LED_b, OUTPUT);
	pinMode(LED_c, OUTPUT);

	pinMode(LED_d, OUTPUT);
	pinMode(LED_e, OUTPUT);
	pinMode(LED_f, OUTPUT);

	pinMode(LED_g, OUTPUT);
	pinMode(LED_dp, OUTPUT);

	pinMode(digit_1, OUTPUT);
	pinMode(digit_2, OUTPUT);
	pinMode(digit_3, OUTPUT);

        // Convert the number into 3 digits
        convertNumber2Digits(theNumber);
    //pinMode(LED, OUTPUT);
    
}

void loop()
{
		digitalWrite(unit_num[digit_num], HIGH);
		display_number(0);
  		delay(500);
		display_number(1);
		delay(500);
		display_number(2);
		delay(500);
		display_number(3);
		delay(500);
		display_number(4);
		delay(500);
		display_number(5);
		delay(500);
		display_number(6);
		delay(500);
		display_number(7);
		delay(500);
		display_number(8);
		delay(500);
		display_number(9);
		delay(500);
		delay(delayTime);

                // Change the digit
		digitalWrite(unit_num[digit_num], LOW);

                if (digit_num >= 2) {
                    
                    digit_num = 0;
                  
                } else {
                  
                    digit_num += 1;
                  
                }
  
}

void convertNumber2Digits(int number)
{
      d3 = number / 100;
      d2 = (number - d3 * 100) / 10;
      d1 = number - (d3 * 100 + d2 * 10);

}//void convertNumber2Digits(int number)

void display_number (int n) {
  // digits[n]の各ビットを調べて対応するセグメントを点灯・消灯する
  digitalWrite(LED_a, digits[n] & 0b00000001 ? HIGH : LOW);
  digitalWrite(LED_b, digits[n] & 0b00000010 ? HIGH : LOW);
  digitalWrite(LED_c, digits[n] & 0b00000100 ? HIGH : LOW);
  digitalWrite(LED_d, digits[n] & 0b00001000 ? HIGH : LOW);
  digitalWrite(LED_e, digits[n] & 0b00010000 ? HIGH : LOW);
  digitalWrite(LED_f, digits[n] & 0b00100000 ? HIGH : LOW);
  digitalWrite(LED_g, digits[n] & 0b01000000 ? HIGH : LOW);
}
