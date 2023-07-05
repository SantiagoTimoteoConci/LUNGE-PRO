#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(2, 3);  // Define los pines de comunicación serial

void setup() {
  Serial.begin(9600);           // Inicializa el puerto serial del Arduino
  bluetoothSerial.begin(9600);  // Inicializa el puerto serial para la comunicación con el módulo Bluetooth

  pinMode(LED_BUILTIN, OUTPUT);  // Configura el pin del LED incorporado como salida
}

void loop() {
  if (bluetoothSerial.available()) {  // Verifica si hay datos disponibles en el puerto serial del módulo Bluetooth
    char data = bluetoothSerial.read();  // Lee el dato recibido
  
    if (data == '1') {
      digitalWrite(LED_BUILTIN, HIGH);  // Enciende el LED incorporado si recibe el carácter '1'
    } else if (data == '0') {
      digitalWrite(LED_BUILTIN, LOW);   // Apaga el LED incorporado si recibe el carácter '0'
    }
  }

  if (Serial.available()) {          // Verifica si hay datos disponibles en el puerto serial del Arduino
    char data = Serial.read();       // Lee el dato recibido desde la aplicación de React Native
    bluetoothSerial.write(data);     // Envía el dato al módulo Bluetooth
  }
}
