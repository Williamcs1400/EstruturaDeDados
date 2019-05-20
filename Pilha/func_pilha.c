#include "HeadersPilha.h"

int PilhaExiste(Pilha **topo){
  if(topo == NULL){
    return 0;
  }
  else
    return 1;
}

int PilhaEhVazia(Pilha **topo){
  if(*topo == NULL){
      return 1;
  }
  else
    return 0;
}

Pilha** CriarPilha(){
  Pilha **novo;

  novo = (Pilha **) malloc(sizeof(Pilha *));
  *novo = NULL;

  return novo;
}

void EmpilharElemento(Pilha **topo, Data novo){
  Pilha *novoelem, *aux;
  aux = *topo;

  novoelem = (Pilha*) malloc(sizeof(Pilha*));

  if(PilhaEhVazia(topo) == 1){
    novoelem->elem = novo;
    novoelem->prox = NULL;

    aux = novoelem;
  }
  else{
    novoelem->elem = novo;
    novoelem->prox = aux;

    aux = novoelem;
  }
}

void DescerTopo(Pilha **topo){
  Pilha *aux, *aux1;

  aux = *topo;
  aux1 = aux;

  if(aux->prox == NULL){
    *topo = NULL;
  }
  else{
    aux = aux->prox;
    free(aux);
  }
}

void ImprimePilha(Pilha **topo){
  Pilha **aux, *aux1;
  aux1 = *topo;
  Data temp;

  if(PilhaEhVazia(topo) == 1){
    printf("A pilha estah vazia\n");
  }
  else{
    printf("\nTopo =>");
    while(topo != NULL){
      temp.info = (aux1->elem).info;
      printf("       %d", temp.info);
      EmpilharElemento(aux, temp);
      DescerTopo(topo);
    }
    while(aux != NULL){
      EmpilharElemento(topo, temp);
      DescerTopo(aux);
    }
  }
}
