/*Fundación Kinal
 * Centro Educativo Tecnico Laboral Kinal
 * Electrónica 
 * Grado: Quinto
 * Sección:A
 * Curso: Taller de Electrónoca Digital y Reparación de Computadoras I
 * Nombre: Edgar Emnauel Gálvez Bol
 * Carné: 2019253
 */
//librerias
#include <LiquidCrystal_I2C.h> 

//Directivas de procesador
#define Enter A0

//Variables
float valor_In;
float Parte_1;
int Vcc=5;
float Parte_2;
int Res;
int res2 = 10000;
int res1;
//
void formula(void);
//Constructor
LiquidCrystal_I2C LCD_Edgar(0x27, 16, 2);

void setup(){
  Serial.begin(9600);
LCD_Edgar.init(); 
LCD_Edgar.backlight(); 
LCD_Edgar.setCursor(3,0);
LCD_Edgar.print ("Ohmimetro");
pinMode(A0, INPUT);
  }

void loop(){
  formula();
}
void formula(){
  valor_In = analogRead(Enter);
  valor_In =(Vcc * valor_In) / 1023;
  if (valor_In){
  Parte_1= Vcc - valor_In; 
  Parte_2 = valor_In;
  res1 = (Parte_1/Parte_2) * res2;
  LCD_Edgar.setCursor(4,1); 
  LCD_Edgar.print(res1);
   LCD_Edgar.print("            ");
   Serial.println(res1);
}
}
