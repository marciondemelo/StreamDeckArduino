
#include "HelpFunction.h"

void Inicializer_DigitalPins(void);

#define  BtnDBack 2
#define  BtnDNext 3

#define BtnB01 1
#define BtnB02 2
#define BtnB03 3
#define BtnD04 5
#define BtnD05 6
#define BtnD06 7
#define EncodeSinal01 A1
#define EncodeSinal02 A2
#define EncodeButton 3

void Inicializer_DigitalPins(void){

	clr_bit(DDRB, BtnB01); //define como input (invert de 1 para 0)
	clr_bit(DDRB, BtnB02); //define como input (invert de 1 para 0)
	clr_bit(DDRB, BtnB03); //define como input (invert de 1 para 0)
	clr_bit(DDRD, BtnD04); //define como input (invert de 1 para 0)
	clr_bit(DDRD, BtnDBack); //define como input (invert de 1 para 0)
	clr_bit(DDRD, BtnDNext); //define como input (invert de 1 para 0)
	clr_bit(DDRD, BtnD05); //define como input (invert de 1 para 0)
	clr_bit(DDRD, BtnD06); //define como input (invert de 1 para 0)
  // clr_bit(DDRC, EncodeSinal01); //define como input (invert de 1 para 0)
  // clr_bit(DDRC, EncodeSinal02); //define como input (invert de 1 para 0)
  clr_bit(DDRC, EncodeButton); //define como input (invert de 1 para 0)

	set_bit(PORTB, BtnB01); //define como pullup
	set_bit(PORTB, BtnB02); //define como pullup
	set_bit(PORTB, BtnB03); //define como pullup
	set_bit(PORTD, BtnDBack); //define como pullup
	set_bit(PORTD, BtnDNext); //define como pullup
	set_bit(PORTD, BtnD04); //define como pullup
	set_bit(PORTD, BtnD05); //define como pullup
	set_bit(PORTD, BtnD06); //define como pullup
  // set_bit(PORTC, EncodeSinal01); //define como pullup
  // set_bit(PORTC, EncodeSinal02); //define como pullup
  set_bit(PORTC, EncodeButton); //define como pullup
  
  pinMode(EncodeSinal01, INPUT_PULLUP);
  pinMode(EncodeSinal02, INPUT_PULLUP);
}



