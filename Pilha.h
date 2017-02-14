typedef struct pilha Pilha;

typedef struct lista Lista;

struct lista{
    int info;
    struct lista * prox;
};

struct pilha{
	Lista * prim;
	int t;
};

Pilha * pilha_cria(void);

void pilha_push(Pilha* p, int v);

int pilha_pop(Pilha* p);

void pilha_libera(Pilha*p);

int vazia(Pilha *p);

void imprime(Pilha*l);

int topo(Pilha* p);

