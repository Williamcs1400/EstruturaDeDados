#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

struct dados{
  int info;
};

typedef struct dados Data;

struct fila{
  Data elem;
  struct fila *prox;
};

typedef struct fila Fila;

int FilaExiste(Fila **inicio);

int FilaEhVazia(Fila **inicio);

Fila** CriarFila();

int Enfileirar(Fila **inicio, Data novo);

int Desenfileirar(Fila **inicio);

void ImprimeFila(Fila **inicio);

void LimparFila(Fila **inicio);
