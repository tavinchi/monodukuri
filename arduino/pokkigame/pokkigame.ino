int currentNumber = 0; // 現在の数値を保持する変数
bool switchPressed = false; // スイッチが押されたかどうかのフラグ

// ドレミの周波数を設定
int frequency_do = 261; // ド（C）
int frequency_re = 293; // レ（D）
int frequency_mi = 329; // ミ（E）

int duration = 200;  // 持続時間（ミリ秒）



// LEDをオン・オフする際の出力
#define DIGIT_ON LOW
#define DIGIT_OFF HIGH
#define SEGMENT_ON HIGH
#define SEGMENT_OFF LOW

const int digitPins[] = {13,7};                                        // ディジット(コモン)に接続するArduinoのピン
const int segmentPins[] = {12, 8, 5, 3, 2, 10, 6};                             // セグメントピンに接続するArduinoのピン
const int numberOfDigitPins = sizeof(digitPins) / sizeof(digitPins[0]);        // ディジットの数
const int numberOfSegmentPins = sizeof(segmentPins) / sizeof(segmentPins[0]);  // セグメントの数
int numbersToDisplay = 0;                                                      // LEDに表示する数字を保持する変数

int a;
int pinNo=4;
bool flg=true;

// 数字と表示させるセグメントの関係
const int digits[] = {
    0b00111111,  // 0
    0b00000110,  // 1
    0b01011011,  // 2
    0b01001111,  // 3
    0b01100110,  // 4
    0b01101101,  // 5
    0b01111101,  // 6
    0b00100111,  // 7
    0b01111111,  // 8
    0b01101111,  // 9
};

// 数字を表示する
void displayNumber(int n) {
  // digits[n]の各ビットを調べて対応するセグメントを点灯・消灯する
  for (int i = 0; i < numberOfSegmentPins; i++) {
    digitalWrite(segmentPins[i], digits[n] & (1 << i) ? SEGMENT_ON : SEGMENT_OFF);

  }
}

// セグメントをすべてオフにする
void clearSegments() {
  for (int j = 0; j < numberOfSegmentPins; j++) {
    digitalWrite(segmentPins[j], SEGMENT_OFF);
  }
}

// 4桁の数字を表示する
void displayNumbers() {
    static int n = numberOfDigitPins;
    static int digit = 0;
    int div[] = {1, 10, 100, 1000};

    clearSegments();                            // セグメントをすべてオフにする
    digitalWrite(digitPins[digit], DIGIT_OFF);  // ディジットをオフにする
    digit = (digit + 1) % numberOfDigitPins;    // 次のディジットを求める
    if (digit == 0) {
        n = numbersToDisplay;  // numberToDisplayの値を書き換えないために変数にコピー
    }
    digitalWrite(digitPins[digit], DIGIT_ON);   // ディジットをオンにする
    displayNumber((n / div[digit]) % 10);       // ディジットに対応する数字を表示する
}

// 表示する数字をセットする
void setNumbers(int n) {
  numbersToDisplay = n;
}

// setup()　は，最初に一度だけ実行される
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < numberOfDigitPins; i++) {
    pinMode(digitPins[i], OUTPUT);  // digitPinsを出力モードに設定する
    digitalWrite(digitPins[i], DIGIT_OFF);
  }
  for (int i = 0; i < numberOfSegmentPins; i++) {
    pinMode(segmentPins[i], OUTPUT);  // segmentPinsを出力モードに設定する
  }

  // f = クロック周波数 / ( 分周比　*　255 * 2)
  // 分周比=64, 比較レジスタの1値=255 -> f = 16000000 / (64 * 255 * 2) = 490 Hz
  OCR2A = 255;                  // 255クロックごとに割り込みをかける
  TCCR2B = 0b100;               // 分周比を32に設定する
  bitWrite(TIMSK2, OCIE2A, 1);  // TIMER2を許可する
}

void loop() {
  for (int i = currentNumber; i < 100; i++) {
    setNumbers(i);
    delay(100);
    if (digitalRead(9) == 1) {
      delay(10);
      if(i==11){
        // ドの音を生成
        analogWrite(pinNo, 128); // 50%デューティサイクルでPWMを生成
        delay(duration);
        analogWrite(pinNo, 0);   // PWMを停止
        delay(50);  // PWMの間隔

        // レの音を生成
        analogWrite(pinNo, 128); // 50%デューティサイクルでPWMを生成
        delay(duration);
        analogWrite(pinNo, 0);   // PWMを停止
        delay(50);  // PWMの間隔

        // ミの音を生成
        analogWrite(pinNo, 128); // 50%デューティサイクルでPWMを生成
        delay(duration);
        analogWrite(pinNo, 0);   // PWMを停止
        delay(50);  // PWMの間隔
      }
      delay(1000);
      while(true){
        if(digitalRead(9)==1){
          break;
        }
      }
      delay(100);
      break;
    }
    delay(900);
  }
}

ISR(TIMER2_COMPA_vect) {
  displayNumbers();
}
