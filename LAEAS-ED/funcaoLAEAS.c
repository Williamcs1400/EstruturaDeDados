#include "headersLAEAS.h"

void Inicializa(Celula *lista){
    lista->fim = -1;
}

int EhCheia(Celula lista){
    if(lista.fim == MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

int EhVazia(Celula *lista){
    if(lista->fim == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void ImprimeLista(Celula lista){
    int i, V_vazia;
    V_vazia = EhVazia(&lista);
    if(V_vazia == 1){
        printf("A lista eh Vazia");
    }
    else{
        for(i=0; i<=lista.fim-1; i++){
            if(lista.elem[i] > 0){
                printf("%d ", lista.elem[i]);
            }
        }
        printf("\n");
    }
}

void PreencherLista(Celula *lista){
    int i;
    printf("Digite os elementos positivos para preencher a lista de até %d elementos\n", MAX);
    for(i=0; i<MAX-1; i++){
        scanf("%d", &lista->elem[i]);
        lista->fim = i;
        if(lista->elem[i] < 0)
            break;
    }
}

void InserirFinal(Celula *lista){
    int V_cheia, elemento, posi = lista->fim;
    V_cheia = EhCheia(*lista);
    if(V_cheia == 1){
        printf("A lista estah cheia, nao eh possivel inserir um elemento\n");
    }
    else{
        printf("Digite um elemento: ");
        scanf("%d", &elemento);
        lista->elem[posi] = elemento;
        lista->fim++;
    }
}

void InserirInicio(Celula *lista){
    int i, V_cheia, elemento;
    V_cheia = EhCheia(*lista);
    if(V_cheia == 1){
        printf("A lista estah cheia, nao eh possivel inserir um elemento\n");
    }
    else{
        printf("Digite um elemento: ");
        scanf("%d", &elemento);
        for(i=lista->fim+1; i>0; i--){
            lista->elem[i] = lista->elem[i-1];
        }
        lista->elem[0] = elemento;
        lista->fim++;
    }
}

void RemoverInicio(Celula *lista){
	int i;
	for(i=lista->fim; i>0; i--){
		lista->elem[i] = lista->elem[i-1];
	}
	
	lista->fim--;
}

void RemoveFinal(Celula *lista){
	int posi = lista->fim;
	lista->elem[posi] = -1;
	lista->fim--;
}