#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 6      // Pin al que conectamos el sensor
#define DHTTYPE DHT11  // Tipo de sensor utilizado 

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.println("Test de temperatura y humedad");
  dht.begin();
}

void loop() {
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  // Primera linea LCD
  lcd.setCursor(0, 0);
  lcd.print("Temperatura");
  lcd.setCursor(12,0);
  lcd.print(t);
  lcd.print("\337C");
  // Segunda linea LCD
  lcd.setCursor(0, 1);
  lcd.print("Humedad");
  lcd.setCursor(13,1);  
  lcd.print(h);
  lcd.print("%");
  // Informacion puerto serie/usb
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print("C, Humedad: ");
  Serial.print(h);
  Serial.println("%");
}
