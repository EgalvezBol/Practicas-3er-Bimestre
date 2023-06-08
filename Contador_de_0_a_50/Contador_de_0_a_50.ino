/*Fundación Kinal
 * Centro Educativo Tecnico Laboral Kinal
 * Electrónica 
 * Grado: Qu#defineo
 * Sección:A
 * Curso: Taller de Electrónoca Digital y Reparación de Computadoras I
 * Nombre: Edgar Emnauel Gálvez Bol
 * Carné: 2019253
 */
#define Rising 2
#define Faling 3
#define A1 4
#define A2 11
#define B1 5
#define B2 12
#define C1 6
#define C2 13
#define D1 7
#define D2 14
#define E1 8
#define E2 15
#define F1 9
#define F2 16
#define G1 10
#define G2 17

//funciones de ISR
void funcion_ISR_rising(void);
void funcion_ISR_falling(void);

//variables
volatile static bool F_print= false;
volatile static unsigned char i=0;

void setup() {
Serial.begin(9600);
pinMode(A1,OUTPUT);
pinMode(A2,OUTPUT);
pinMode(B1,OUTPUT);
pinMode(B2,OUTPUT);
pinMode(C1,OUTPUT);
pinMode(C2,OUTPUT);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(E1,OUTPUT);
pinMode(E2,OUTPUT);
pinMode(F1,OUTPUT);
pinMode(F2,OUTPUT);
pinMode(G1,OUTPUT);
pinMode(G2,OUTPUT);
pinMode(Rising,INPUT);
pinMode(Faling,INPUT);
attachInterrupt(digitalPinToInterrupt(Rising),funcion_ISR_rising,RISING);
attachInterrupt(digitalPinToInterrupt(Faling),funcion_ISR_falling,FALLING);
}

void loop() {
if (F_print){
  F_print = false; 
Serial.println(i);
  contador();
}
}
//Funciones de ISR aplicadas
void funcion_ISR_rising(void){
F_print = true;
  i++;
 if (i>50){
  i=0;} }
void funcion_ISR_falling(void){
 F_print = true; 
  i--;
if (i<=0){
 i=50;}
 }
//Funcion de la configuración de los Displays
void contador(){
if(i==0){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,HIGH),digitalWrite(G2,LOW);//Display 2
}
if(i==1){
digitalWrite(A1,LOW),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,HIGH),digitalWrite(G2,LOW);//Display 2
}
if(i==2){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,LOW),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,LOW),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,HIGH),digitalWrite(G2,LOW);//Display 2 
}
if(i==3){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,HIGH),digitalWrite(G2,LOW);//Display 2
}
if(i==4){
digitalWrite(A1,LOW),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,HIGH),digitalWrite(G2,LOW);//Display 2
}
if(i==5){
digitalWrite(A1,HIGH),digitalWrite(B1,LOW),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,HIGH),digitalWrite(G2,LOW);//Display 2
}
if(i==6){
digitalWrite(A1,HIGH),digitalWrite(B1,LOW),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,HIGH),digitalWrite(G2,LOW);//Display 2
}
if(i==7){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,HIGH),digitalWrite(G2,LOW);//Display 2
}
if(i==8){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,HIGH),digitalWrite(G2,LOW);//Display 2
}
if(i==9){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,HIGH),digitalWrite(G2,LOW);//Display 2
}
if(i==10){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,LOW);//Display 2
}
if(i==11){
digitalWrite(A1,LOW),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,LOW);//Display 2
}
if(i==12){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,LOW),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,LOW),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,LOW);//Display 2
}
if(i==13){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,LOW);//Display 2
}
if(i==14){
digitalWrite(A1,LOW),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,LOW);//Display 2
}
if(i==15){
digitalWrite(A1,HIGH),digitalWrite(B1,LOW),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,LOW);//Display 2
}
if(i==16){
digitalWrite(A1,HIGH),digitalWrite(B1,LOW),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,LOW);//Display 2
}
if(i==17){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,LOW);//Display 2
}
if(i==18){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,LOW);//Display 2
}
if(i==19){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,LOW);//Display 2
}
if(i==20){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,LOW),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==21){
digitalWrite(A1,LOW),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,LOW),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==22){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,LOW),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,LOW),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,LOW),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==23){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,LOW),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==24){
digitalWrite(A1,LOW),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,LOW),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==25){
digitalWrite(A1,HIGH),digitalWrite(B1,LOW),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,LOW),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==26){
digitalWrite(A1,HIGH),digitalWrite(B1,LOW),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,LOW),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==27){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,LOW),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==28){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,LOW),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==29){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,LOW),digitalWrite(D2,HIGH),digitalWrite(E2,HIGH),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==30){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==31){
digitalWrite(A1,LOW),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==32){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,LOW),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,LOW),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==33){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==34){
digitalWrite(A1,LOW),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==35){
digitalWrite(A1,HIGH),digitalWrite(B1,LOW),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==36){
digitalWrite(A1,HIGH),digitalWrite(B1,LOW),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==37){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==38){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==39){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,LOW),digitalWrite(F2,LOW),digitalWrite(G2,HIGH);//Display 2
}
if(i==40){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,HIGH),digitalWrite(G2,HIGH);//Display 2
}
if(i==41){
digitalWrite(A1,LOW),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,HIGH),digitalWrite(G2,HIGH);//Display 2
}
if(i==42){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,LOW),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,LOW),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,HIGH),digitalWrite(G2,HIGH);//Display 2
}
if(i==43){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,HIGH),digitalWrite(G2,HIGH);//Display 2
}
if(i==44){
digitalWrite(A1,LOW),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,HIGH),digitalWrite(G2,HIGH);//Display 2
}
if(i==45){
digitalWrite(A1,HIGH),digitalWrite(B1,LOW),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,HIGH),digitalWrite(G2,HIGH);//Display 2
}
if(i==46){
digitalWrite(A1,HIGH),digitalWrite(B1,LOW),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,HIGH),digitalWrite(G2,HIGH);//Display 2
}
if(i==47){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,LOW),digitalWrite(E1,LOW),digitalWrite(F1,LOW),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,HIGH),digitalWrite(G2,HIGH);//Display 2
}
if(i==48){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,HIGH),digitalWrite(G2,HIGH);//Display 2
}
if(i==49){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,LOW),digitalWrite(F1,HIGH),digitalWrite(G1,HIGH);//Display 1
digitalWrite(A2,LOW),digitalWrite(B2,HIGH),digitalWrite(C2,HIGH),digitalWrite(D2,LOW),digitalWrite(E2,LOW),digitalWrite(F2,HIGH),digitalWrite(G2,HIGH);//Display 2
}
if(i==50){
digitalWrite(A1,HIGH),digitalWrite(B1,HIGH),digitalWrite(C1,HIGH),digitalWrite(D1,HIGH),digitalWrite(E1,HIGH),digitalWrite(F1,HIGH),digitalWrite(G1,LOW);//Display 1
digitalWrite(A2,HIGH),digitalWrite(B2,LOW),digitalWrite(C2,HIGH),digitalWrite(D2,HIGH),digitalWrite(E2,LOW),digitalWrite(F2,HIGH),digitalWrite(G2,HIGH);//Display 2
}
}
