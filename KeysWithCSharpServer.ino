#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "ButtonControl.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
extern unsigned char pagName;
static char Page = 2;

static String Page01Linha01 = "", Page01Linha02 = "", Page02Linha01 = "", Page02Linha02 = "";

static unsigned long tempo;
bool TimeAtualizaLcd() {
  if (tempo < millis()) {
    tempo = millis() + 1000;
    return true;
  } else {
    return false;
  }
}

static unsigned long tempoPag;
static bool pag1 = false;
bool alternaEntrePaginasLcd() {
  if (tempoPag < millis()) {
    tempoPag = millis() + 2000;
    pag1 = !pag1;
  }
  return pag1;
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  Inicializer_DigitalPins();
  Wire.begin();

  lcd.init();
  lcd.backlight();
  lcd.clear();
  encoder.setPosition(10); // start with the value of 10.
  // Page01Linha01 = "PAG-A  1-Vol+";
  // Page01Linha02 = "2-Vol- 3-Mute";

  // Page02Linha01 = "PAG-A  4-Home";
  // Page02Linha02 = "5-End  6-Prin";
}

String inputString = "";
void loop() {
  // put your main code here, to run repeatedly:
  pressButton();
  setPage();

  if (TimeAtualizaLcd()) {
    SerialToLcd();
  }


  if (alternaEntrePaginasLcd()) {
    if (Page == 2) {
      Page = 1;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(Page01Linha01);
      lcd.setCursor(0, 1);
      lcd.print(Page01Linha02);
    }
  } else {
    if (Page == 1) {
      Page = 2;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(Page02Linha01);
      lcd.setCursor(0, 1);
      lcd.print(Page02Linha02);
    }
  }
}

void SerialToLcd() {
  if (Serial.available()) {
    String inputString = Serial.readStringUntil('#');  // Lê a string recebida via serial até encontrar o caractere '\n' (que indica o fim da string)
    // Serial.print("String recebida: ");
    // Serial.println(inputString);  // Imprime a string recebida no monitor serial

    uint8_t pos1 = inputString.indexOf('@');            // Procura a posição do primeiro caractere '@'
    uint8_t pos2 = inputString.indexOf('@', pos1 + 1);  // Procura a posição do segundo caractere '@', a partir da posição do primeiro '@'
    uint8_t pos3 = inputString.indexOf('@', pos2 + 1);  // Procura a posição do terceiro caractere '@', a partir da posição do segundo '@'

    if (pos1 != -1 && pos2 != -1 && pos3 != -1) {  // Verifica se os três caracteres '@' foram encontrados na string

      // Page01Linha01 = inputString.substring(0, pos1);         // Extrai a primeira variável, que está entre o início da string e o primeiro '@'
      // Page01Linha02 = inputString.substring(pos1 + 1, pos2);  // Extrai a segunda variável, que está entre o primeiro '@' e o segundo '@'
      FillPage01(inputString.substring(0, pos1), inputString.substring(pos1 + 1, pos2));

      // Page02Linha01 = inputString.substring(pos2 + 1, pos3);  // Extrai a terceira variável, que está entre o segundo '@' e o terceiro '@'
      // Page02Linha02 = inputString.substring(pos3 + 1);        // Extrai a quarta variável, que está entre o terceiro '@' e o final da string
      FillPage02(inputString.substring(pos2 + 1, pos3), inputString.substring(pos3 + 1));

    } else {
      // Serial.println("Erro: a string não contém 3 caracteres '@'");  // Caso não encontre os três caracteres '@', imprime uma mensagem de erro no monitor serial
    }
  }
}

void FillPage01(String linha01, String linha02) {
  Page01Linha01 = linha01;
  Page01Linha02 = linha02;
}

void FillPage02(String linha01, String linha02) {
  Page02Linha01 = linha01;
  Page02Linha02 = linha02;
}