#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

Pilha * pilha_cria(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    p->t=0;
    return p;
}

void pilha_push(Pilha* p, int v){
    Lista * t = (Lista*) malloc(sizeof(Lista));
    t->info = v;
    t->prox= p->prim;
    p->prim =t;
}

int pilha_pop(Pilha* p){
    if(vazia(p)){
        return 0;
    }
     Lista * t;
     float v;
     t = p->prim;
     v = t->info;
     p->prim = t->prox;
     free(t);
     return v;
}

int vazia(Pilha *p){
    return (p->prim==NULL);
}

void pilha_libera(Pilha*p){
    Lista* q= p->prim;
    Lista* t;
    while (q != NULL) {
        t = q->prox;
        free(q);
        q = t;

    }
    free(p);
}

void imprime(Pilha*l){
	Lista*p;
	for(p=l->prim; p!=NULL; p=p->prox){
		printf("\t %d \n", p->info);
	}
}

int topo(Pilha* p){
	if(!vazia(p)){
    Lista * t;
     int v;
     t = p->prim;
     v = t->info;
     return v;
 }
 else return 0;
     
 
}

