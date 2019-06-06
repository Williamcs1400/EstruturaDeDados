#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int carta;
    struct lista *prox;
}Lista;

typedef struct fila{
    Lista *ini;
    Lista *fim;
}Fila;

Fila* CriarFila(){
    Fila *novo;
    
    novo = (Fila*) malloc(sizeof(Fila));
    novo->ini = NULL;
    novo->fim = NULL;

    return novo;
}

void *ColocarCartas(Fila *pont, int card){
    Lista *novoelem;

    novoelem = (Lista*) malloc(sizeof(Lista));

    novoelem->carta = card;
    novoelem->prox = NULL;

    if(pont->ini == NULL){
        pont->ini = novoelem;
        pont->fim = novoelem;
    }
    else{
        pont->fim->prox = novoelem;
        pont->ini = novoelem;
    }
}

int Baralho(Fila *pont){
    int card;
    Lista *aux;
    
    aux = pont->ini;
    card = aux->carta;

    pont->ini = aux->prox;
    if(pont->ini == NULL){
        pont->fim = NULL;
    }
    free(aux);
    
    return  card;
}

int FilaEhVazia(Fila *pont){
    if(pont->ini == NULL){
        return 1;
    }
    else
        return 0;
}


int main(){
    int n, i, carta, cont = 0;
    Fila *inicio;

    inicio = CriarFila();

    do{
        scanf("%d", &n);

        if(n != 0){
            cont = n;
            for(i = 1; i <= n; i++){
                ColocarCartas(inicio, i);
            }

            printf("Discarded cards: ");
            while(cont != 1){
                printf("%d, ", Baralho(inicio));
                ColocarCartas(inicio, Baralho(inicio));

                
                cont--;
            }
            if(FilaEhVazia(inicio)){
                printf("\nRemaining card: %d\n", Baralho(inicio));
            }

        }
    }while(n != 0);
    return 0;
}