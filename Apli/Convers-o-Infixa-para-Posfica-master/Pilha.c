#include <stdio.h>
#include "Pilha.h"

void inicializarPilha(PILHA *pilha){
	pilha->topo = 0;
}

int cheia(PILHA *pilha){
	return pilha->topo == MAX;
}

int vazia(PILHA * pilha){
	return pilha->topo == 0;
}

int empilha(REGISTRO reg, PILHA *pilha){
	if(cheia(pilha)){
		return FALSE;	
	}
	
	pilha->a[pilha->topo] = reg;
	pilha->topo++;
	return TRUE;
}

int desempilha( PILHA *pilha){
	if(vazia(pilha)){
		return FALSE;
		
	}
	pilha->topo--;
	return TRUE;
}

void exibirPilha(PILHA *pilha){
	int i;
	printf("Pilha: [");
	for(i = 0; i< pilha->topo; i++){
		printf("%c", pilha->a[i].chave);
	}
	printf("]\n");
}

REGISTRO criarReg(TIPOCHAVE chave) {
 REGISTRO reg;
 reg.chave = chave;
 return reg;
}

int topo(PILHA *pilha) {
 return pilha->a[pilha->topo-1].chave;
}

