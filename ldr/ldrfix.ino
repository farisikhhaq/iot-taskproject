#include "DHT.h"
#define sensorLDR A0
#define GPIO4 4    
#define DHTTYPE DHT11   // DHT 11
#define LedMerah D3 //D3 pin led merah
#define LedHijau D4 //D4 pin led hijau
#define LedBiru D5 //D5 pin led biru

DHT dht(GPIO4, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("test!");

  pinMode(LedMerah, OUTPUT);
  pinMode(LedHijau, OUTPUT);
  pinMode(LedBiru, OUTPUT);
  
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int a = analogRead(A0);
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print("\t Suhu Dingin \t");
    Serial.print("Humidity: ");
    Serial.println(h);
    Serial.println(" %");
    Serial.print("Intensitas: ");
    Serial.println(a);  
    
  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  if ((a > 500) && (dht.readTemperature() <= 29.80)){
    delay(100);
    digitalWrite(LedBiru, LOW); // Lampu Biru Menyala
    digitalWrite(LedHijau, HIGH); // Lampu Biru Menyala
    digitalWrite(LedMerah, HIGH); // Lampu hijau Mati
  }
  
  else if ((a <= 500) && (dht.readTemperature() > 29.80)){
    delay(100);
    digitalWrite(LedMerah, LOW); // Lampu Merah Mati
    digitalWrite(LedBiru, HIGH); // Lampu Biru Menyala
    digitalWrite(LedHijau, HIGH); // Lampu hijau Mati
  }
  else {
    delay(100);
    digitalWrite(LedMerah, HIGH); // Lampu Merah Mati
    digitalWrite(LedBiru, HIGH); // Lampu Biru Menyala
    digitalWrite(LedHijau, LOW); // Lampu hijau Mati
  }
  delay(1000);
  digitalWrite(LedBiru, HIGH); // Lampu Biru Mati
}
