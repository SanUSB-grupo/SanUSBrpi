#include "SanUSB1.h"

#pragma interrupt interrupcao //Tem que estar aqui ou dentro do firmware.c
void interrupcao(){
                  }

void main(){
clock_int_4MHz();

while(1)
{
if(!entrada_pin_e3){Reset();}//pressionar o bot�o para grava��o

inverte_saida(pin_b7);
tempo_ms(300);
}
}
