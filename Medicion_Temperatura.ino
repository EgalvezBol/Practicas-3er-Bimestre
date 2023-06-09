/*Fundación Kinal
 * Centro Educativo Tecnico Laboral Kinal
 * Electrónica 
 * Grado: Quiinto
 * Sección:A
 * Curso: Taller de Electrónoca Digital y Reparación de Computadoras I
 * Nombre: Edgar Emnauel Gálvez Bol
 * Carné: 2019253
 */

//Inluyo librearias
#include <OneWire.h>                
#include <DallasTemperature.h>
#include <Ticker.h>

#define boton 6

//Variables
volatile static bool Medicion;
  
//Funciones
void Temperatura(void);
void Boton(void);

//Constructores
OneWire myWire(4);                //Se dicta o establece que el pin 4 lo utilizaremos para el protocolo OneWire
DallasTemperature sensor(&myWire); //Se declara una objeto para nuestro sensor
Ticker accionTemperatura(Temperatura, 3000);
Ticker accionBoton(Boton, 6000);

void setup() {
  Serial.begin(9600);
  pinMode(boton, INPUT);
  sensor.begin();
  accionTemperatura.start();
  accionBoton.start();
  Serial.println("Inicia la Medicion");
}

void loop() {
accionTemperatura.update();
accionBoton.update();
}

void Temperatura(void){
  sensor.requestTemperatures();   //Se envía el comando para leer la Temperaturaeratura
  float Temperatura = sensor.getTempCByIndex(0); //Se obtiene la Temperaturaeratura en ºC
  Serial.print("*****");  
  Serial.print("La Temperatura es: ");  
  Serial.print(Temperatura);
  Serial.print(" C ");  
  Serial.println("*****");
  }
  
void Boton(void){
  Medicion = digitalRead(boton);
  if(Medicion == HIGH){
    Serial.println("//// Boton Activado ////");

    }
  if(Medicion == LOW){
    Serial.println("//// Boton Desactivado ////");
}
}
