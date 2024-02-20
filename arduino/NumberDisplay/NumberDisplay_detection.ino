// Bluetoothモジュール HC-05(HC-06) 動作テストスケッチ②
// Arduino(HC-05)←→Arduino(HC-05 or HC-06)間のやり取り！
// https://burariweb.info

#include <SoftwareSerial.h>

SoftwareSerial BTserial(2, 3);  // RX | TX
int SW = 1;

void setup() 
{
  pinMode(8,INPUT);
  BTserial.begin(9600);
  Serial.begin(9600);

}

void loop()
{
    SW = digitalRead(8);
    Serial.println(SW);
    
    if(SW == 0){
      BTserial.write('U');
    } else if(SW == LOW){
      BTserial.write('S');
    }
    
    delay(300);

}