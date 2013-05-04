/*
  File: D_8_v_4_0_C_3_v_3
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
const int    max_num = 15;

const int delayTime = 1;

int flag          = 1;

int      counter    = 0;

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
    
}//void setup()  

void loop()
{ 
      if (counter < 10) {
        
          digitalWrite(unit_num[0], HIGH);
          digitalWrite(unit_num[1], LOW);
          display_number(counter);
          delay(500);

          counter += 1;
          
      } else if (counter >= 10 && counter < max_num) {
          
          display_number_10s(counter);
          counter += 1;
          
      } else {
          
          counter = 0;
          
      }//if (counter < 10) {
		
}//void loop()

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

void display_number_10s (int n) {
    int d10 = n % 10;
    int d1  = n - (n * 10);
    
    for(int i = 0; i < 5000; i++) {
	    // digits[n]の各ビットを調べて対応するセグメントを点灯・消灯する
	    digitalWrite(unit_num[0], HIGH);
	    digitalWrite(unit_num[1], LOW);
	    
	    digitalWrite(LED_a, digits[d1] & 0b00000001 ? HIGH : LOW);
	    digitalWrite(LED_b, digits[d1] & 0b00000010 ? HIGH : LOW);
	    digitalWrite(LED_c, digits[d1] & 0b00000100 ? HIGH : LOW);
	    digitalWrite(LED_d, digits[d1] & 0b00001000 ? HIGH : LOW);
	    digitalWrite(LED_e, digits[d1] & 0b00010000 ? HIGH : LOW);
	    digitalWrite(LED_f, digits[d1] & 0b00100000 ? HIGH : LOW);
	    digitalWrite(LED_g, digits[d1] & 0b01000000 ? HIGH : LOW);
	    
            delay(5);
            
	    digitalWrite(unit_num[0], LOW);
	    digitalWrite(unit_num[1], HIGH);
	    
	    digitalWrite(LED_a, digits[d10] & 0b00000001 ? HIGH : LOW);
	    digitalWrite(LED_b, digits[d10] & 0b00000010 ? HIGH : LOW);
	    digitalWrite(LED_c, digits[d10] & 0b00000100 ? HIGH : LOW);
	    digitalWrite(LED_d, digits[d10] & 0b00001000 ? HIGH : LOW);
	    digitalWrite(LED_e, digits[d10] & 0b00010000 ? HIGH : LOW);
	    digitalWrite(LED_f, digits[d10] & 0b00100000 ? HIGH : LOW);
	    digitalWrite(LED_g, digits[d10] & 0b01000000 ? HIGH : LOW);

            delay(5);
            
    }//for(int i = 0; i < 1000; i++) {
	
}//void display_number_10s (int n) {

void set_units(int x) {
    switch (x) {
       case 1:
           digitalWrite(unit_num[0], HIGH);
           digitalWrite(unit_num[1], LOW);
           digitalWrite(unit_num[2], LOW);
           
           break; 

       case 2:
           digitalWrite(unit_num[0], HIGH);
           digitalWrite(unit_num[1], HIGH);
           digitalWrite(unit_num[2], LOW);

           break; 
       case 3:
           digitalWrite(unit_num[0], HIGH);
           digitalWrite(unit_num[1], HIGH);
           digitalWrite(unit_num[2], HIGH);
     
          break; 
       
       default:
           break;
          
    }
  
}//void set_units(int x) {

