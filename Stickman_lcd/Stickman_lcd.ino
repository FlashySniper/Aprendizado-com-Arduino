#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Inicializa o display no endereço 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

int eixo_X= A0; //PINO REFERENTE A LIGAÇÃO DO EIXO X
int eixo_Y = A1; //PINO REFERENTE A LIGAÇÃO DO EIXO Y
int botao = 2; //PINO REFERENTE A LIGAÇÃO NO PINO KEY (EIXO Z)
int x = 1;
int y = 0;

void setup() {
  lcd.init();
  pinMode (botao, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setBacklight(HIGH);
  lcd.setCursor(x,0);
  lcd.print("O");
  lcd.setCursor(y,1);
  lcd.print("/|>");
   if((analogRead(eixo_X)) == 0){ //SE LEITURA FOR IGUAL A 0, FAZ
        lcd.clear();
        x -= 1;
        lcd.setCursor(x,0);
        lcd.print("/|>");
        lcd.setCursor(y,1);
        lcd.print("| |");
        x += 1;
    }else{
          if((analogRead(eixo_X)) == 1023){ //SE LEITURA FOR IGUAL A 1023, FAZ
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("");
              y += 1;
              lcd.setCursor(y,1);
              lcd.print("O");
              y -= 1;
          }else{
                if((analogRead(eixo_Y)) == 0){ //SE LEITURA FOR IGUAL A 0, FAZ
                  x += 1;
                  lcd.setCursor(x,0);
                  lcd.print("O");
                  y += 1;
                  lcd.setCursor(y,1);
                  lcd.print("/|>"); 
                }else{
                      if((analogRead(eixo_Y)) == 1023){ //SE LEITURA FOR IGUAL A 1023, FAZ
                          x -= 1;
                          lcd.setCursor(x,0);
                          lcd.print("O");
                          y -= 1;
                          lcd.setCursor(y,1);
                          lcd.print("/|>"); 
                      }else{
                            if(digitalRead(botao) == LOW){ //SE LEITURA FOR IGUAL A HIGH, FAZ
                               Serial.println("BOTAO PRESSIONADO"); //IMPRIME O TEXTO NO MONITOR SERIAL
                            }  
                      }
                }
          }
    }
    delay(300);
}
