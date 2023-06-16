/*Fundación Kinal
 * Centro Educativo Tecnico Laboral Kinal
 * Electrónica 
 * Led_Grado: Quinto
 * Sección:A
 * Curso: Taller de Electrónoca Digital y Reparación de Computadoras I
 * Nombre: Edgar Emnauel Led_Gálvez Led_Bol
 * Carné: 2019253
 */
#include <Ticker.h>
#define Poten A0
#define Led_G 6
#define Led_B 3
#define Led_R 5

//Variables
int Brillo;
int Estado;
int Espacio;

//Funciones
int Tiempo();
void Serie();
void ISR_Inter(void);

//Constructor
Ticker ISR_obtener_Espacio(ISR_Inter, 1); //Cada 1ms obtiene el valor del Potenenciometro

void setup() {
 ISR_obtener_Espacio.start();
 Serial.begin(9600);
 pinMode(Led_R, OUTPUT);
 pinMode(Led_G, OUTPUT);
 pinMode(Led_B, OUTPUT);
 pinMode(Poten, INPUT);
}

void loop() {
  Serie();
  ISR_obtener_Espacio.update();
}
int Tiempo(){
  Brillo = analogRead(Poten);
  Estado = map(Brillo, 0, 1023, 100, 1000);
  return Estado;
  }
void ISR_Inter(){
    Espacio = Tiempo();
    Serial.println(Espacio);
    }
    
void Serie(){
//    Led_R: 174 Led_G: 92 Led_B: 230
    analogWrite(Led_R, 174);
    analogWrite(Led_G, 92);
    analogWrite(Led_B, 230);
    delay(Espacio);
//    Led_R: 255 Led_G: 255 Led_B: 255
    analogWrite(Led_R, 255);
    analogWrite(Led_G, 255);
    analogWrite(Led_B, 255);
    delay(Espacio);
//    Led_R: 0 Led_G: 255 Led_B: 255
    analogWrite(Led_R, 0);
    analogWrite(Led_G, 255);
    analogWrite(Led_B, 255);
    delay(Espacio);
//     Led_R: 189 Led_G: 174 Led_B: 20
    analogWrite(Led_R, 189);
    analogWrite(Led_G, 174);
    analogWrite(Led_B, 20);
    delay(Espacio);
//Led_R: 225 Led_G: 87 Led_B: 35
    analogWrite(Led_R, 255);
    analogWrite(Led_G, 87);
    analogWrite(Led_B, 35);
    delay(Espacio);
    }
