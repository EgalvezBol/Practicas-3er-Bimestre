/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Edgar Emanuel Gálvez Bol
 * Carnet: 2019253
*/
#include <Wire.h>
#include <SPI.h>
#include <SparkFun_ADXL345.h>
#include <LedControl.h>
#define T_Matrix 8
#define B_Matrix 8 
#define Data_P 12
#define CLK_P 11
#define CS_P 10

float xg,yg,zg;
float SA;
float Tl;
float angle;

const byte derechaV[8] = {
B00000000,
B11111111,
B11111111,
B00000001,
B00000001,
B11111111,
B11111111,
B00000000
};

const byte derechaIV[8] = {
B00000000,
B11111111,
B11111111,
B00000011,
B00000011,
B11111111,
B11111111,
B00000000
};

const byte derechaIII[8] = {
B00000000,
B11111111,
B11111111,
B00000110,
B00000110,
B11111111,
B11111111,
B00000000
};

const byte derechaII[8] = {
B00000000,
B11111111,
B11111111,
B00001100,
B00001100,
B11111111,
B11111111,
B00000000
  };

const byte derechaI[8] = {
B00000000,
B11111111,
B11111111,
B00001000,
B00001000,
B11111111,
B11111111,
B00000000
  };

const byte CENTRO[8] = {
B00000000,
B11111111,
B11111111,
B00011000,
B00011000,
B11111111,
B11111111,
B00000000};

const byte izquierdaI[8] = {
B00000000,
B11111111,
B11111111,
B00010000,
B00010000,
B11111111,
B11111111,
B00000000};

const byte izquierdaII[8] = {
B00000000,
B11111111,
B11111111,
B00110000,
B00110000,
B11111111,
B11111111,
B00000000
};

const byte izquierdaIII[8] = {
B00000000,
B11111111,
B11111111,
B01100000,
B01100000,
B11111111,
B11111111,
B00000000
};

const byte izquierdaIV[8] = {
B00000000,
B11111111,
B11111111,
B11000000,
B11000000,
B11111111,
B11111111,
B00000000
};

const byte izquierdaV[8] = {
B00000000,
B11111111,
B11111111,
100000000,
B10000000,
B11111111,
B11111111,
B00000000
};

LedControl MatrisLed = LedControl(Data_P,CLK_P,CS_P,1);
ADXL345 NIVEL = ADXL345();
void setup() {
   Serial.begin(9600);    
   MatrisLed.shutdown(0,false);    
   MatrisLed.setIntensity(0,15);   
   MatrisLed.clearDisplay(0);    
   NIVEL.powerOn();           
   NIVEL.setRangeSetting(8);       

}

void loop() {
   nivelacion();
   animacion(); 
}

void nivelacion(){
  int sumax = 0;
  int x, y, z;
  NIVEL.readAccel(&x, &y, &z);
     xg = x*0.0039;
     yg = y*0.0039;
     zg = z*0.0039;
     SA = xg/zg;
     Tl = atan(SA)*57.296;
}
void animacion(){
  if(Tl >= -5 && Tl <= 5){  //centro
   for (int i = T_Matrix; i > 0; i--) {
    MatrisLed.setColumn(0, i, CENTRO[i]);
      }
  }

  if((Tl > 5) && (Tl <= 15 )){ 
   for (int i = T_Matrix; i > 0; i--) {
    MatrisLed.setColumn(0, i, derechaI[i]);
      }
  }
  
  if((Tl > 15) && (Tl <= 30 )){ 
   for (int i = T_Matrix; i > 0; i--) {
    MatrisLed.setColumn(0, i, derechaII[i]);
      }
  }

  if((Tl > 30) && (Tl <= 45 )){  
   for (int i = T_Matrix; i > 0; i--) {
    MatrisLed.setColumn(0, i, derechaIII[i]);
      }
  }
  
  if((Tl > 45) && (Tl <= 60 )){  
   for (int i = T_Matrix; i > 0; i--) {
    MatrisLed.setColumn(0, i, derechaIV[i]);
      }
  }
  if((Tl > 60) && (Tl <= 90 )){  
   for (int i = T_Matrix; i > 0; i--) {
    MatrisLed.setColumn(0, i, derechaV[i]);
      }
  }
    if((Tl < -60) && ( Tl >= -90) ){
    for (int i = T_Matrix; i > 0; i--) {
    MatrisLed.setColumn(0, i,derechaV[i]);
      }
  }
  if((Tl < -45) && (Tl >= -60 )){ 
    for (int i = T_Matrix; i > 0; i--) {
    MatrisLed.setColumn(0, i,derechaIV[i]);
      }
  }
    if((Tl < -30) && (Tl >= -45 )){ 
    for (int i = T_Matrix; i > 0; i--) {
    MatrisLed.setColumn(0, i,derechaIII[i]);
      }
  }
    if((Tl < -15) && (Tl >= -30 )){  
   for (int i = T_Matrix; i > 0; i--) {
    MatrisLed.setColumn(0, i,derechaII[i]);
      }
  }
    if((Tl < -5) && (Tl >= -15 )){ 
   for (int i = T_Matrix; i > 0; i--) {
    MatrisLed.setColumn(0, i, izquierdaI[i]);
      }
  }
  }
