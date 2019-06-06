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

int VerParent(Pilha **topo, char *expre){
    Pilha *novoelem, *aux;
    int i;

    for(i = 0; expre[i] != '\0'; i++){
        aux = *topo;
        if(expre[i] == '('){
            novoelem = (Pilha*) malloc(sizeof(Pilha));
            if(PilhaEhVazia(topo)){
                novoelem->elem = '(';
                novoelem->prox = NULL;
                *topo = novoelem;
            }
            else{
                novoelem->elem = '(';
                novoelem->prox = *topo;
                *topo = novoelem;
            }
        }
        if(expre[i] == ')'){
            if(PilhaEhVazia(topo)){
                return 0;
            }
            else{
                if(aux->elem == '('){
                    LimparTopo(topo);
                }
            }
        }
    }
    return 1;
}


int main(){
    char expre[1000];
    int result;

    while(scanf("%s", expre) !=  EOF){
        Pilha **topo;
        
        topo = CriarPilha();

        result = VerParent(topo, expre);

        if((result == 0) || !PilhaEhVazia(topo)){
            printf("incorrect\n");
        }
        else
            printf("correct\n");
    }
    
    return 0;
}
