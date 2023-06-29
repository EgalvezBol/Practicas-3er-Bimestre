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

#define LDR A0  
#define ledA  2   
#define ledV 3   
#define ledR  4   
#define pinINA 15  
#define pinINB 16 
#define pinINC 17  
#define pinIND 18  
#define SenOb 12  
#define valido 8   
#define invalido 9  


int resrojo , resverde , resazul;

int RES;

//Valor de umbral 
int tol = 8; 

Stepper Motor(2048,pinINA,pinINC,pinINB,pinIND);   
Servo stepper;  

void setup() {
  //Comunicacion serial
  Serial.begin(9600);

  //Configuracion de I/O 
  pinMode(LDR, INPUT); 
  pinMode(ledA, OUTPUT); 
  pinMode(ledV, OUTPUT); 
  pinMode(ledR, OUTPUT);  
  pinMode(valido, OUTPUT);
  pinMode(invalido, OUTPUT);
  digitalWrite(ledA, LOW);
  digitalWrite(ledV, LOW);
  digitalWrite(ledR, LOW);
  Motor.setSpeed(15);
  stepper.attach(6);
  stepper.write(180); 
}

void loop() {
  if(digitalRead(SenOb) == true){  
    Motor.step(-1);
    }
    if(digitalRead(SenOb) == false){   
    color();
    }
}
int color(){
  
  digitalWrite(ledR, HIGH);
  delay(50);

  
  RES = analogRead(LDR);
  resrojo = map(RES, 0,1023,0,255);
  digitalWrite(ledR, LOW);
  delay(50);

  digitalWrite(ledV, HIGH);
  delay(50);

  
  RES = analogRead(LDR);
  resverde = map(RES, 0,1023,0,255);  
  digitalWrite(ledV, LOW);
  delay(50);

  digitalWrite(ledA, HIGH);
  
  delay(50);

 
  RES = analogRead(LDR);
  resazul = map(RES, 0,1023,0,255);  
  digitalWrite(ledA, LOW);
  delay(50);

  if(resrojo > resazul && resrojo > resverde){  
    digitalWrite(valido, HIGH); 
    Serial.println("Rojo OK");
    Serial.println("Posicionado");
    Motor.step(-2048);    
    delay(100);
    Serial.println("Piston");
    stepper.write(0);  
    delay(500);
    stepper.write(180);
    digitalWrite(valido, LOW); 
    }
    else{
      Serial.println("No detectado");  
      for(int i = 0; i < 12; i++){
      digitalWrite(invalido, !digitalRead(invalido));
      delay(100);
      }
      Motor.step(-5000);   
      }
  }
