#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void inicializarFila(FILA *fila){
	fila->inicio = 0;
	fila->fim = 0;
	fila->qtdelem = 0;
}

int fila_cheia(FILA *fila){
	return fila->qtdelem == MAX;
}

int fila_vazia(FILA *fila){
	return fila->qtdelem == 0;
}

int avancar(int i){
	i++;
	
	if(i >= MAX){
		return FALSE;
	}
	return i;
}

int insere_fila(REGISTRO_Fila elem, FILA *fila){
	if(fila_cheia(fila)){
		return FALSE;
	}

	fila->a[fila->fim] = elem;
	fila->fim = avancar(fila->fim);
	fila->qtdelem++;
}

void exibirFila(FILA *fila){
	int i;
	printf("Resultado: ");
	
	for(i = 0; i < fila->fim; i++){
		printf("%c", fila->a[i].chave);
	}
	printf("\n");
}

REGISTRO_Fila CriarReg(TIPOCHAVE chave) {
 REGISTRO_Fila reg;
 reg.chave = chave;
 return reg;
}


