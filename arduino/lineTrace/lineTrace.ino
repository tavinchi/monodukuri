int target=0;
int black=0;
int white=0;
int getBrightness=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(A0,INPUT);

  pinMode(2,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

  //キャリブレーション
  calibration();
}

void loop() {
  getBrightness=analogRead(A0);
  if(getBrightness>target){
    turnRight();
  }else{
    turnLeft();
  }
}

void turnRight(){
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(10);
}

void turnLeft(){
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  delay(10);
}

void calibration(){
  //led2秒光らす
  digitalWrite(2,HIGH);
  //反射光①取得
  black=analogRead(A0);
  delay(2000);
  digitalWrite(2,LOW);
  delay(2000);

  //led2秒光らす
  digitalWrite(2,HIGH);
  //反射光②取得
  white=analogRead(A0);
  delay(2000);

  //targetを求める
  target=(black + white)/2;
}

void on(int time){
  digitalWrite(2,HIGH);
  delay(time*1000);
}

void off(int time){
  digitalWrite(2,LOW);
  delay(time*1000);
}

void foward(int time){
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  delay(time*1000);
}

void back(int time){
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(time*1000);
}
