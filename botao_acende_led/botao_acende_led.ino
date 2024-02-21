int led3 = 3;
int botao = 13;
bool estadoLed = 0; //variavel de controle

void setup() {
  // put your setup code here, to run once:
  pinMode(botao, INPUT_PULLUP); // define o pino do botao como entrada
  pinMode(led3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(botao) == LOW){ //Se o botao for pressionado
    estadoLed = !estadoLed; //Troca estado do LED
    digitalWrite(led3, estadoLed);
    while(digitalRead(botao) == LOW);
    delay(100);
  }
}
