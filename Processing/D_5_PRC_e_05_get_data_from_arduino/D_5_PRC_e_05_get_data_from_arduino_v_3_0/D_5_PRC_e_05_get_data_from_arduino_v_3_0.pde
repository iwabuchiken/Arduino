/*
  File: D-5_PRC_e-05_get_data_from_arduino_v_3_0
  Description: Get data from arduino via serial
  Source: 
  
*/
import processing.serial.*;

color c;
PFont font;
Serial port;
String arduinoPort;
String msg = "";

int portAvail = 0;
int portNoAvail = 0;

void setup(){
 

    size(640, 480);
    
    frameRate(10);
    
    fill(255);

    font = loadFont("Gabriola-48.vlw");
    
//    textFont(font, 64);
    textFont(font, 32);

    // Serial
    if(Serial.list().length < 1) {
      
        println("No serial port list");
        arduinoPort = null;
        
        println("Serial.list()=" + Serial.list());
      
    } else {
      
        arduinoPort = Serial.list()[0];
        port = new Serial(this, arduinoPort, 9600);
        
        println("Port opened: " + arduinoPort);
        
        println("port.available()=" + port.available());
        
        println("port.read() => " + port.read());

    }
//    arduinoPort = Serial.list()[0];
//    port = new Serial(this, arduinoPort, 9600);
    
    println("arduinoPort=" + arduinoPort);
    
    
    
}//void setup(){

void draw(){

//    if (port.available > 0 && portAvail == 0) {
      if (port.available() > 0) {
     
//         println("Port => Available");
         
//         String msg = "";
         
//         while (port.available() > 0) {
           
         int inByte = port.read();
         
         if (inByte != 10) {
           
           msg = msg + char(inByte);
           
         } else {
           
           println("inByte => 10");
           
           if (msg.length() > 0) {
            
              println("msg=" + msg);
              
//              fill(100);
//              if (msg.equals("On!")) {
//              if (msg == "On!") {
              if (match(msg, "On!") != null) {
                
                background(0, 164, 0, 50);
                text(msg, 10, 100);
                
//              } else if (msg.equals("On!")) {
              } else if (match(msg, "Off!") != null) {
                
                background(192, 0, 0, 50);
                text(msg, 10, 100);
                
              } else {
                
                background(192, 164, 0, 50);
                text(msg, 10, 100);
              
              }
              msg = "";
           }
           
         }//if (inByte != 10) {
           
//         msg += port.readString();
             
//         }//while (port.available() > 0) {
//         println(port.readString());
//         Serial.flush();
         
//         msg = port.readString();
         
//         println("msg=" + msg);
         
         portAvail = 1;
         portNoAvail = 0;
         
      } else {
      
        if (portNoAvail == 0) {
          
            println("Port => Not available");
            
            portNoAvail = 1;
          
        }
        
      }//if (port.available() > 0) {
  
}//void draw(){

void mousePressed() {
   if(mouseButton == RIGHT) {
     
//     saveFrame("overview-out-####.png");
//     saveFrame("images/overview-3-out-####.png");
      exit();
   
   } else if(mouseButton == LEFT) {

//    if (port != null) {
//      
////      if (msgFlag != 1) {
////        port.clear();      
//  
//        port.write("Go");
//        
//        println("Port written");
//        
//        println("Serial.available() => " + String.valueOf(port.available()));
////        msgFlag = 1;
//        
//        println("port.readString()=>" + port.readString());
////      }//if (msgFlag != 1) {
//      
//        port.clear();
//      
//    } else {
//     
//       println("port => null"); 
//    }//if (port != null) {
//
//   port.clear();
//      
//   } else {
//     
//     background(192, 64, 0);
//     
   }
   
}//void mousePressed() {

