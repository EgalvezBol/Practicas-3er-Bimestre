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
//Librerias
#include <LedControl.h>
#include <Ticker.h>
//Defino mis pines
#define D_Pin 2
#define CS_Pin 3
#define CLK_Pin 4
#define Gas_Pin 14
void L_Gas();

LedControl MATRIX = LedControl(D_Pin,CLK_Pin,CS_Pin,1);
Ticker ISR_GAS(L_Gas,3000);
 
int Pro;
int E_Gas;
const int T_Matrix = 8;

byte FIRE_1[8] = {
B11111111,
B01000001,
B01000001,
B01000010,
B00100100,
B00010100,
B00001000,
B00000000 
};
byte FIRE_2[8] = {
B11111111,
B01111111,
B01111111,
B01111110,
B00111100,
B00011100,
B00001000,
B00000000
};
byte Copo_Nieve [8] = {
B00011000,
B10011001,
B01011010,
B00111100,
B00011000,
B00111100,
B01011010,
B10011001
};

void setup() {
  MATRIX.shutdown(0, false); 
  MATRIX.setIntensity(0, 15); 
  MATRIX.clearDisplay(0); 
  pinMode(Gas_Pin, INPUT); 
  ISR_GAS.start();
  Serial.begin(9600);
}

void loop() {
 ISR_GAS.update();
  
  if (Pro > 30) {
    alerta_fuego();
  } else {
    for (int i = 0; i < T_Matrix; i++) {
    MATRIX.setColumn(0, i, Copo_Nieve[i]);
  }
  }
  delay(1000);
}
void L_Gas(){
  int suma =0;
  
  for(int i = 0; i < 5; i++){
  E_Gas = map(analogRead(Gas_Pin),0,1023,0,100);
  suma = suma + E_Gas;
  delay(100);
  }
  Pro = suma/5;
  Serial.println(E_Gas);
}

void alerta_fuego() {
  MATRIX.clearDisplay(0);
for(int t = 0; t<5;t++){
  for (int i = T_Matrix; i > 0; i--)
    MATRIX.setColumn(0, i, FIRE_1[i]);
  }
  delay(500);
  
  for (int i = T_Matrix; i > 0; i--) {
    MATRIX.setColumn(0, i, FIRE_2[i]);
  }
  delay(500);
}
