#include "DHT.h"
/*#define DHTPIN D2     */
#define GPIO4 4    
#define DHTTYPE DHT11   // DHT 11
#define LedMerah D3 //D3 pin led merah
#define LedHijau D4 //D4 pin led hijau
#define LedBiru D5 //D5 pin led biru

DHT dht(GPIO4, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  pinMode(LedMerah, OUTPUT);
  pinMode(LedHijau, OUTPUT);
  pinMode(LedBiru, OUTPUT);
  
  dht.begin();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if ((dht.readTemperature() <= 27.50)){

    delay(100);
    digitalWrite(LedBiru, LOW); // Lampu Biru Menyala
    digitalWrite(LedHijau, HIGH); // Lampu Biru Menyala
    digitalWrite(LedMerah, HIGH); // Lampu hijau Mati
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print("\t Suhu Dingin \t");
    Serial.print("Humidity: ");
    Serial.println(h);
    Serial.println(" %");
  }
  
  else if ((dht.readTemperature() > 27.50) && (dht.readTemperature() <=28) ){

    delay(100);
    digitalWrite(LedHijau, LOW); // Lampu hijau Mati
    digitalWrite(LedBiru, HIGH); // Lampu Biru Menyala
    digitalWrite(LedMerah, HIGH); // Lampu hijau Mati
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print("\t Suhu Normal \t");
    Serial.print("Humidity: ");
    Serial.println(h);
    Serial.println(" %");
  }
   else if ((dht.readTemperature() > 28)){

    delay(100);
    digitalWrite(LedMerah, LOW); // Lampu Merah Mati
    digitalWrite(LedBiru, HIGH); // Lampu Biru Menyala
    digitalWrite(LedHijau, HIGH); // Lampu hijau Mati
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print("\t Suhu Panas \t");
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.println(" %");

  }
  
  delay(1000);
  digitalWrite(LedMerah, HIGH); // Lampu Merah Mati
    digitalWrite(LedBiru, HIGH); // Lampu Biru Menyala
    digitalWrite(LedHijau, HIGH); // Lampu hijau Mati
  
 }