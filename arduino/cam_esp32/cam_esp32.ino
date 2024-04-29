#include <WiFi.h>
#include "esp_camera.h"
#define CAMERA_MODEL_WROVER_KIT
#include "camera_pins.h"
#include <TridentTD_LineNotify.h>

//sensorPin
const int sensorPin=33;

// Wi-Fi
const char* ssid     = "JCOM_ISEJ";
const char* password = "170617282143";
// Notify
const char* token = "XTAJxwtcNODXAihg4hjWbpxo5kVqLI0cTE7HsyE1WcB";

void setup() {
  pinMode(sensorPin,INPUT);
  Serial.begin(115200);
  if (cameraSetup()==1) {
  // LED onなど
     } else {
      return;
  }
  WiFi.begin(ssid, password);
  Serial.print("WiFi connecting to ");
  while(WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
  delay(500);
  }
  Serial.println("");
  Serial.println(WiFi.localIP());  
  LINE.setToken(token);
  }

void loop() {
  if(digitalRead(sensorPin)==0){
    delay(1000);
    Camera_capture();
  }

  delay(500); 
}

void Camera_capture() {
  camera_fb_t * fb = NULL;
  delay(200); 
  // 撮影処理
  fb = esp_camera_fb_get(); 
  if(!fb) {
    Serial.println("撮影失敗");
    return;
  }
   Send_line(fb->buf,fb->len);
   esp_camera_fb_return(fb); 
  }

void Send_line(uint8_t *image_data,size_t   image_size){
   LINE.notifyPicture("ESPCAMから画像送信",image_data, image_size);
   Serial.println("送信完了");
  }

 int cameraSetup() {
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.frame_size = FRAMESIZE_UXGA;
  config.pixel_format = PIXFORMAT_JPEG; // for streaming
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 12;
  config.fb_count = 1;
  // if PSRAM IC present, init with UXGA resolution and higher JPEG quality
  // for larger pre-allocated frame buffer.
  if(psramFound()){
    config.jpeg_quality = 10;
    config.fb_count = 2;
    config.grab_mode = CAMERA_GRAB_LATEST;
  } else {
  // Limit the frame size when PSRAM is not available
    config.frame_size = FRAMESIZE_SVGA;
    config.fb_location = CAMERA_FB_IN_DRAM;
  }
  
  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("カメラの初期化に失敗しました：", err);
    return 0;
  }

  sensor_t * s = esp_camera_sensor_get();
    //s->set_vflip(s, 1); // 撮影画像の反転　※画像が反転する場合はコメントアウトを消去
  s->set_brightness(s, 1); // 撮影画像の明るさ
  s->set_saturation(s, 0); // 撮影画像の彩度

  Serial.println("カメラの設定が完了しました");
    return 1;
 }
