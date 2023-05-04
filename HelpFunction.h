#define set_bit(y,bit)  (y|=(1<<bit))  //coloca em 1 o bit x da variavel y
#define clr_bit(y,bit)  (y&=~(1<<bit)) //coloca em 0 o bit x da variavel y
#define cpl_bit(y,bit)  (y^=(1<<bit))   //macro invert value
#define read_bit(y,bit) (y&(1<<bit))    //retorna 0 ou 1 conforme leitura do bit
