#include "Headers_Fila.h"

int FilaExiste(Fila **inicio){
  if(inicio == NULL){
    return 0;
  }
  return 1;
}

int FilaEhVazia(Fila **inicio){
  if(*inicio == NULL){
    return 1;
  }
  return 0;
}

Fila** CriarFila(){
  Fila **novo;

  novo = (Fila **) malloc(sizeof(Fila *));
  *novo = NULL;

  return novo;
}

int Enfileirar(Fila **inicio, Data novo){
  Fila *aux, *novoelem;
  aux = *inicio;
  int flag = 0;

  novoelem = (Fila*) malloc(sizeof(Fila));

  novoelem->elem = novo;
  novoelem->prox = NULL;

  if(FilaEhVazia(inicio) == 1){
    *inicio = novoelem;
    flag = 1;
  }
  else{
    while(aux->prox != NULL){
      aux = aux->prox;
    }
    if(aux->prox == NULL){
      aux->prox = novoelem;
      flag = 1;
    }
  }
  if(flag == 1){
    return 1;
  }
  return 0;
}

int Desenfileirar(Fila **inicio){
  Fila *aux;
  aux = *inicio;

  *inicio = aux->prox;
  free(aux);
  return 1;
}

void ImprimeFila(Fila **inicio){
  Data temp;
  Fila **aux, *aux1;

  aux1 = *inicio;

  aux = CriarFila();
  printf("\n");

  while(aux1 != NULL){
    temp.info = (aux1->elem).info;
    printf("%d -> ", temp.info);
    Enfileirar(aux, temp);
    Desenfileirar(inicio);
    aux1 = *inicio;
  }
  while(*aux != NULL){
    temp.info = ((*aux)->elem).info;
    Enfileirar(inicio, temp);
    Desenfileirar(aux);
  }
  free(aux);
  printf("\n\n");
}

void LimparFila(Fila **inicio){
  while(*inicio != NULL){
    Desenfileirar(inicio);
  }
}
