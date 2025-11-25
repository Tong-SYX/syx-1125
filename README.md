# ESP32 LED 閃爍程式

## 功能描述
此程式在GPIO22上連接一個LED，使其每秒閃爍1次（1Hz頻率）。

## 硬體需求
- **開發板**：ESP32 (NodeMCU-32S)
- **LED**：標準LED
- **限流電阻**：約220Ω至470Ω
- **GPIO腳位**：GPIO22

## 硬體接線
```
GPIO22 ─── 220Ω電阻 ─── LED正極(長腳)
                        LED負極(短腳) ─── GND
```

## 程式解析

### 包含檔案
```cpp
#include <Arduino.h>
```
引入Arduino框架的標準庫，提供GPIO控制的函數。

### GPIO定義
```cpp
#define LED_PIN 22
```
定義LED連接的GPIO腳位為22，方便後續使用。

### setup() 函數
```cpp
void setup() {
  pinMode(LED_PIN, OUTPUT);
}
```
- 在程式啟動時執行一次
- 設定GPIO22為輸出模式，允許控制LED的狀態

### loop() 函數
```cpp
void loop() {
  digitalWrite(LED_PIN, HIGH);  // 點亮LED
  delay(500);                   // 等待500毫秒
  
  digitalWrite(LED_PIN, LOW);   // 關閉LED
  delay(500);                   // 等待500毫秒
}
```
- 無限循環執行
- **HIGH (HIGH)**：GPIO22輸出高電位（5V/3.3V），點亮LED
- **delay(500)**：延遲500毫秒
- **LOW (LOW)**：GPIO22輸出低電位（0V），關閉LED
- **總週期**：500ms (ON) + 500ms (OFF) = 1秒

## 工作原理
LED以1Hz的頻率閃爍，即每1秒內LED點亮0.5秒，熄滅0.5秒。

## 上傳方法
1. 使用PlatformIO連接ESP32開發板
2. 編譯程式
3. 上傳到開發板
4. LED會自動開始閃爍

## 修改頻率方法
若要改變LED閃爍頻率，修改loop()函數中的delay值：
- 減小delay值 → LED閃爍速度加快
- 增加delay值 → LED閃爍速度減慢
- 公式：頻率(Hz) = 1000 / (LED_ON_TIME + LED_OFF_TIME)

例如，若要每秒閃爍2次（2Hz）：
```cpp
delay(250);  // 改為250毫秒
```
