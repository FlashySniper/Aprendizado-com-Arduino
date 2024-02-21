#include <Servo.h>

#define SERVO 8

Servo meuServo;
int angulo = 0;

const int azul = 9;
const int verde = 10;
const int vermelho = 11;

const int pinoLed = 12; //Pino digital usado pelo sensor
const int pinoSensor = 5; //PINO DIGITAL UTILIZADO PELO SENSOR

void setup() {
  // put your setup code here, to run once:
  meuServo.attach(SERVO);
  Serial.begin(9600);
  meuServo.write(0);
  
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);

  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(pinoLed, OUTPUT); //DEFINE O PINO COMO SAÍDA
  digitalWrite(pinoLed, LOW); //LED INICIA DESLIGADO
}

void vermelhoFuncao(){
  analogWrite(azul, 0);
  analogWrite(verde, 0);
  analogWrite(vermelho, 255);
}
void azulFuncao(){
  analogWrite(azul, 255);
  analogWrite(verde, 0);
  analogWrite(vermelho, 0);
}
void verdeFuncao(){
  analogWrite(azul, 0);
  analogWrite(verde, 255);
  analogWrite(vermelho, 0);
}
void amareloFuncao(){
  analogWrite(azul, 0);
  analogWrite(verde, 255);
  analogWrite(vermelho, 255);
}
void roxoFuncao(){
  analogWrite(azul, 255);
  analogWrite(verde, 0);
  analogWrite(vermelho, 255);
}
void brancoFuncao(){
  analogWrite(azul, 255);
  analogWrite(verde, 255);
  analogWrite(vermelho, 255);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pinoSensor) == HIGH){ //SE A LEITURA DO PINO FOR IGUAL A HIGH
      digitalWrite(pinoLed, HIGH); //ACENDE O LED
  }else{ 
    digitalWrite(pinoLed, LOW); //APAGA O LED
  }
  for(angulo = 0; angulo <= 180; angulo += 1){
    if(angulo == 30){
      vermelhoFuncao();
    }
    if(angulo == 60){
      azulFuncao();
    }
    if(angulo == 90){
      verdeFuncao();
    }
    if(angulo == 120){
      amareloFuncao();
    }
    if(angulo == 150){
      roxoFuncao();
    }
    if(angulo == 179){
      brancoFuncao();
    }
    meuServo.write(angulo);
    delay(30);
  }
  delay(1000);
  for(angulo = 180; angulo >= 1; angulo -= 1){
    if(angulo == 30){
      vermelhoFuncao();
    }
    if(angulo == 60){
      azulFuncao();
    }
    if(angulo == 90){
      verdeFuncao();
    }
    if(angulo == 120){
      amareloFuncao();
    }
    if(angulo == 150){
      roxoFuncao();
    }
    if(angulo == 179){
      brancoFuncao();
    }
    meuServo.write(angulo);
    delay(30);
  }
  delay(1000);
}
