// Bluetoothモジュール HC-05(HC-06) 動作テストスケッチ②
// Arduino(HC-05)←→Arduino(HC-05 or HC-06)間のやり取り！
// https://burariweb.info

#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd( 4, 6, 10, 11, 12, 13 );  //LiquidCrystal(rs, enable, d4, d5, d6, d7)

SoftwareSerial BTserial(2, 3);  // RX | TX

int BTint = 0;
int cnt=0;
bool flg=false;

void setup() 
{
  lcd.begin( 16, 2 );
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(0);
  BTserial.begin(9600);

}

void loop()
{

    if (BTserial.available())
    {
c:\Users\kotaromatsuo\デスクトップ\NumberDisplay_detection\NumberDisplay_detection.ino        BTint = BTserial.read();

        if(BTint == 'U'&& flg==true){
          cnt++;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print(cnt);
          flg=false;
          delay(600);
        }else if(BTint=='S'){
          flg=true;
        }
    }
    

}