#include <Servo.h>

/*
  File: D_16_v_2_0_e_1_servo_with_lib
  Behavior: 7-seg LED
  Ports used:

  Date: 2013/06/06 11:07:55

*/

Servo servo;//サーボのインスタンス

void setup(){
  //サーボの信号線を３番ピンに接続
  //（PWMピン以外のピンにも接続可）
  servo.attach(3);
  
  Serial.begin(9600);
  
}

void loop(){
  //センサの読み取り値
  int val=analogRead(0);
  //map()を使って0~1023のセンサ読取り値を0~180の角度に変換
  int deg=map(val,0,1023,0,180);
  //サーボ出力
  servo.write(deg);//0~180まで
  
  Serial.print("deg=");
  Serial.println(String(deg));
  
}

