/*
  File: D_16_v_1_0_e_1
  Behavior: 7-seg LED
  Ports used:

  Date: 2013/06/05 14:32:38

*/

void setup(){
  //特になし
}

void loop(){
  //可変抵抗器の値を読み込み４で割る
  int val=analogRead(0)/4;
  //アナログ出力
  analogWrite(3,val); //0~255
  //0.05秒ループにする
  delay(20);
}
