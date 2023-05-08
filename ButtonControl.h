#include "Pagination.h"

extern unsigned char pagName;
extern uint8_t valor;

unsigned char statusBtnDBack = '0';
unsigned char statusBtnDNext = '0';

unsigned char statusBtn06 = '0';
unsigned char statusBtn05 = '0';
unsigned char statusBtn04 = '0';
unsigned char statusBtn03 = '0';
unsigned char statusBtn02 = '0';
unsigned char statusBtn01 = '0';
unsigned char statusEncodeButton = '0';

void checkButton();
void pressButton();

void funcButton(unsigned char numButton) {
  if (numButton == '1') {
    statusBtn01 = '0';

  } else if (numButton == '2') {
    statusBtn02 = '0';

  } else if (numButton == '3') {
    statusBtn03 = '0';

  } else if (numButton == '4') {
    statusBtn04 = '0';

  } else if (numButton == '5') {
    statusBtn05 = '0';

  } else if (numButton == '6') {
    statusBtn06 = '0';
  }
  Serial.print(char(pagName));
  Serial.println(char(numButton));
}

int encoderValue = 10;                // Valor atual do encoder
unsigned char encoderPinALast = LOW;  // Estado anterior do sinal A
unsigned char encoderPinBLast = LOW;  // Estado anterior do sinal B
static unsigned long timeRotaryEncoder;

void EncoderConfig() {
  unsigned char encoderPinAState = digitalRead(EncodeSinal01);
  unsigned char encoderPinBState = digitalRead(EncodeSinal02);

  if (encoderPinAState != encoderPinALast) {

    if (timeRotaryEncoder < millis()) {
      timeRotaryEncoder = millis() + 70;

      if (encoderPinBState != encoderPinAState) {
        encoderValue++;
        if (encoderValue > 100) {
          encoderValue = 100;
        }
      } else {
        encoderValue--;
        if (encoderValue < 0) {
          encoderValue = 0;
        }
      }

      Serial.print("vol@");
      Serial.println(encoderValue);  // Mostra o valor binário do encoder no monitor serial
    }
  }

  encoderPinALast = encoderPinAState;
  encoderPinBLast = encoderPinBState;
}

void pressButton() {
  checkButton();
  EncoderConfig();

  if (read_bit(PIND, BtnDBack) && statusBtnDBack) {
    valor = (valor == 3) ? 0 : valor + 1;
    statusBtnDBack = 0;
  }
  if (read_bit(PIND, BtnDNext) && statusBtnDNext) {
    valor = (valor == 0) ? 3 : valor - 1;
    statusBtnDNext = 0;
  }


  if (read_bit(PINB, BtnB01) > 0 && statusBtn01 == '1') {
    funcButton('1');
  }
  if (read_bit(PINB, BtnB02) > 0 && statusBtn02 == '1') {
    funcButton('2');
  }
  if (read_bit(PINB, BtnB03) > 0 && statusBtn03 == '1') {
    funcButton('13');
  }
  if (read_bit(PIND, BtnD04) > 0 && statusBtn04 == '1') {
    funcButton('4');
  }

  if (read_bit(PIND, BtnD05) > 0 && statusBtn05 == '1') {
    funcButton('5');
  }

  if (read_bit(PIND, BtnD06) > 0 && statusBtn06 == '1') {
    funcButton('6');
  }

  if (read_bit(PINC, EncodeButton) > 0 && statusEncodeButton == '1') {
    statusEncodeButton = '0';
    Serial.println("volmute");
  }
}

void checkButton() {
  if ((read_bit(PIND, BtnDBack)) == 0) {
    statusBtnDBack = '1';
  }
  if ((read_bit(PIND, BtnDNext)) == 0) {
    statusBtnDNext = '1';
  }
  if ((read_bit(PINB, BtnB01)) == 0) {
    statusBtn01 = '1';
  }
  if ((read_bit(PINB, BtnB02)) == 0) {
    statusBtn02 = '1';
  }
  if ((read_bit(PINB, BtnB03)) == 0) {
    statusBtn03 = '1';
  }
  if ((read_bit(PIND, BtnD04)) == 0) {
    statusBtn04 = '1';
  }
  if ((read_bit(PIND, BtnD05)) == 0) {
    statusBtn05 = '1';
  }
  if ((read_bit(PIND, BtnD06)) == 0) {
    statusBtn06 = '1';
  }
  if (read_bit(PINC, EncodeButton) == 0) {
    statusEncodeButton = '1';
  }
}
