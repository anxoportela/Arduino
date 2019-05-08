const int buttonPin = 5;  // Pin del botón.
const int ledPin =  13;  // Led de la placa arduino.

int buttonState = 0;  // Variable para leer el estado del botón.

void setup() {
  pinMode(ledPin, OUTPUT);  // Iniciar led en modo salida.
  pinMode(buttonPin, INPUT);  // Iniciar el botón en modo entrada
}

void loop() {
  buttonState = digitalRead(buttonPin);  // Leer el estado del botón
  if (buttonState == HIGH) {  // Comprobar si se pulsa el botón. Si se pulsa su estado es "HIGH"
    digitalWrite(ledPin, HIGH);  // Enciende el Led.
  } else {  // No se pulsa el botón. Pasa a estado "LOW"
    digitalWrite(ledPin, LOW);  // Apaga el Led.
  }
}
