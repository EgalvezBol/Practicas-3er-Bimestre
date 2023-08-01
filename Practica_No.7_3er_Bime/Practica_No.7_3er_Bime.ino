//Librerias
#include <LiquidCrystal_I2C.h> 
#include <Wire.h> 
#include <MFRC522.h>
#include <SPI.h>
#include <RTClib.h>


//Directivas de preprocesador
#define direccion_lcd 0x26
#define filas 2
#define columnas 16
#define SS_PIN 10
#define RST_PIN 9
#define LED1 3
#define LED2 4

LiquidCrystal_I2C LCD(direccion_lcd, columnas, filas);
MFRC522 RFID(SS_PIN, RST_PIN);
RTC_DS3231 rtc;

enum Estado {
  ESTADO_ESPERA,
  ESTADO_AUTORIZADO,
  ESTADO_NO_AUTORIZADO,
};

Estado estadoActual = ESTADO_ESPERA;
unsigned long ultimoTiempoActualizado = 0;
const unsigned long intervaloActualizacion = 1000; // Actualizar la LCD cada 1 segundo

// Variables para el sensor de corriente
const float Sensibilidad = 0.185;
const int Sensor = A1;

void setup() {
  Serial.begin(9600);
  LCD.init();
  LCD.backlight();
  Wire.begin();
  rtc.begin();
  SPI.begin();
  RFID.PCD_Init();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  // Establecer la hora del RTC (ajustar según sea necesario)
  rtc.adjust(DateTime(2023, 7, 24, 16, 8, 0));
}

void loop() {
  switch (estadoActual) {
    case ESTADO_ESPERA:
      manejarEstadoEspera();
      break;
    case ESTADO_AUTORIZADO:
      manejarEstadoAutorizado();
      break;
    case ESTADO_NO_AUTORIZADO:
      manejarEstadoNoAutorizado();
      break;
    default:
      break;
  }
}

void manejarEstadoEspera() {
  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("  EEGSA  Kinal  ");
  LCD.setCursor(0, 1);
  LCD.print("  Medidor Energía  ");

  // Verificar si hay una nueva tarjeta
  if (RFID.PICC_IsNewCardPresent() && RFID.PICC_ReadCardSerial()) {
    String contenido = obtenerUIDString();
    contenido.toUpperCase();
    
    if (contenido == "13 85 5B AD") {
      estadoActual = ESTADO_AUTORIZADO;
    } else {
      estadoActual = ESTADO_NO_AUTORIZADO;
    }
  }
}

void manejarEstadoAutorizado() {
  DateTime ahora = rtc.now();

  if (millis() - ultimoTiempoActualizado >= intervaloActualizacion) {
    lcd_valores();
    ultimoTiempoActualizado = millis();
  }

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);

  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("Usuario Autorizado");
  LCD.setCursor(0, 1);
  LCD.print("Hora: ");
  imprimirHora(ahora);
}

void manejarEstadoNoAutorizado() {
  digitalWrite(LED2, HIGH);
  digitalWrite(LED1, LOW);

  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("  EEGSA  Kinal  ");
  LCD.setCursor(0, 1);
  LCD.print("Usuario No Autorizado   ");

  delay(1500);

  estadoActual = ESTADO_ESPERA;
}

void lcd_valores() {
  // Valores de voltaje
  float voltaje = (float)25 * analogRead(A1) / 1023;

  // Valores de corriente
  float corriente = obtenerCorriente(200);

  // Valores de potencia
  float potencia = corriente * voltaje;

  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("  EEGSA  Kinal  ");
  LCD.setCursor(0, 1);
  LCD.print(voltaje, 1);
  LCD.print("V ");
  LCD.print(corriente, 1);
  LCD.print("A ");
  LCD.print(potencia, 1);
  LCD.print("W ");
}

String obtenerUIDString() {
  String contenido = "";
  for (byte i = 0; i < RFID.uid.size; i++) {
    contenido.concat(String(RFID.uid.uidByte[i] < 0x10 ? " 0" : " "));
    contenido.concat(String(RFID.uid.uidByte[i], HEX));
  }
  return contenido;
}

void imprimirHora(DateTime hora) {
  LCD.print(hora.hour(), DEC);
  LCD.print(":");
  LCD.print(hora.minute(), DEC);
  LCD.print(":");
  LCD.print(hora.second(), DEC);
}
