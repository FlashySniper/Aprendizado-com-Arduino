#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <U8glib.h>

//Inicializa o display no endereço 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

int eixo_X= A0; //PINO REFERENTE A LIGAÇÃO DO EIXO X
int eixo_Y = A1; //PINO REFERENTE A LIGAÇÃO DO EIXO Y
int botao = 2; //PINO REFERENTE A LIGAÇÃO NO PINO KEY (EIXO Z)
int x = 1;
int y = 0;

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);  // Display which does not send AC

void draw() 
{
  //Comandos graficos para o display devem ser colocados aqui
  //Seleciona a fonte de texto
  u8g.setFont(u8g_font_8x13B);
  //Linha superior - temperatura 
  u8g.drawStr( 5, 15, "23");
  u8g.drawCircle(28,8,3);
  u8g.drawStr( 34, 15, "C");
  //Hora
  u8g.setFont(u8g_font_fub30);
  u8g.drawStr( 10, 57, "09:35");
  //Texto - AM
  u8g.setFont(u8g_font_5x7);
  u8g.drawStr( 115, 33, "AM");
  //moldura relogio
  u8g.drawRFrame(0,18, 128, 46, 4);
  //Desenho bateria
  u8g.drawRFrame(105, 3, 20,12 , 0);
  u8g.drawBox(125, 6, 2,6);
  u8g.drawBox(107, 5, 4,8);
  u8g.drawBox(114, 5, 4,8);
  //Desenho linhas sinal
  u8g.drawVLine(99,0, 15);
  u8g.drawVLine(98,0, 15);
  u8g.drawVLine(96,4, 11);
  u8g.drawVLine(95,4, 11);
  u8g.drawVLine(93,8, 7);
  u8g.drawVLine(92,8, 7);
  u8g.drawVLine(90,12, 3);
  u8g.drawVLine(89,12, 3);
}

void setup() {
  lcd.init();
  pinMode (botao, INPUT_PULLUP);

  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
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

      u8g.firstPage();  
  do
  {
    draw();
  } while( u8g.nextPage() );
   
  delay(50);
}
