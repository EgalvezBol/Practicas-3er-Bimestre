/*Fundación Kinal
 * Centro Educativo Tecnico Laboral Kinal
 * Electrónica 
 * Grado: Quinto
 * Sección:A
 * Curso: Taller de Electrónoca Digital y Reparación de Computadoras I
 * Nombre: Edgar Emanuel Gálvez Bol
 * Carné: 2019253
 */
 
#define Led_T 6
#define Poten A0


void setup(){
  Serial.begin(9600);
  pinMode(Led_T,OUTPUT);
  pinMode(Poten,INPUT);
  }

void loop(){
 encender();
}

void encender(){
int valor = analogRead(Poten);
int mapear = map(valor,0,1023,0,255);
analogWrite(Led_T, mapear);
}
