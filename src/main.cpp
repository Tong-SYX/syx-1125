#include <Arduino.h>

#define LED_PIN 22

void setup() {
  // 設定GPIO22為輸出模式
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // 點亮LED
  digitalWrite(LED_PIN, HIGH);
  delay(500);  // 等待0.5秒
  
  // 關閉LED
  digitalWrite(LED_PIN, LOW);
  delay(500);  // 等待0.5秒
  // 總週期：1秒
}

