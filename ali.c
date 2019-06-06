#include <stdio.h>
#include <stdlib.h>

#define ERRO_PILHA_VAZIA 100

typedef struct char_Pilha
{
    char aga;
    struct char_Pilha *proximo, *anterior;
}char_Pilha;

char_Pilha *InicializaPilha()
{
    char_Pilha *pilha;
    pilha = malloc(sizeof(char_Pilha));
    pilha->proximo = NULL;
    pilha->anterior = NULL;
    pilha->aga = 0;
    return pilha;
}

void push(char_Pilha **topo, char te)
{
    char_Pilha *top = *topo;
    top->proximo = malloc(sizeof(char_Pilha));
    top->proximo->anterior = top;
    top->proximo->proximo = NULL;
    top = top->proximo;
    top->aga = te;
    *topo = top;
}

char_Pilha* pop(char_Pilha **topo)
{
    if(PilhaVazia(topo))
        return NULL;
    char_Pilha *top = *topo;
    char_Pilha *nod = top;
    top = top->anterior;
    top->proximo = NULL;
    *topo = top;
    return nod;
}

int PilhaVazia(char_Pilha **pilha)
{
    char_Pilha *pi = *pilha;
    if(pi->anterior == NULL)
        return 1;
    else
        return 0;
}

char ConsultaPilha(char_Pilha **topo)
{
    char_Pilha *top = *topo;
    return top->aga;
}

void FinalizarPilha(char_Pilha **topo)
{
    char_Pilha *nod, *pilha = *topo;
    while(pilha->anterior != NULL)
    {
        nod = pilha->anterior;
        free(pilha);
        pilha = nod;
    }
    free(pilha);
    *topo = NULL;
}

void CopiarPilha(char_Pilha **pilhaOriginal, char_Pilha **pilhaCopia)
{
    char_Pilha *pilhaOr = *pilhaOriginal;
    char_Pilha *pilhaCop = NULL;
    while(pilhaOr->anterior != NULL)
    {
        pilhaOr = pilhaOr->anterior;
    }

    pilhaCop = malloc(sizeof(char_Pilha));
    pilhaCop->anterior = NULL;
    pilhaCop->proximo = NULL;
    pilhaCop->aga = pilhaOr->aga;
    pilhaOr = pilhaOr->proximo;
    
    while(pilhaOr != NULL)
    {
        pilhaCop->proximo = malloc(sizeof(char_Pilha));
        //pilhaCop->anterior = pilhaCop;
        //pilhaCop->proximo = NULL;
        //pilhaCop->aga = pilhaOr->aga;
        //pilhaOr = pilhaOr->proximo;
        if(pilhaOr->proximo != NULL)
            pilhaCop = pilhaCop->proximo;
    }
    
    *pilhaCopia = pilhaCop;
}

//Programa para checar palindromos
void main()
{
    char_Pilha *pilha, *apontador;
    char letra;
    char palavra[100];
    int i = 0;
    pilha = InicializaPilha();
    while(letra != '\n')
    {
        letra = getchar();
        if(letra == '\n')
            break;
        else if(letra != ' ')
        {
            push(&pilha, letra);
            palavra[i] = letra;
            i++;
        }
    }
    palavra[i] = '\0';
    i = 0;
    while(!PilhaVazia(&pilha))
    {
        apontador = pop(&pilha);
        //printf("%c", testee->aga);
        if(apontador->aga != palavra[i])
        {
            printf("não é palindromo, saindo...");
            return;
        }
        i++;
    }
    printf("\n\nÉ palindromo a palavra, serviço completo!\nSaindo...");
}