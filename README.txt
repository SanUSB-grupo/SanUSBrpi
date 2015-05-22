Para gravação via USB, basta conectar o cabo USB (5V), entre os pinos do Rpi (3,3 V) e do PIC (5V), e ligar apenas o fio azul entre o pino físico Rpi 11 (Wpi 0) 
de 3,3 V ao pino e3 do microcontrolador PIC (pino 1 de entrada). Essa conexão, com proteção de tensão (5V <-> 3,3 V), é possível porque os pinos de I/O do 
Rpi têm um diodo grampeador interno para 3,3V. Além disso, o pino e3 da placa PIC SanUSB tem um resistor de 2k2 ligado à fonte USB (5V), o que permite a 
aplicação da tensão de 3,3 V ao pino e3 de entrada do PIC, com tensão proveniente do pino Wpi 0 do Rpi através do fio azul e conectado de um lado do resistor 
de 2k2, como permite também a tensão de 5V (fonte USB da placa PIC) do outro lado deste resistor de 2k2, onde é aplicado a queda de tensão (5V - 3,3 V) para 
o pino Rpi 11 (Wpi 0), quando o pino e3 de entrada do PIC recebe nível lógico alto.

Caso seja utilizada  a comunicação serial, entre os pinos do PIC (5V) e do Rpi (3,3V), verifique se o jumper de tensão da porta USB (+5V) está removido, pois a 
alimentacao do microcontrolador vem do pino do 3,3V do Rpi, como o circuito abaixo, para que os dois possam se comunicar na mesma tensão (3,3V) e não ocorrer 
danos nos pinos por sobretensão em (5V). 
Com o pino físico 11 do Rpi, ou seja, wPi 0 ligado por um fio no pino 1 (pin_e3) do microcontrolador, execute o código WiringPiGCCParaGravarPICviaUSB para gravar 
e regravar o microcontrolador, como descrito abaixo:
//********************************************************************************************************
pi@raspberrypi ~ $ sudo su
root@raspberrypi:/home/pi# cd /home/share/SanUSBrpi/CodigoWiringPiParaGravarPICviaUSB/
root@raspberrypi:/home/share/SanUSBrpi/CodigoWiringPiParaGravarPICviaUSB# gcc -o WiringPiGCCParaGravarPICviaUSB WiringPiGCCParaGravarPICviaUSB.c -l wiringPi
root@raspberrypi:/home/share/SanUSBrpi/CodigoWiringPiParaGravarPICviaUSB# ./WiringPiGCCParaGravarPICviaUSB
Digite Ctrl+c para sair e gravar o microcontrolador via USB
^C
root@raspberrypi:/home/share/SanUSBrpi/CodigoWiringPiParaGravarPICviaUSB# /home/share/SanUSBrpi/./sanusb -w /home/share/SanUSBrpi/exemplo1.hex -r
SanUSB device found
Writing '/home/share/SanUSBrpi/exemplo1.hex':....
OK....
//********************************************************************************************************
Em substituicao ao código WiringPiGCCParaGravarPICviaUSB para regravacao do microcontrolador, é possível digitar diretamente no LXTerminal: 
gpio mode 0 out <Enter> (configura o pino wPi 0 como saída), depois:
 gpio write 0 0 <Enter> (escreve 0 no pino wPi 0 conectado ao pin_e3 do PIC para gravacao) e finalmente: 
gpio write 0 1 <Enter> (escreve 1 no pino wPi 0 conectado ao pin_e3 do PIC para operacao do microcontrolador após a gravacao).
root@raspberrypi:/home/share/SanUSBrpi/CodigoWiringPiParaGravarPICviaUSB# gpio mode 0 out
root@raspberrypi:/home/share/SanUSBrpi/CodigoWiringPiParaGravarPICviaUSB# gpio write 0 0
root@raspberrypi:/home/share/SanUSBrpi/CodigoWiringPiParaGravarPICviaUSB# gpio write 0 1
root@raspberrypi:/home/share/SanUSBrpi/CodigoWiringPiParaGravarPICviaUSB# /home/share/SanUSBrpi/./sanusb -w /home/share/SanUSBrpi/exemplo1.hex -r
SanUSB device found

A placa SanUSB pode ser construída seguindo o tutorial em https://www.youtube.com/watch?v=S30wVi9RWEs e os programas disponíveis em 
https://dl.dropbox.com/u/101922388/121007SanUSBOrig.zip ou adquirida em http://lista.mercadolivre.com.br/sanusb . Mais detalhes em: 
http://sanusb.blogspot.com.br/2015/02/gravando-pic-online-via-porta-usb-de-um.html
