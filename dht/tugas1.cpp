#include "DHT.h"
/*#define DHTPIN D2     */
#define GPIO4 4
#define DHTTYPE DHT11 // DHT 11
DHT dht(GPIO4, DHTTYPE);
void setup()
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  dht.begin();
}
void loop()
{
  delay(2000);
  float converted = 0.00;
  float h = dht.readHumidity();
  float temp = dht.readTemperature();

  if (isnan(h) || isnan(temp))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.println("");  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %\t");
  Serial.print("Celcius: ");
  Serial.print(temp);
  Serial.println(" °C ");
  
  // Reamur
  // T(°R) = (T(°C) + 273.15) × 9/5
  converted = temp + 273.15;
  converted = (converted * 1.8);
  Serial.print("Reamur = ");
  Serial.print(converted);
  Serial.println(" °R ");

  //Fahrenheit
  //T(°F) = T(°C) × 9/5 + 32
  converted = ( temp * 1.8 ) + 32;
  Serial.print("Farehneit = ");
  Serial.print(converted);
  Serial.println(" °F "); 

  // Kelvin
  // T(K) = T(°C) + 273.15
  converted = temp + 273.15;
  Serial.print("Kelvin = ");
  Serial.print(converted);
  Serial.println(" K "); 
  
}