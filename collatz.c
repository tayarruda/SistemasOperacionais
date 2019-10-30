
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

//Tayná Arruda Câmara da Silva
//20190153061

int main(void){
	int x, pid=-1;
	printf("Forneca x: ");
  	scanf("%d", &x);

  	if(x>0 && x!= 1){
		pid = fork();
	}


	if(pid < 0){
		printf("\nFalha na criação do filho\n");
		exit(-1);
	}

	if(pid > 0){
		printf("\nProcesso Pai depois da criação do processo filho\n");
		wait();
	}else{
		printf("\nProcesso filho\n");
		while (x != 1) {
    			if (x % 2 == 0){
      				x /= 2;
    			}else{
      				x = 3 * x + 1;
			}
			printf("%d - ",x);
  		}

	}
	exit(0);
}


