// LIBRERÍAS
#include <SoftwareSerial.h>

// PUERTOS DEL MOTOR
// MOTOR A
int ENA = 3;
int IN1 = 4;
int IN2 = 5;

// MOTOR B
int IN3 = 7;
int IN4 = 8;
int ENB = 10;

// PUERTOS DEL BLUE...


void setup(){
  
  // DEFINIENDO LA CANTIDAD DE BAUDIOS
  Serial.begin(9600);

  // CONFIGURACIÓN DE LAS VARIABLES

  // VARIABLES DE SALIDA
  for(int i = 3; i <= 5; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

// MOV. DE LOS MOTORES
// ADELANTE
void avanzar(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
}

void retroceder(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
}

void izquierda(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(ENA, 0);
  analogWrite(ENB, 180);
}

void derecha(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
  analogWrite(ENA, 180);
  analogWrite(ENB, 0);
}

void detener(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void retraso_tiempo(float time){
  // Ingrese el tiempo en segundos
  delay(time*1000);
}

void loop(){

  /*avanzar();
  retraso_tiempo(2.5);
  retroceder();
  retraso_tiempo(2.5);
  derecha();
  retraso_tiempo(2.5);
  izquierda();
  retraso_tiempo(2.5);
  detener();
  retraso_tiempo(2.5);*/

  if( Serial.available() ){ // EJECUTAR ALGO SI LA COMUNICACIÓN SERIAL ESTA HABILITADA
     int data = Serial.parseInt();
     String mensaje = "";
  switch(data){
    case 1 :
     // avanzar();
     mensaje = "1. Avanzar";
    break;
    
    case 2 :
     // retroceder();
     mensaje = "2. Retroceder";
    break;
    
    case 3 :
     mensaje = "3. Hacía la derecha";
    break;
    
    case 4 :
     mensaje = "4. Hacía la izquierda";
    break;

    case 5 : 
    mensaje = "5. Detener motor";
    break;

    default :
    mensaje = "0. EN ESPERA";
    break;
  }
  Serial.println(mensaje);
  retraso_tiempo(1.5);
  }else{
    Serial.println("La comunicación Serial no esta habilitada");
    retraso_tiempo(2);
  }
  
}



























