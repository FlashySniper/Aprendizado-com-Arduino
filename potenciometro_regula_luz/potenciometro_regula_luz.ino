#define potPin A0 //Variavel que salva o valor do potenciômetro
#define ledPin 13

int valPot = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(valPot, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); //Inicia a serial com Baud Rand 9600
}

void loop() {
  // put your main code here, to run repeatedly:
  valPot = analogRead(potPin);
  valPot = map(valPot, 0, 1023, 0, 255);

  analogWrite(ledPin, valPot);
  
}
