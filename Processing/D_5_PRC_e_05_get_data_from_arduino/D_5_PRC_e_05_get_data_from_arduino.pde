/*
  File: D-5_PRC_e-05_get_data_from_arduino
  Description: Get data from arduino via serial
  Source: 
  
*/
import processing.serial.*;

color c;
PFont font;
Serial port;
String arduinoPort;
String message;

int msgFlag = 0;

void setup(){
 

    size(640, 480);
    
    frameRate(10);
    
    fill(255);

    font = loadFont("Gabriola-32.vlw");
    
    textFont(font, 64);

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

    background( c );
    
    text("Hello", 10, 100);
    
    text("Hello", 10, 200, -50);
    
//    if (port != null) {
//      
//      if (msgFlag != 1) {
//        
//        port.write("Go");
//        
//        println("Port written");
//        
//        msgFlag = 1;
//        
//      }//if (msgFlag != 1) {
//      
//      
//    } else {
//     
//       println("port => null"); 
//    }//if (port != null) {
    
//    port.clear();
    
}//void draw(){

void mousePressed() {
   if(mouseButton == RIGHT) {
     
//     saveFrame("overview-out-####.png");
//     saveFrame("images/overview-3-out-####.png");
      exit();
   
   } else if(mouseButton == LEFT) {

    if (port != null) {
      
//      if (msgFlag != 1) {
//        port.clear();      
  
        port.write("Go");
        
        println("Port written");
        
        println("Serial.available() => " + String.valueOf(port.available()));
//        msgFlag = 1;
        
        println("port.readString()=>" + port.readString());
//      }//if (msgFlag != 1) {
      
        port.clear();
      
    } else {
     
       println("port => null"); 
    }//if (port != null) {

   port.clear();
      
   } else {
     
     background(192, 64, 0);
     
   }
   
}//void mousePressed() {

