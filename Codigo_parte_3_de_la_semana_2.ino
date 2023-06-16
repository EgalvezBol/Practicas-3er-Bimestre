/*Fundación Kinal
 * Centro Educativo Tecnico Laboral Kinal
 * Electrónica 
 * Grado: Quinto
 * Sección:A
 * Curso: Taller de Electrónoca Digital y Reparación de Computadoras I
 * Nombre: Edgar Emnauel Gálvez Bol
 * Carné: 2019253
 */
//Incluyo Librerias
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Defino todo lo de la LCD
#define direccion_lcd 0x3F
#define filas 2
#define columnas 16

//Defino el pin que utilizo
#define Resistencia A0 

//Variable
int Medicion();

//Constructor
LiquidCrystal_I2C LCD_Edgar(direccion_lcd, columnas, filas); 
  void setup() {
    Serial.begin(9600);
    pinMode(Resistencia, INPUT);
  LCD_Edgar.init();
  LCD_Edgar.backlight();
}
void loop() {
  LCD_Edgar.setCursor(0,0);
  LCD_Edgar.print("  Resistencia   ");
  unsigned long int ohms = Medicion();
  LCD_Edgar.setCursor(0,1);
  LCD_Edgar.print(ohms);
  LCD_Edgar.print(" ohms");
}
 int Medicion(){
    int lectura = 0;   //Valor de voltaje en el divisor de voltaje
    int Ve = 5;   // Vcc
    float VR2 = 0;    //Voltaje en la R2
    float R1 = 10000;     // Valor de la Resistencia de referencia
    float R2 = 0;         // Variable de la resistencia a encontrar
    float relacion = 0;
    lectura = analogRead(Resistencia);
   if(lectura) //Si detecta una resistencia
  {
    relacion = lectura * Ve;  // Opera el valor de la lectura del divisor por el voltaje de alimentacion
    VR2 = (relacion)/1024.0;  //hace la relacion en la escala raw para voltaje 
    relacion = (Ve/VR2) -1;    //en la operacion sule existir un 1 que no deveria de estar entonces se le resta 1 para poder obtener el verdadero resultado
    R2= (R1 * relacion)-20;  //para tener mayor precicion
    Serial.print("el valor es de :");
    Serial.println(R2);
    return R2;
  } else {
    Serial.println("no hay resistencia");
    return 0;
    }
  }
