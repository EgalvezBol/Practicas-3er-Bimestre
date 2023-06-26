/*
CENTRO EDUCATIVO TECNICO LABORAL KINAL
Electronica dispositivos digitales
Taller de electronica
NOMBRES:
*Diego Alejandro Culajay Gonzalez
*Edgar Emmanuel Galvez Bol
Carnet
*2019485
*2019253
*/

#include <Stepper.h>
#include <Servo.h>

//Directivas del preprocesador
#define LDR    A0  
#define led_Azul  2   
#define led_Verde 3   
#define led_Rojo  4    
#define obs 12  
#define pin1 15  
#define pin2 16  
#define pin3 17  
#define pin4 18 
#define valido 8   
#define invalido 9  

//Variables
int Result_azul, Result_rojo, Result_verde;
int Result;

//Valor de umbral para los colores
int val = 7; //este valor lo podremos cambiar segun los valores leidos por nuestra LDR
//Constructor
Stepper Banda(2048,pin1,pin3,pin2,pin4);   
Servo piston;

void setup() {
  //Comunicacion serial
  Serial.begin(9600);

  //Configuracion de IN Y OUT 
  pinMode(LDR, INPUT); 
  pinMode(led_Azul, OUTPUT); 
  pinMode(led_Verde, OUTPUT); 
  pinMode(led_Rojo, OUTPUT);  
  pinMode(valido, OUTPUT);
  pinMode(invalido, OUTPUT);
  
  //Los leds inician en un estado de bajo
  digitalWrite(led_Azul, LOW);
  digitalWrite(led_Verde, LOW);
  digitalWrite(led_Rojo, LOW);
  
  //Configuracion Banda  
  Banda.setSpeed(15);
  //Configuracion Servo
  piston.attach(6);
  piston.write(180);
}

void loop() {
  if(digitalRead(obs) == true){  //Si no hay un obs
    Banda.step(-1);
    }
    if(digitalRead(obs) == false){   //Si hay un obs
    color();
    }
}
int color(){
  //Enciendo el led rojo
  digitalWrite(led_Rojo, HIGH);
  delay(100);

  //Leo el valor captado por la LDR
  Result = analogRead(LDR);
  Result_rojo = map(Result, 0,1023,0,255);  //lo linealizo 
  digitalWrite(led_Rojo, LOW);
  delay(100);

  //Enciendo el led verde
  digitalWrite(led_Verde, HIGH);
  delay(100);

  //Leo el valor captado por la LDR
  Result = analogRead(LDR);
  Result_verde = map(Result, 0,1023,0,255);  //lo linealizo 
  digitalWrite(led_Verde, LOW);
  delay(100);

   //Enciendo el led azul
  digitalWrite(led_Azul, HIGH);
  delay(100);

  //Leo el valor captado por la LDR
  Result = analogRead(LDR);
  Result_azul = map(Result, 0,1023,0,255);  //lo linealizo 
  digitalWrite(led_Azul, LOW);
  delay(100);

  if(Result_verde > Result_azul && Result_verde > Result_rojo){  //Si el valor de verde es mayor a los demas
    digitalWrite(valido, HIGH); //Aviso de verde detectado
    Serial.println("Verde detect");
    Serial.println("Posicionado");
    Banda.step(-2048);    //Mueve el obs a la posicion del Servo
    delay(100);
    Serial.println("Piston");
    piston.write(0);  // Mueve el servo a la posicion de empuje
    delay(500);
    piston.write(180);  //Regresa el servo a su posicion de inicio
    digitalWrite(valido, LOW); //Apaga la luz de verde detectado
    }
    else{
      Serial.println("No detectado");  //El color escaneado no es verde
      for(int i = 0; i < 12; i++){
      digitalWrite(invalido, digitalRead(invalido));
      delay(100);
      }
      Banda.step(-5000);   //Mueve el obs fuera del rango del sensor de obss para evitar lecturas en loop
      }
  }
