#include "types.h"
#include "user.h"
#include "syscall.h" 

#define haha 2147483649LL
 
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

	while(wait() != -1);   
	exit();             
}

void f1(void){
	int i=0; 	
	while(i<haha){
		i++;
	}
}



