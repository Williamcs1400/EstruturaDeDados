#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define FALSE 0;
#define TRUE 1;


typedef char TIPOCHAVE;

typedef struct{
	TIPOCHAVE chave;
}REGISTRO_Fila;

typedef struct{
	REGISTRO_Fila a[MAX];
	int inicio;
	int fim;
	int qtdelem;
}FILA;

void inicializarFila(FILA *fila);
REGISTRO_Fila CriarReg(TIPOCHAVE chave);
int insere_fila(REGISTRO_Fila elem, FILA *fila);
int fila_cheia(FILA *fila);
int fila_vazia(FILA *fila);
int avancar(int i);
void exibirFila(FILA *fila);


