#include <stdio.h>
#define MAX 10

struct lista1{
    int fim;
    int elem[MAX];
};

typedef struct lista1 Celula;

void Inicializa(Celula *lista);

int EhCheia(Celula lista);

int EhVazia(Celula *lista);

void ImprimeLista(Celula lista);

void PreencherLista(Celula *lista);

void InserirFinal(Celula *lista);

void InserirInicio(Celula *lista);

void RemoverInicio(Celula *lista);

void RemoveFinal(Celula *lista);