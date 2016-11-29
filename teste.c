#include "types.h"
#include "user.h"
#include "syscall.h" 
 
 
void f1(void);

int main (int argh,char *argv[]){
	int p[argh];
	int j;
	for(j=0;j<argh;j++){      //Cria os filhos com a quantidade de argumeentos de "argh"
	  p[j]=atoi(argv[j]);     //Converte char pra int
	  if(fork(p[j])==0){      //Cria filhos
	      f1();               //comendo tempo
	      exit(); 
     }
    }

	for(j=0;j<100000;j++) {
		wait();             //esperando os filhos
	}
	exit();                 
}

void f1(void){
	int i=0;	
	while(i<5900000000){
		i++;
	}
}



