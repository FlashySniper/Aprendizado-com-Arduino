int ledVermelho = 3;
int ledAmarelo = 4;
int ledVerde = 5;

void setup() { //Etapa do setup de periféficos.
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  analogWrite(ledVermelho, 255);
  delay(8000);
  analogWrite(ledVermelho, 0);
  analogWrite(ledVerde, 255);
  delay(4000);
  analogWrite(ledVerde, 0);
  analogWrite(ledAmarelo, 255);
  delay(2000);
  analogWrite(ledAmarelo, 0);
}
