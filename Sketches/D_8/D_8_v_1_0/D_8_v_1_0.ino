/*
  File: D_8_v_10
  Behavior: 7-seg LED
  Ports used:

  Date: 2013/05/03 20:15:36

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
    
    //pinMode(LED, OUTPUT);
    
}

void loop()
{
	// Digit 1
	digitalWrite(LED_a, HIGH);
	digitalWrite(LED_b, HIGH);
	digitalWrite(LED_c, HIGH);

	digitalWrite(LED_d, HIGH);
	digitalWrite(LED_e, HIGH);
	digitalWrite(LED_f, HIGH);

	digitalWrite(LED_g, HIGH);
	digitalWrite(LED_dp, HIGH);

	digitalWrite(digit_1, HIGH);
	digitalWrite(digit_2, LOW);
	digitalWrite(digit_3, LOW);
 
    //digitalWrite(LED, HIGH);
    delay(1000);

	// Digit 2
	digitalWrite(LED_a, HIGH);
	digitalWrite(LED_b, HIGH);
	digitalWrite(LED_c, HIGH);

	digitalWrite(LED_d, HIGH);
	digitalWrite(LED_e, HIGH);
	digitalWrite(LED_f, HIGH);

	digitalWrite(LED_g, HIGH);
	digitalWrite(LED_dp, HIGH);

	digitalWrite(digit_1, LOW);
	digitalWrite(digit_2, HIGH);
	digitalWrite(digit_3, LOW);

    //digitalWrite(LED, LOW);
    delay(1000);
  
}

