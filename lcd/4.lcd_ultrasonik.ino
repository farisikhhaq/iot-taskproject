#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define trigger_pin 15 //D8
#define Echo_pin 13 //D7
LiquidCrystal_I2C lcd (0x27, 16,2);  //pengenalan alamat i2c
long duration;
int distance;
void  setup () {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();         
  lcd.backlight();
  pinMode(trigger_pin, OUTPUT); 
  pinMode(Echo_pin, INPUT); 
}
void  loop () {
  digitalWrite(trigger_pin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);          
  digitalWrite(trigger_pin, LOW); 
  duration = pulseIn(Echo_pin, HIGH); // save waktu durasi parsing data
  distance= duration*0.034/2; //ubahdurasi ke jarak
  lcd.setCursor(1, 1);
  lcd.print("Tes Ultrasonik");
  lcd.setCursor(1, 0);
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.print("   cm");

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);
}
