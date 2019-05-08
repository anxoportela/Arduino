#include <Wire.h>
#include "RTClib.h"

DS1302 rtc(2, 3, 4); // Elegimos los pines conectados al RTC (Reset,Datos,Clock).

void setup () {
  Serial.begin(57600);
  Wire.begin();
  rtc.begin();
  if (! rtc.isrunning()) {
    Serial.println("RTC apagado");
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
}

void loop () {
  DateTime now = rtc.now();
  char buf[100];
  strncpy(buf, "DD.MM.YYYY  hh:mm:ss\0", 100);
  Serial.println(now.format(buf));
  delay(1000);
}
