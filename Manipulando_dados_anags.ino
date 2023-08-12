//PROJETO DE EXIBIÇÃO DE TEMPERATURA EM UM DISPLAY LCD, MANIPULANDO DADOS ANALÓGICOS.


#include <LiquidCrystal.h> //Inclusao da biblioteca do LCD
unsigned int temperatura; //Variável de 16bits que admite somente valores positivos
void temperatura_mostrar(); //Loading da função primária

LiquidCrystal lcd (8, 9, 4, 5, 6, 7); //Mapeamento/pinagem do LCD

//Função de inicialização do sistema
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(6, 0);
  lcd.print("SENAI");
}

//Função de exibição da temperatura no display
void temperatura_mostrar()
{
  temperatura = map(temperatura, 0, 1023, 0, 100);

  if (temperatura <= 9) {
    lcd.setCursor(9, 1);
    lcd.print(temperatura);
    lcd.print("    ");
  }

  if (temperatura <= 100) {
    lcd.setCursor(8, 1);
    lcd.print(temperatura);
    lcd.print("    ");
  }
}

//Função de loop/repetição
void loop()
{
  temperatura = analogRead(A8);
  lcd.setCursor(0, 1);
  lcd.print(temperatura);
  lcd.print("    ");
  temperatura_mostrar();
}
