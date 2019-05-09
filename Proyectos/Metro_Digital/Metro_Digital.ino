//I2C LCD:
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// LCD I2C address
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int inputPin=4; // pin to read signal from sensor
int outputPin=5; // pin to send  signal to sensor
int ledpin=13;

void setup() {
        Serial.begin(9600);
        lcd.begin(16,2);
        pinMode(ledpin,OUTPUT);
        pinMode(inputPin, INPUT);
        pinMode(outputPin, OUTPUT);
}

void loop(){
        digitalWrite(outputPin, LOW);
        delayMicroseconds(2);
        digitalWrite(outputPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(outputPin, LOW);
        int distance = pulseIn(inputPin, HIGH);
        distance= distance/58;
        Serial.println(distance); //print distance value in cm
        lcd.setCursor(0, 0);
        lcd.print("                ");
        lcd.setCursor(0, 0);
        lcd.print("Distancia: ");
        lcd.print(distance);
        lcd.print("cm");
        lcd.setCursor(0,1);
        lcd.print("");
        delay(50);
        if (distance >=50)
        {// light up LED if distance more than 50cm
                digitalWrite(ledpin,HIGH);
        }// turn off LED if distance less than 50cm
        else
                digitalWrite(ledpin,LOW);
}
