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
// unsigned char statusEncodeButton = '0';

void checkButton();
void pressButton();
unsigned char retornaVolume0a100();

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

static unsigned char volumeAnterior;
void EncoderConfig() {
  // Lê o estado atual dos pinos do encoder
  unsigned char volumeAtual = retornaVolume0a100();
  // Serial.print(volumeAnterior);
  // Serial.print("--");
  // Serial.println(volumeAtual);
  if (volumeAnterior != volumeAtual && (volumeAnterior+1) != volumeAtual && (volumeAnterior-1) != volumeAtual) {
    Serial.print("vol");
    Serial.print('@');
    Serial.println(volumeAtual);
    delay(500);
    volumeAnterior = volumeAtual;
    
  }


  // byte AtualEncode01 = read_bit(PINC, EncodeSinal01);
  // if (AnteriorEncode01 != AtualEncode01) {
  //   delay(100);
  //   AnteriorEncode01 = AtualEncode01;
  //   if (read_bit(PINC, EncodeSinal02) != AtualEncode01) {
  //     Serial.println("volU");
  //   } else {
  //     Serial.println("volD");
  //   }
  // }
}

unsigned char retornaVolume0a100() {
  return analogRead(A1) / (1023 / 100);
}

void pressButton() {
  checkButton();
  EncoderConfig();

  if (read_bit(PIND, BtnDBack) > 0 && statusBtnDBack == '1') {
    if (valor == 3) {
      valor = 0;
    } else {
      valor++;
    }
    statusBtnDBack = '0';
  }
  if (read_bit(PIND, BtnDNext) > 0 && statusBtnDNext == '1') {
    if (valor == 0) {
      valor = 3;
    } else {
      valor--;
    }
    statusBtnDNext = '0';
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

  // if (read_bit(PINC, EncodeButton) > 0 && statusEncodeButton == '1') {
  //   statusEncodeButton = '0';
  //   Serial.println("volmute");
  // }
}

void checkButton() {
  //verifica se o pino D7 é 1(HIGH) e nega. Entra se o Pino D7 for false (LOW)

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
  // if (read_bit(PINC, EncodeButton) == 0) {
  //   statusEncodeButton = '1';
  // }
  delay(10);
}
