/*Problema Torre de Hanoi com busca em porfundidade */

#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include <math.h>
#define D 7 //Quantidade de discos
int movimentos = (pow(2,D)-1);
int contador=0;

typedef struct estado{
	Pilha * torre1;
	Pilha * torre2;
	Pilha * torre3;
	int N;
}Estado;

int top(Estado e){
    if (!vazia(e.torre1) && topo(e.torre1) == 1 ){
        return 1;
    }
    else if (!vazia(e.torre2) && topo(e.torre2) == 1){
        return 2;
    }
    else if (!vazia(e.torre3) && topo(e.torre3) == 1){
        return 3;
    }
}

void imprimeTorre(Estado e);

Estado Expande(Estado e){
	int i, d1, d2;
	i = movimentos;
		int t = top(e);
		if (!(i%2==0)){
			if(!(D%2==0)){
			switch(t){
				case 1:
					printf("1-3 \n");
					pilha_push(e.torre3, pilha_pop(e.torre1));
					break;
				case 2: 
				printf("2-1 \n");
					pilha_push(e.torre1, pilha_pop(e.torre2));
					break;
				case 3: 
				printf("3-2 \n");
					pilha_push(e.torre2, pilha_pop(e.torre3));
					break;
			}
		}
		else{
			switch(t){
				case 1:
					printf("1-2 \n");
					pilha_push(e.torre2, pilha_pop(e.torre1));
					break;
				case 2: 
				printf("2-3\n");
					pilha_push(e.torre3, pilha_pop(e.torre2));
					break;
				case 3: 
				printf("3-1 \n");
					pilha_push(e.torre1, pilha_pop(e.torre3));
					break;
			}
		}
		}
		else{
			switch(t){
				case 1:
					d1 = topo(e.torre2);
                	d2 = topo(e.torre3);
                	if (d1 < d2 && d1!=0 || vazia(e.torre3)){
                		printf("2-3 \n\n");
                    	pilha_push(e.torre3,pilha_pop(e.torre2));
                	}
                	else if (d1 > d2 && d2!=0 || vazia(e.torre2)){
                		printf("3-2 \n\n");
                    	pilha_push(e.torre2,pilha_pop(e.torre3));
                	}
					break;
				case 2:
					d1 = topo(e.torre1);
                	d2 = topo(e.torre3);
                	if (d1 < d2 && d1!=0 || vazia(e.torre3)){
                		printf("1-3 \n\n");
                		pilha_push(e.torre3,pilha_pop(e.torre1));
                	}
                	else if (d1 > d2 && d2!=0 || vazia(e.torre1)){
                		printf("3-1 \n\n");
                		pilha_push(e.torre1,pilha_pop(e.torre3));
                	}
					break;
				case 3:
					d1 = topo(e.torre1);
                	d2 = topo(e.torre2);
                	if (d1 < d2 && d1!=0 || vazia(e.torre2)){
                		printf("1-2 \n\n");
                		pilha_push(e.torre2,pilha_pop(e.torre1));
                	}
                	else if (d1 > d2 && d2!=0 || vazia(e.torre1)){
                		printf("2-1 \n\n");
                		pilha_push(e.torre1,pilha_pop(e.torre2));
                	}
					break;
			}
		}
		movimentos--;
		contador++;
	return e;
}


int Estado_objetivo(Estado *e){
	if(e->torre1->prim==NULL && e->torre2->prim==NULL){
		printf("Estado Objetivo encontrado!!! \n");
		return 1;
	}
	else return 0;
}

int BPL(Estado e){
	if(Estado_objetivo(&e)){
		return 1;
	}
	e = Expande(e);
	imprimeTorre(e);
	if(BPL(e)){
		return 1;
	}
return 0;
}



int main(int argc, char *argv[]) {
	int n;
	Estado e;
	e.torre1 = pilha_cria();
	e.torre2 = pilha_cria();
	e.torre3 = pilha_cria();
	e.N = D;
	for(n=D; n!=0; n--){
		pilha_push(e.torre1, n);
	}
	imprimeTorre(e);
	BPL(e);
	printf("Chamadas a expande: %d \n", contador);
	pilha_libera(e.torre1);
	pilha_libera(e.torre2);
	pilha_libera(e.torre3);
	return 0;
}

void imprimeTorre(Estado e){
	printf("\nEstado:\n");
	printf("1-Torre\n");
	imprime(e.torre1);
	printf("2-Torre\n");
	imprime(e.torre2);
	printf("3-Torre\n");
	imprime(e.torre3);
}
