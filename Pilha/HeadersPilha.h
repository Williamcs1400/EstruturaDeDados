#include <stdio.h>
#include <stdlib.h>

struct dados{
  int info;
};

typedef struct dados Data;

struct pilha{
  Data elem;
  struct pilha *prox;
};

typedef struct pilha Pilha;

int PilhaExiste(Pilha **topo);

int PilhaEhVazia(Pilha **topo);

Pilha** CriarPilha();

void EmpilharElemento(Pilha **topo, Data novo);

void ImprimePilha(Pilha **topo);
