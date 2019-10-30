#include <pthread.h>

#include <stdio.h>

#include <stdlib.h>

#define NUM_THREADS 2



//Tayná Arruda Câmara da Silva

//20190153061

/* 
as funcoes para serem passadas para a criacao da thread
precisam ter o modelo -> void * nome_da_função(void *arg) 
pois deve receber qualquer informacao e retornar tambem 
*/

//sequencia de collatz
void *Collatz(void *n)
{
	int x, 
	x = (int)n;//convertendo o parametro da funcao

	//printf("Forneca x: ");

  	//scanf("%d", &x);


	while (x != 1) {

    		if (x % 2 == 0){

      			x /= 2;

    		}else{

 			x = 3 * x + 1;

		}

		printf("%d - ",x);
  	}

//fim da thread filha 0
	printf("\n fim");
	pthread_exit(NULL);
}



//sequencia de fibonacci

void *Fibonacci(void *n)
{
	
	
	int num;
	
	num = (int)n; //convertendo o parametro da funcao
	
	int i, fib1 = 1, fib2 = 1, soma; 

	
	printf(" \n----- Sequência de Fibonacci ----- \n");
	 
        
	printf("%d, ", fib1); 
	printf("%d, ", fib2); 
      
     
	for (i = 3; i <= num; i = i + 1){                                        
        
		soma = fib1 + fib2;                    
        
		fib1 = fib2;                           
        
		fib2 = soma;
	
		printf("%d, ", fib2);                           
    
}                      
	
//fim da thread filha 1
	printf("\n fim");
	pthread_exit(NULL);
}



int main (int argc, char *argv[])
{

//pthread_create : inicializa a thread, retorna um valor *void
//0              - sucesso
//codigo de erro - falha
	
	pthread_t threads[NUM_THREADS]; //numero de threads 
	int err1, err2; //verificação da funcao pthread_create()
	
	int num;//

	
	printf("\nInforme um número inteiro, positivo, maior ou igual a 2 \n");
	
//recebendo do usuário um número inteiro, positivo, maior ou igual a 2 (n ≥ 2).
	scanf("%d", &num);
	
	if(num>=2){
	
		
// Criando a thread da sequencia de collatz
		
/*
		 
- &threads[0] : a referencia para a thread collatz;
    		 
- NULL por padrao;
		 
- Collatz: nome da funcao que a thread ira executar;
		 
- (void *)num: passa o parametro da funcao Collatz(tipo void*
) para a thread		
*/
		
	err1 = pthread_create(&threads[0], NULL, Collatz, (void *)num);
		
		
// Criando a thread da serie de fibonacci
		
/*
		 
- &threads[1] : a referencia da thread fibonacci;
    		 
- NULL por padrao;
		 
- Fibonacci :nome da função que a thread ira executar;
		 
- (void *)num: passa o parametro da funcao Collatz(tipo void*
) para a thread		
*/
		
	err2 = pthread_create(&threads[1], NULL, SerieFibonacci, (void *)num);

//verificando	
		
		
	if (err1){
		  
		printf("ERROR; %d\n", err1);
		  
		exit(-1);
		
	}

		
	if (err2){
		  
		printf("ERROR; %d\n", err2);
		  
		exit(-1);
			
	}else {
		
		printf("\n O número não é válido, precisa ser maior ou igual a 2! \n");
	
	} 
	
	
//final da thread mae;
	
	pthread_exit(NULL);

}
