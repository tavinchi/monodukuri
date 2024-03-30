#include <LiquidCrystal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

LiquidCrystal lcd( 4, 6, 10, 11, 12, 13 );

int a,b;
int E_x,E_y,my_x,my_y,cnt_x,lv=0;
int cnt;
bool flg=false;
void setup() {
  b=0;
  randomSeed(analogRead(0));
  //初期化
  Serial.begin(9600);
  lcd.begin( 16, 2 );
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(".");
  cnt_x=15;
  cnt=0;
  E_x=14;
  E_y=0;
  my_x=0;
  my_y=1;
}

void loop() {
  while(flg==false){
    Serial.println(b);
    a=digitalRead(8);
    if(a==0){
      my_y=0;
    }else{
      my_y=1;
    }
    
    lcd.begin( 16, 2 );
    lcd.clear();
    lcd.setCursor(cnt_x, 0);
    lcd.print(cnt);
    lcd.setCursor(E_x, E_y);
    lcd.print(".");
    lcd.setCursor(my_x, my_y);
    lcd.print("h");
    if(E_x==my_x && E_y==my_y){
      lcd.begin( 16, 2 );
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Game Over");
      lcd.setCursor(cnt_x, 0);
      lcd.print(cnt);
      delay(200);
      flg=true;
      break;
    }
    E_x--;
    if(E_x==-1){
      E_x=14;
      // 乱数生成器の初期化
      // 0または1をランダムに生成し、変数E_yに代入
      E_y = random(2);
      Serial.println(E_y);
      
      cnt++;
      if(cnt!=0 && cnt%5==0){
        lv++;
      }
      E_x=E_x-lv;

      if(cnt>99){
        cnt_x=13;
      }else if(cnt>9){
        cnt_x=14;
      }else{
        cnt_x=15;
      }
    }
    delay(200);
  }
  b=digitalRead(7);
  if(b==1){
    cnt_x=15;
    cnt=0;
    E_x=14;
    E_y=0;
    my_x=0;
    my_y=1;
    flg=false;
  }
  
}
