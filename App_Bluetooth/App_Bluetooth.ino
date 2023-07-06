

#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
#define ledA 3


SoftwareSerial MyBlut(6,7);  // defino los pines que utilizare para el sensor Bluetooth

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

char myChar;
float temp;

void setup() {
  delay(1000);
  Serial.begin(9600);
  MyBlut.begin(9600);
  Serial.println("Ready");
  sensors.begin();
  pinMode(3,OUTPUT);

  
}

void loop() {
  sensors.requestTemperatures();

  temp = sensors.getTempCByIndex(0);

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("°C");

  MyBlut.print(temp);
  MyBlut.println(";");
  delay(100);
 
  LucesLed();
}

void LucesLed(){
if(MyBlut.available() ){
    myChar = MyBlut.read();
    switch (myChar){
      case '1':
      digitalWrite(ledA,HIGH);
      break;
      case '2':
      digitalWrite(ledA,LOW);
      break;
      default:
      MyBlut.println("opccion no valida");
      break;
      }
    }
}
