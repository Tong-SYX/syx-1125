#include <Arduino.h>
#include "DHT.h"

// DHT 設定
#define DHTPIN 22        // DHT11 資料線連接到 GPIO22
#define DHTTYPE DHT11    // DHT11 感應器類型
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // 初始化串列通訊（波特率115200）
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n\n=== DHT11 溫濕度偵測程式 ===");
  
  // 初始化 DHT11 感應器
  dht.begin();
  Serial.println("DHT11 已初始化，開始偵測...");
  Serial.println("偵測周期：3 秒\n");
}

void loop() {
  // 讀取溫度和濕度
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  // 檢查讀取是否成功
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("ERROR: 無法讀取DHT11感應器！");
  } else {
    // 顯示讀取結果
    Serial.print("濕度: ");
    Serial.print(humidity, 2);
    Serial.print("% | 溫度: ");
    Serial.print(temperature, 2);
    Serial.println("°C");
  }
  
  // 等待 3 秒後再偵測一次
  delay(3000);
}

