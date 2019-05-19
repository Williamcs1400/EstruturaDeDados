#include<stdio.h>
#include<stdlib.h>

struct dados
{
    int info;
};

typedef struct dados Data;

struct node
{
    Data elem;
    struct node *prox;
};

typedef struct node LADAE;

int ListaExiste(LADAE **inicio);

LADAE** criaLADAE();

int ehVaziaLADAE(LADAE **inicio);

int insereLADAE(LADAE **inicio, Data novo);

int RemoveElemento(LADAE **inicio, int remove);

int BuscarElemento(LADAE **inicio, int busca);

int ZeraLista(LADAE **inicio);

void imprimeLADAE(LADAE **inicio);

void liberaLADAE(LADAE **inicio);

