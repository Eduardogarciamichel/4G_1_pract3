#include <18F4620.h>
#include <STDIO.H>
#include <stdlib.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use RS232(BAUD=9600,XMIT=PIN_C6,rcv=PIN_C7,BITS=8,PARITY=N,STOP=1)

#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use fast_io(e)

int validarCadena(char vect[], int cont);
int evaluarBackSpace(char vect[], int cont);

void main (void){
   setup_oscillator(OSC_16MHZ);
   set_tris_b(0x00);
   set_tris_d(0x00);
   char dato[15];
   signed long resultado = 0x00;
   int contCaracter = 0x00, flagValido = 0x00;
   printf("Hola");
   printf("\r");
   while(1){
      if(kbhit()){
         dato[contCaracter] = getch(); 
         printf("%c", dato[contCaracter]);
         evaluarBackSpace(dato,contCaracter);
         if(dato[contCaracter] == 13){
            if(dato[0] == '<' && dato[contCaracter-1] == '>'){
               flagValido = (dato, contCaracter);
                  if(flagValido == 0x01){
                     for (int i = 0; i<contCaracter; i++){
                        printf("%c", dato[contCaracter]);
                        printf("\r");
                        contCaracter = 0x00;
                     }
                  }
                  else{
                     printf("Cadena no valida");
                     printf("\r");
                     contCaracter = 0x00;
                  }
            }
            else{
               printf("Valores no validos");
               printf("\r");
               contCaracter = 0x00;
            }
             contCaracter = 0x00;
         }  
         else
            contCaracter++;
      }
   } 
}


int validarCadena(char vect[], int cont){
   int contValido = 0x00;
      for(int i = 1; i < cont-1; i++){
         if(vect[i] > 41 && vect[i] < 58){
            contValido++;
            if (contValido == cont-2){
               return 0x01;
            }
         }
         else
            return 0x00;
      }
}

int evaluarBackSpace(char vect[], int cont){
   if(vect[cont] == 8){
      return cont-2;
   }
   else{
      return cont;
   }
}

void mostrarDatos(char vect[],int tam){
   for(int i = 0; i < tam; i++){
      printf("%c",vect[i]);
      printf("\r");                       
   }
}