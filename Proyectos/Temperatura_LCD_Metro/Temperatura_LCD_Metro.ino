#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 11
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int inputPin = 4;
int outputPin = 5;

void setup() {
  lcd.begin(16, 2);
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  dht.begin();
}

void loop() {
  digitalWrite(outputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);
  int distance = pulseIn(inputPin, HIGH);
  distance = distance / 58;
  lcd.setCursor(0, 0);
  lcd.print("T: ");
  lcd.print(int(dht.readTemperature()));
  lcd.print("\337C");
  lcd.setCursor(9, 0);
  lcd.print("H: ");
  lcd.print(int(dht.readHumidity()));
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("Distancia: ");
  lcd.print(distance);
  lcd.print("cm");
  delay(1000);
}

