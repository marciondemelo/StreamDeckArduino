
#include "PinRegistration.h"

void setPage();
uint8_t valor = 0;
unsigned char pagName = 'A';

void setPage() {
   char newPagName = 'A' + valor;
  if (newPagName != pagName) {
    pagName = newPagName;
    Serial.print("page");
    Serial.println(char(pagName));
  }
  delay(10);
}

