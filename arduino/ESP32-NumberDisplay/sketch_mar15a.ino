#include <WiFi.h>
#include <WebServer.h>

#include <HTTPClient.h>
//#define led 12  //テスト

const char* ssid = "*****";
const char* pwwd = "*****";
String host = "GASのデプロイ先";
int count = 0;
int SW=1;
bool flg=false;

WebServer server(80);
void setup() {
  pinMode(5,INPUT);
  //シリアルポート設定
  Serial.begin(115200);
  //pinMode(led, OUTPUT);
  //digitalWrite(led, LOW);
  WiFi.begin(ssid, pwwd);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());

  server.on("/", handleLedOnOff);
  server.onNotFound(handleNotFound);

  server.begin();
}

void loop() {
  SW = digitalRead(5);
  if (SW == 0 && flg == true) {
    count++;  // 障害物センサが検知された場合に count を増加させる
    flg = false;
  } else if (SW == 1) {
    flg = true;
  }
  server.handleClient();
  delay(300);
}

void handleLedOnOff() {
  String html;
  html = "<!DOCTYPE html>";
  html += "<html lang='ja'>";
  html += "<meta charset=\"utf-8\">";
  html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
  html += "<head>";
  html+="<meta http-equiv='refresh' content='1'>";  // Add this line
  html += "<title>数値表示メーター</title>";

  html+="<style>";
  html+="h1,h2{";
  html+="text-align:center;";
  html+="}";
  html+=".button-container{";
  html+="text-align:center;";
  html+="}";
  html+="</style>";

  html += "</head>";
  html += "<body>";
  html += "<h1>数値表示メーター</h1>";
  html +="<h2 id='cnt'>"+String(count)+"</h2>";

  html += "<div class='button-container'>";
  html += "<form action='' method='post'>";
  html += "<button type='submit' name='click' value='on'><big>開始<big></button>";
  html += "<button type='submit' name='click' value='off'><big>終了<big></button>";
  html += "<button type='submit' name='click' value='res'><big>リセット<big></button>";
  html += "</form>";
  html += "</div>";

  html += "</body>";
  html += "</html>";
  html += "";
  
  if (server.method() == HTTP_POST) 
  {
    if (server.arg("click").equals("on")) {
      HTTPClient http;
      http.begin(host + "?count=" + count + "&SE=start");
      http.GET();
      //digitalWrite(led, HIGH);
    }
    else if (server.arg("click").equals("off")) {
      HTTPClient http;
      http.begin(host + "?count=" + count + "&SE=end");
      http.GET();
      //digitalWrite(led, LOW);
    }
    else if(server.arg("click").equals("res")){
      count=0;
    }
  }
  server.send(200, "text/html", html);
}

void handleNotFound(void) {
  server.send(404, "text/plain", "Not Found");
}
