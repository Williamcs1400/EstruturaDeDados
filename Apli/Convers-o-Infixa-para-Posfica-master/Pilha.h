#include <stdio.h>
#include <stdio.h>

#define MAX 50
#define FALSE 0;
#define TRUE 1;



typedef char TIPOCHAVE;

typedef struct{
	TIPOCHAVE chave;
}REGISTRO;

typedef struct{
	REGISTRO a[MAX];
	int topo;
}PILHA;

void inicializarPilha(PILHA *pilha);
int cheia(PILHA *pilha);
int vazia(PILHA * pilha);
REGISTRO criarReg(TIPOCHAVE chave);
int empilha(REGISTRO reg, PILHA *pilha);
int desempilha( PILHA *pilha);
void exibirPilha(PILHA *pilha);
int topo(PILHA *pilha);
