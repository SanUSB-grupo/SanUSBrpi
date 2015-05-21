/*Programa para gerar o reset no pino 1 (pin_e3 do microcontrolador) para gravação do PIC via USB, 
pois o pino físico 11 do Rpi, ou seja, wPi 0 está ligado no pino 1 (pin_e3) do microcontrolador. 
Em subtituição a esse código, é possível digitar diretamente no LXTerminal: gpio mode 0 out <Enter> , 
depois gpio write 0 0 <Enter> e finalmente: gpio write 0 1 <Enter>.
*/

#include<stdio.h>
#include<wiringPi.h>

int main(){

   wiringPiSetup();
   pinMode(0,OUTPUT); //pino wPi 0 configurado como saída (ou digitar no LXTerminal: gpio mode 0 out)
   
   digitalWrite(0,LOW);  //(gpio write 0 0)como está ligado por um fio no pino 1 pin_e3 do PIC, gera um reset no microcontrolador e o PIC
   delay(1500);          // entra em estado de gravação via USB, pois está escrito no firmware do PIC: if(input(pin_e3)==0){reset_cpu();}
   
   digitalWrite(0,HIGH); //(gpio write 0 1)volta o pino wPi 0 do Rpi e o pino 1 (pin_e3) do PIC para estado de operação 
                         //(nível lógico alto) após a gravação
   printf ("Digite Ctrl+c para sair e gravar o microcontrolador via USB\n") ;
   //if (1) {exit (1) ;}//Volta ao terminal após o reset do microcontrolador

   while(1){//fica parado. Após compilar e executar esse código no LXTerminal, digite Ctrl+C para sair desse programa 
            //e gravar o microcontrolador com o programa SanUSB        
           }
   
   return 0;
            }
