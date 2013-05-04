/*
  File: D_8_v_3_0_C_3
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

const int delayTime = 1;

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
//        _digit_1();
        lightUpNum(1, 4);
        delay(delayTime);

	// Digit 2
//        _digit_2();
        lightUpNum(2, 0);
        delay(delayTime);
  
	// Digit 2
        lightUpNum(3, 1);
        delay(delayTime);
  
}

void lightUpNum(int digit, int num)
{
    switch (num) {
        case 0:
                digitalWrite(LED_a,  HIGH);
        	digitalWrite(LED_b,  HIGH);
        	digitalWrite(LED_c,  HIGH);
        
        	digitalWrite(LED_d,  HIGH);
        	digitalWrite(LED_e,  HIGH);
        	digitalWrite(LED_f,  HIGH);
    
        	digitalWrite(LED_g,  LOW);
        	digitalWrite(LED_dp,  HIGH);

           break;
        
        case 1:
                digitalWrite(LED_a,  LOW);
        	digitalWrite(LED_b,  HIGH);
        	digitalWrite(LED_c,  HIGH);
        
        	digitalWrite(LED_d,  LOW);
        	digitalWrite(LED_e,  LOW);
        	digitalWrite(LED_f,  LOW);
    
        	digitalWrite(LED_g,  LOW);
        	digitalWrite(LED_dp,  HIGH);
        
           break;

        case 4:
                digitalWrite(LED_a,  LOW);
        	digitalWrite(LED_b,  HIGH);
        	digitalWrite(LED_c,  HIGH);
        
        	digitalWrite(LED_d,  LOW);
        	digitalWrite(LED_e,  LOW);
        	digitalWrite(LED_f,  HIGH);
    
        	digitalWrite(LED_g,  HIGH);
        	digitalWrite(LED_dp,  HIGH);
        
           break;

        default:
           break; 
      
    }//switch (num) {

    switch (digit) {
        case 1:
        	digitalWrite(digit_1, HIGH);
        	digitalWrite(digit_2, LOW);
        	digitalWrite(digit_3, LOW);
                
                break;
        
	    case 2:
        	digitalWrite(digit_1, LOW);
        	digitalWrite(digit_2, HIGH);
        	digitalWrite(digit_3, LOW);

                break;
                	
	    case 3:
        	digitalWrite(digit_1, LOW);
        	digitalWrite(digit_2, LOW);
        	digitalWrite(digit_3, HIGH);
        
                break;
        
        default:
        
           	digitalWrite(digit_1, HIGH);
        	digitalWrite(digit_2, HIGH);
        	digitalWrite(digit_3, HIGH);

        
    }//switch (digit) {

  
}
void lightUp(int digit)
{
      	digitalWrite(LED_a, HIGH);
      	digitalWrite(LED_b, HIGH);
      	digitalWrite(LED_c, HIGH);
      
      	digitalWrite(LED_d, HIGH);
      	digitalWrite(LED_e, HIGH);
      	digitalWrite(LED_f, HIGH);
  
      	digitalWrite(LED_g, HIGH);
      	digitalWrite(LED_dp, HIGH);

    switch (digit) {
        case 1:
        	digitalWrite(digit_1, HIGH);
        	digitalWrite(digit_2, LOW);
        	digitalWrite(digit_3, LOW);
                
                break;
        
	    case 2:
        	digitalWrite(digit_1, LOW);
        	digitalWrite(digit_2, HIGH);
        	digitalWrite(digit_3, LOW);

                break;
                	
	    case 3:
        	digitalWrite(digit_1, LOW);
        	digitalWrite(digit_2, LOW);
        	digitalWrite(digit_3, HIGH);
        
                break;
        
        default:
        
           	digitalWrite(digit_1, HIGH);
        	digitalWrite(digit_2, HIGH);
        	digitalWrite(digit_3, HIGH);

        
    }//switch (digit) {

//	digitalWrite(digit_1, HIGH);
//	digitalWrite(digit_2, LOW);
//	digitalWrite(digit_3, LOW);  
}//void digit_1()

