#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DS1302.h>
#include "DHT.h"

#define I2C_ADDR 0x3F
#define DHTPIN 6
#define DHTTYPE DHT11

DS1302 rtc(4, 3, 2);
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int buttonState = 0;
Time f;
const int buttonPin = 5;

void setup() {
  pinMode(buttonPin, INPUT);
  Wire.begin();
  rtc.halt(false);
  rtc.writeProtect(false);
//  Descomentar las siguientes tres lineas la primera vez para poner el reloj en hora.
//  Resubir el sketch con ellas comentadas para que no se reescriba.   
//rtc.setDOW(THURSDAY);        // Día de la semana en inglés
//rtc.setTime(1, 40, 45);     // Hora tipo (h, m, s) en formato 24h
//rtc.setDate(28, 6, 2018);   // Fecha tipo (d, m, a)
  lcd.begin (16, 2);
  dht.begin();
}

void loop() {
  f = rtc.getTime();
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperatura");
    lcd.setCursor(12, 0);
    lcd.print(t);
    lcd.print("\337C");
    lcd.setCursor(0, 1);
    lcd.print("Humedad");
    lcd.setCursor(13, 1);
    lcd.print(h);
    lcd.print("%");
    delay(5000);
    lcd.clear();
  } else {
    lcd.setCursor(0, 0);
    if (f.dow == 1) lcd.print("Lun");
    if (f.dow == 2) lcd.print("Mar");
    if (f.dow == 3) lcd.print("Mie");
    if (f.dow == 4) lcd.print("Jue");
    if (f.dow == 5) lcd.print("Vie");
    if (f.dow == 6) lcd.print("Sab");
    if (f.dow == 7) lcd.print("Dom");
    lcd.print(" ,");
    lcd.print(" ");
    print2digits(f.date);
    lcd.print("/");
    print2digits(f.mon);
    lcd.print("/");
    lcd.print(f.year);
    lcd.setCursor(4, 1);
    print2digits(f.hour);
    lcd.print(":");
    print2digits(f.min);
    lcd.print(":");
    print2digits(f.sec);
    delay(1000);
  }
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    lcd.write('0');
  }
  lcd.print(number);
}
