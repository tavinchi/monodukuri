//ESP32 Lesson 05 WebServerクラスを使ったWiFi経由のLED On/OFF
//https://omoroya.com/

#include <WiFi.h>
#include <WebServer.h>

//アクセスポイント情報
const char* ssid = "JCOM_ISEJ";        //ssidを入力
const char* passwd = "170617282143";      //ネットワークパスワード入力

//WebServerクラス
WebServer server(80);                     //通信を受けるポート番号（通常は80に設定）

// Motor A
int motor1Pin1 = 26; 
int motor1Pin2 = 27; 
int enable1Pin = 14; 

// Motor B
int motor2Pin1 = 25; 
int motor2Pin2 = 33; 
int enable2Pin = 32; 

// Setting PWM properties
const int freq = 30000;
const int pwmChannel1 = 0;
const int pwmChannel2 = 1;
const int resolution = 8;
int dutyCycle = 255;

void setup() {
  // sets the pins as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
  
  // configure LED PWM functionalities
  ledcSetup(pwmChannel1, freq, resolution);
  ledcSetup(pwmChannel2, freq, resolution);
  
  // attach the channels to the GPIOs to be controlled
  ledcAttachPin(enable1Pin, pwmChannel1);
  ledcAttachPin(enable2Pin, pwmChannel2);

  //シリアルポート設定
  Serial.begin(115200);                   //シリアル通信のデータ転送レートを115200bpsで指定
  WiFi.begin(ssid, passwd);               //アクセスポイント接続のためのIDとパスワードの設定
  while (WiFi.status() != WL_CONNECTED) { //接続状態の確認
    delay(300);                           //接続していなければ0.3秒待つ
    Serial.print(".");                    //接続しなかったらシリアルモニタに「.」と表示
  }

  //通信が可能となったら各種情報を表示する
  Serial.println("");                     //シリアルモニタ改行
  Serial.println("WiFi Connected");       //接続したらシリアルモニタに「WiFi Connected」と表示
  Serial.print("IP Address : ");          //シリアルモニタに表示
  Serial.println(WiFi.localIP());         //割り当てられたIPアドレスをシリアルモニタに表示

  //serverにアクセスしたときの処理関数
  server.on("/", car);         //TOPページのアドレスにアクセスしたときの処理関数
  server.onNotFound(handleNotFound);      //存在しないアドレスにアクセスしたときの処理関数
  
  //WebServerを起動、server(80)で作成したサーバー
  server.begin();                         //WebServer起動
}

void loop() {
  ledcWrite(pwmChannel1, dutyCycle);   
  ledcWrite(pwmChannel2, dutyCycle);
  server.handleClient();
}

//TOPページにアクセスしたきの処理関数


//on_offのアドレスにアクセスしたときの処理関数
void car() {
  String html;
  //HTML記述
  html = "<!DOCTYPE html>";
  html += "<html lang='ja'>";
  html += "<meta charset=\"utf-8\">";
  html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
  html += "<head>";
  html += "<title>ラジコン</title>";
  html +="<style>";
  html +="h1{";
  html +="text-align:center;";
  html +="font-size: 50px;";
  html +="}";
  html +="button{";
  html +="margin: 20px; /* ボタンのマージン */";
  html +="padding:40px 80px";
  html +="margin: 20px; /* ボタンのマージン */";
  html +="}";
  html +="p{";
  html +="text-align:center";
  html +="}";
  html +=".button-container {";
  html +="display: flex; /* ボタンを水平に並べる */";
  html+="justify-content: center; /* ボタンを中央揃え */";
  html+="align-items: center; /* ボタンを垂直方向に中央揃え */";
  html+="margin-top: 20px; /* 上側のマージン */";
  html+="}";
  html+=".button-container a { margin: 0 10px; }";
  html+="</style>";
  html += "</head>";
  html += "<body>";
  html += "<h1>ラジコン</h1>";
  html +="<div class='button-container'>";
  html += "<a href=\"/?click=on\"><button style='padding: 30px 60px;'>前</button></a>";   //パラメータの送信
  html += "<a href=\"/?click=off\"><button style='padding: 30px 60px;'>後</button></a>"; //パラメータの送信
  html += "<a href=\"/?click=stop\"><button style='padding: 30px 60px;'>止</button></a>"; //パラメータの送信
  html += "</div>";
  html += "</body>";
  html += "</html>";
  html += "";
  
  if (server.hasArg("click"))                      //clickが送信されたかどうかの確認
  {
    //前
    if (server.arg("click").equals("on"))          
    {
      Serial.println("前");
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH); 
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH); 
      delay(700);
    }
    //後ろ
    else if (server.arg("click").equals("off"))
    {
      Serial.println("後");
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW); 
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW); 
      delay(700);
    }
    //止める
    else if (server.arg("click").equals("stop"))
    {
      Serial.println("止");
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      delay(700);
    }
  }
  server.send(200, "text/html", html);
}

//存在しないアドレスへアクセスしたときの処理関数
void handleNotFound(void) {
  server.send(404, "text/plain", "Not Found");
}
