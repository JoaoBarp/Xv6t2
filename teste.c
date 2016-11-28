#include "types.h"
#include "user.h"
#include "syscall.h" 
 
 
void f1(void);

int main (int argh,char *argv[]){
	int p[argh];
	int j;
	for(j=0;j<argh;j++){      //Cria os filhos com a quantidade de argumeentos de "argh"
	  p[j]=atoi(argv[j]);    //Converte char pra int
	  if(fork(p[j])==0){     //Cria filhos
	      f1();              //comendo tempo
	      exit(); 
     }
    }

	for(j=0;j<10000;j++) {
		wait();             //esperando os filhos
	}
	exit();                 
}

void f1(void){
	int i=0;	
	while(i<50000000){
		i++;
	}
}







int buscaMaisDeumpassoZero(){
	int count=0;
	struct proc *p;
	for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
		if(p->cpasso == 0){count++;}
	}	
	if(count > 2){return 1;}
	else{return 0;}
}


BuscaMaiorPasso(){

struct proc *p;
for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){}

}

BuscamaiorPIDcomPasso=Zero(){

struct proc *p;
for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){}

}





void
scheduler(void)
{
  struct proc *p;
  int escolhaPorPID=0;

  for(;;){
    // Enable interrupts on this processor.
    sti();
    acquire(&ptable.lock);

    if(buscaMaisDeumpassoZero() == TRUE){
		MPid=BuscamaiorPIDcomPasso=Zero();
		for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
    		if(p->state == RUNNABLE && p->pid == MPid){
				break;
			}
		}
	}else{
		Mpasso=BuscaMaiorPasso();
		for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
    		if(p->state == RUNNABLE && p->cpasso == MPasso){
				break;
		}
	}
	p->Mpasso = p->Mpasso + (100000/p->ptick);

      // Switch to chosen process.  It is the process's job
      // to release ptable.lock and then reacquire it
      // before jumping back to us.	
      proc = p;
      switchuvm(p);
      p->state = RUNNING;
      swtch(&cpu->scheduler, p->context);
      switchkvm();

      // Process is done running for now.
      // It should have changed its p->state before coming back.
      proc = 0;
    }
    release(&ptable.lock);

  }
}
