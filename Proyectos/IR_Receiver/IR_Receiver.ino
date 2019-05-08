//I2C LCD:
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// LCD I2C address
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
#include <IRremote.h>
int input_pin = 10; //set D10 as input signal pin
IRrecv irrecv(input_pin);
decode_results signals;
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  irrecv.enableIRIn(); // enable input from IR receiver
}
void loop() {
if (irrecv.decode(&signals)) {
    Serial.println(signals.value, HEX);
    lcd.setCursor(0, 0);
    lcd.print(signals.value, HEX);
    lcd.setCursor(0,1);
    lcd.print("");
    irrecv.resume(); // get the next signal
  }
}
