#include <stdio.h>
#include <stdlib.h>

struct node{
    char elem;
    struct node *prox;
};

typedef struct node Pilha;

Pilha** CriarPilha(){
    Pilha **novo;

    novo = (Pilha **) malloc(sizeof(Pilha*));

    *novo = NULL;

    return novo;
}

int PilhaEhVazia(Pilha **topo){
    if(*topo == NULL){
        return 1;
    }
    else 
        return 0;
}

void LimparTopo(Pilha **topo){
    Pilha *aux;

    aux = *topo;

    if(*topo == NULL){
        *topo = NULL;
    }
    else{
        *topo = aux->prox;
        free(aux);
    }
}

int VerMaiorMenor(Pilha **topo, char *expre){
    Pilha *novoelem, *aux;
    int i, cont = 0;

    for(i = 0; expre[i] != '\0'; i++){
        aux = *topo;
        if(expre[i] == '<'){
            novoelem = (Pilha*) malloc(sizeof(Pilha));
            if(PilhaEhVazia(topo)){
                novoelem->elem = '<';
                novoelem->prox = NULL;
                *topo = novoelem;
            }
            else{
                novoelem->elem = '<';
                novoelem->prox = *topo;
                *topo = novoelem;
            }
        }
        if(expre[i] == '>'){
            if(PilhaEhVazia(topo)){
                LimparTopo(topo);
            }
            else{
                if(aux->elem == '<'){
                    cont++;
                    LimparTopo(topo);
                }
            }
        }
    }
    return cont;
}

int main(){
    char expre[1000];
    int result, qtd, i = 0;

    scanf("%d", &qtd);

    while(i < qtd){
        scanf("%s", expre);
        Pilha **topo;
        
        topo = CriarPilha();

        result = VerMaiorMenor(topo, expre);

        printf("%d\n", result);
        i++;
    }
    
    return 0;
}