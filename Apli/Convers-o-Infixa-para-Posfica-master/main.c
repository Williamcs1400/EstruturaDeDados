#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include <string.h>
#include "Pilha.h"


void ConverteInf(char expressao[]){
	FILA fila_posfixa_saida;
	PILHA pilha_auxiliar;
	
	inicializarPilha(&pilha_auxiliar);
	inicializarFila(&fila_posfixa_saida);
	
	
	int i;
	char aux;
	for(i = 0; i< strlen(expressao); i++){
		
			if((expressao[i] == '(')){
			empilha(criarReg(expressao[i]), &pilha_auxiliar);	
			}
			
			else if((expressao[i] == ')') ) {
				while(topo(&pilha_auxiliar) != '('){
				aux= topo(&pilha_auxiliar);
				insere_fila(CriarReg(aux), &fila_posfixa_saida);
				desempilha(&pilha_auxiliar);
				}
			desempilha(&pilha_auxiliar); 
			}
			
			
			else if((expressao[i] == '+') || (expressao[i] == '-')){
				while(topo(&pilha_auxiliar)!= '('){
					aux = topo(&pilha_auxiliar);
					insere_fila(CriarReg(aux), &fila_posfixa_saida);
					desempilha(&pilha_auxiliar);
				}
				empilha(criarReg(expressao[i]), &pilha_auxiliar);   
			}
			
			else if((expressao[i] == '*') || (expressao[i] == '/')){
				while((topo(&pilha_auxiliar) != '(') && (topo(&pilha_auxiliar) != '+') && (topo(&pilha_auxiliar) != '-')){
					aux = topo(&pilha_auxiliar);
					insere_fila(CriarReg(aux), &fila_posfixa_saida);
					desempilha(&pilha_auxiliar);
				}
				empilha(criarReg(expressao[i]), &pilha_auxiliar);	
			}
			
			else{
				insere_fila(CriarReg(expressao[i]), &fila_posfixa_saida);
				
			}
		
		}
	exibirFila(&fila_posfixa_saida);
}




int main() {
	char inf[MAX];

	printf("Digite a expressao a ser convertida para a forma posfixa ou ENTER para sair.\n");
		fgets(inf, 50, stdin);
 		inf[strlen(inf)-1]= '\0';
 
	while(strlen(inf) > 0){
		ConverteInf(inf);
		
		printf("Digite a expressao a ser convertida para a forma posfixa ou ENTER para sair.\n");
		fgets(inf, 50, stdin);
		inf[strlen(inf)-1]= '\0';	
	}
		
	return 0;
}
