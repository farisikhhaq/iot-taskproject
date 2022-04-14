#include "DHT.h"
#include "Adafruit_Sensor.h"
#define GPIO4 4    
#define DHTTYPE DHT11 

DHT dht(GPIO4, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");

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

  Serial.print("Humidity: ");
  Serial.print(h);

  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.println(t);

 }