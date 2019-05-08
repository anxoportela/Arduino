#include <Wire.h> // Incluímos la librería Wire.
#include <LCD.h> // Incluímos la librería LCD.
#include <LiquidCrystal_I2C.h> // Incluímos la librería I2C para el display.
#include <DS1302.h> // Incluímos la librería para el control del reloj DS1302.

#define I2C_ADDR 0x3F // Definimos una variable global de la dirección del display.
Time t; // Definimos la variable "t" para guardar los datos.

DS1302 rtc(4, 3, 2); // Elegimos los pines conectados al RTC (RST,DAT,CLK).
LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7); // Elegimos la dirección y los pines que conectarían al display si no fuera I2C.

void setup()
{
  Wire.begin(); // Inicializamos el bus I2C.
  rtc.halt(false); // Inicializamos el RTC.
  rtc.writeProtect(true); // Activamos la protección contra escritura.
  lcd.begin (16, 2);   // Inicializamos el display con 16 caraceres y 2 líneas.
  lcd.setBacklightPin(3, POSITIVE); // Activamos la luz de encendido del display, en este caso en el pin 3.
  lcd.setBacklight(HIGH); // Pin 3 encendido.
}

void loop()
{
  t = rtc.getTime(); // Inicializamos la variable "t" que creamos antes para que nos muestre los datos de tiempo recogidos por el RTC.

  lcd.setCursor(0, 0); // Nos colocamos para escribir en la parte superior del display.
  if (t.dow == 1) lcd.print("Lun");  // La variable t.dow (día de la semana) tendrá valor 1 para Lun y 7 para Dom.
  if (t.dow == 2) lcd.print("Mar");
  if (t.dow == 3) lcd.print("Mie");
  if (t.dow == 4) lcd.print("Jue");
  if (t.dow == 5) lcd.print("Vie");
  if (t.dow == 6) lcd.print("Sab");
  if (t.dow == 7) lcd.print("Dom");
  lcd.print(" ,");
  lcd.print(" ");
  print2digits(t.date);  // Día.
  lcd.print("/");
  print2digits(t.mon); // Mes.
  lcd.print("/");
  lcd.print(t.year);  // Año.

  lcd.setCursor(4, 1); // Nos colocamos para escribir en el led 5 de la parte inferior del display.
  print2digits(t.hour);  // Hora en formato 00-23.
  lcd.print(":");
  print2digits(t.min);  // Minutos en formato 00-59.
  lcd.print(":");
  print2digits(t.sec);  // Segundos en formato 00-59.
  delay(1000);  // Delay para presentar los datos en pantalla, cada segundo.
  lcd.clear(); // Refresco de pantalla.
}

// Función para añadir un "0" delante de los números con dígito simple

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    lcd.write('0');
  }
  lcd.print(number);
}
