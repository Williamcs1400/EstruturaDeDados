#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info{
    char produto[50];
    float preco;
};

typedef struct info Data;

struct node{
    Data elem;
    struct node *prox;
};

typedef struct node Lista;

Lista** CriaLista(){
    Lista **novo;

    novo =  (Lista**) malloc(sizeof(Lista*));

    *novo = NULL;
    return novo;
}

int EhVaziaLista(Lista **inicio){
    if(*inicio == NULL){
        return 1;
    }
    else
        return 0;
}

void LimparLista(Lista **inicio){
    Lista *aux, *post;
    
    post = *inicio;

    do{
        aux = post;
        post = aux->prox;
        free(aux);
    }while(aux->prox != NULL);
    free(aux);
    *inicio = NULL;
}

float LerProdutos(Lista **inicio){

    int i, qtd_produtos, qtd_disponivel, qtd;
    float resultado = 0;
    Lista *novoelem, *pont_aux;
    Data aux;

    scanf(" %d", &qtd_disponivel);

    for(i = 0; i < qtd_disponivel; i++){
        novoelem = (Lista*) malloc(sizeof(Lista));
        novoelem->prox = NULL;
        if(EhVaziaLista(inicio)){
            scanf(" %s %f", aux.produto, &aux.preco);
            novoelem->elem = aux;
            *inicio = novoelem; 
        }
        else{
            scanf(" %s %f", aux.produto, &aux.preco);
            novoelem->elem = aux;
            novoelem->prox = *inicio;
            *inicio = novoelem;
        }
    }

    scanf(" %d", &qtd_produtos);

    for(i = 0; i < qtd_produtos; i++){
        scanf(" %s %d", aux.produto, &qtd);

        pont_aux = *inicio;

        while(pont_aux != NULL){
            if(!strcmp(aux.produto, (pont_aux->elem).produto)){
                resultado += (pont_aux->elem).preco * qtd;
                break;
            }
            else{
                pont_aux = pont_aux->prox;
            }
        }
    }
    return resultado;
}

int main(){
    Lista **inicio = NULL;
    int qtd_idas, i = 0;

    inicio = CriaLista();

    scanf(" %d", &qtd_idas);

    float vet_resp[qtd_idas];
    
    while(i < qtd_idas){
        vet_resp[i] = LerProdutos(inicio);
        ++i;
    }
    LimparLista(inicio);

    for(i = 0; i < qtd_idas; i++){
        printf("%.2f\n", vet_resp[i]);
    }
    return 0;
}