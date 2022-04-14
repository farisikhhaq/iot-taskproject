#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "time.h"
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "DHT.h"
#define DHTread D6
#define DHTTYPE DHT11   // DHT 11
#define LedMerah D3 //D3 pin led merah
#define LedHijau D4 //D4 pin led hijau
#define LedBiru D5 //D5 pin led biru

LiquidCrystal_I2C lcd (0x27, 16,2);  //pengenalan alamat i2c
const char *ssid       = "INNOVATE BELAKANG";   //Replace with your own SSID
const char *password   = "puring11belakang";  //Replace with your own password
const long utcOffsetInSeconds = 25200;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);
DHT dht(DHTread, DHTTYPE);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();         
  lcd.backlight();
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  timeClient.begin();
  Serial.println("CONNECTED to WIFI");
  Serial.println("DHTxx test!");
  pinMode(LedMerah, OUTPUT);
  pinMode(LedHijau, OUTPUT);
  pinMode(LedBiru, OUTPUT);
  dht.begin();
}

void loop() {
  delay(2000);
  timeClient.update();
  unsigned long epochTime = timeClient.getEpochTime();
  struct tm *ptm = gmtime ((time_t *)&epochTime);
  int cYear = ptm->tm_year+1900;
  int cMonth = ptm->tm_mon+1;
  int cDay = ptm->tm_mday;
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  float f = ( t * 1.8 ) + 32;
  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  if ((dht.readTemperature() <= 27.50)){
    delay(100);
    digitalWrite(LedBiru, HIGH); // Lampu Biru Menyala
    digitalWrite(LedHijau, LOW); // Lampu Biru Menyala
    digitalWrite(LedMerah, HIGH); // Lampu hijau Mati
    Serial.print("Celcius: ");
    Serial.print(t);
    Serial.print("°C ");
    Serial.print("Fahrenheit: ");
    Serial.print(f);
    Serial.print("°F ");
    Serial.print("|Suhu Dingin|");
    Serial.print(" Humidity: ");
    Serial.print(h);
    Serial.println(" %");
  }
  else if ((dht.readTemperature() > 27.50) && (dht.readTemperature() <=28) ){
    delay(100);
    digitalWrite(LedHijau, HIGH); // Lampu hijau Mati
    digitalWrite(LedBiru, LOW); // Lampu Biru Menyala
    digitalWrite(LedMerah, HIGH); // Lampu hijau Mati
    Serial.print("Celcius: ");
    Serial.print(t);
    Serial.print("°C ");
    Serial.print("Fahrenheit: ");
    Serial.print(f);
    Serial.print("°F ");
    Serial.print("|Suhu Normal|");
    Serial.print(" Humidity: ");
    Serial.print(h);
    Serial.println(" %");
  }
   else if ((dht.readTemperature() > 28)){
    delay(100);
    digitalWrite(LedMerah, LOW); // Lampu Merah Mati
    digitalWrite(LedBiru, HIGH); // Lampu Biru Menyala
    digitalWrite(LedHijau, HIGH); // Lampu hijau Mati
    Serial.print("Celcius: ");
    Serial.print(t);
    Serial.print("°C ");
    Serial.print("Fahrenheit: ");
    Serial.print(f);
    Serial.print("°F ");
    Serial.print("|Suhu Panas|");
    Serial.print(" Humidity: ");
    Serial.print(h);
    Serial.println(" %");
  }
  Serial.print("Tanggal: ");
  Serial.print(cDay);
  Serial.print("-");
  Serial.print(cMonth);
  Serial.print("-");
  Serial.print(cYear);
  Serial.print(" ");
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(" ");
  lcd.setCursor(0, 0);
  lcd.print(t);
  lcd.print(" C ");
  lcd.setCursor(9, 0);
  lcd.print(f);
  lcd.print(" F");
  lcd.setCursor(0, 1);
  lcd.print(cDay);
  lcd.print("-");
  lcd.print(cMonth);
  lcd.print("-");
  lcd.print(cYear);
  lcd.print(" ");
  lcd.print(" ");
  lcd.print(timeClient.getHours());
  lcd.print(":");
  lcd.print(timeClient.getMinutes());
  delay(1000);
  digitalWrite(LedMerah, HIGH); // Lampu Merah Mati
  digitalWrite(LedBiru, HIGH); // Lampu Biru Menyala
  digitalWrite(LedHijau, HIGH); // Lampu hijau Mati
 }

 
