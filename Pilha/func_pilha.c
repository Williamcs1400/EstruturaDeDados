#include "HeadersPilha.h"
int cont = 0;

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
  Pilha *novoelem;

  novoelem = (Pilha*) malloc(sizeof(Pilha));

  if(PilhaEhVazia(topo) == 1){
    novoelem->elem = novo;
    novoelem->prox = NULL;

    *topo = novoelem;
  }
  else{
    novoelem->elem = novo;
    novoelem->prox = *topo;

    *topo = novoelem;
  }
}

void DescerTopo(Pilha **topo){ /*Desempihar*/
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

Data VerTopo(Pilha **topo){
  Pilha *aux;
  Data temp;

  aux = *topo;
  temp = (aux->elem);

  return temp;
}

int BuscarElemento(Pilha **topo, Data busca){
  Pilha **aux, *aux1;
  int posi = 0, flag = 0;
  Data temp;

  aux1 = *topo;

  aux = CriarPilha();

  if(PilhaEhVazia(topo) == 1){
    printf("A pilha estah vazia\n");
  }
  else{
    while(aux1 != NULL){
      temp.info = (aux1->elem).info;
      if(busca.info == (aux1->elem).info){
        posi++;
        flag = 1;
      }
      EmpilharElemento(aux, temp);
      DescerTopo(topo);
      aux1 = *topo;
      if(flag == 0){
        posi++;
      }
    }
    while(*aux != NULL){
      temp = VerTopo(aux);
      EmpilharElemento(topo, temp);
      DescerTopo(aux);
    }
  }
  free(aux);

  if(flag == 0){
    return -1;
  }
  else
    return posi;
}

int RemoverElemento(Pilha **topo, Data remove){
  Pilha **aux, *aux1, *prox, *ant;
  Data temp;
  int flag = 0;

  aux1 = *topo;

  ant = aux1;

  aux = CriarPilha();

  if(PilhaEhVazia(topo) == 1){
    printf("A pilha estah vazia\n");
  }
  //Para caso queria remover um elemento do meio da pilha
  /*temp = VerTopo(topo);
  if(remove.info == temp.info){
    *topo = aux1->prox;
    flag = 1;
  }
  else{
    while(aux1 != NULL){
      prox = aux1->prox;
      temp.info = (aux1->elem).info;
      if(remove.info == temp.info){
        free(aux1);
        ant->prox = prox->prox;
        flag = 1;
      }
      EmpilharElemento(aux, temp);
      DescerTopo(topo);
      aux1 = *topo;
      ant = aux1;
    }
    while(*aux != NULL){
      temp = VerTopo(aux);
      EmpilharElemento(topo, temp);
      DescerTopo(aux);
    }
  }
  free(aux);*/
  if(flag == 1){
    return 1;
  }
  else
    return 0;
}

void ImprimePilha(Pilha **topo){
  Pilha **aux, *aux1;
  Data temp;

  aux1 = *topo;

  aux = CriarPilha();

  if(PilhaEhVazia(topo) == 1){
    printf("A pilha estah vazia\n");
  }
  else{
    printf("Topo =>");
    while(aux1 != NULL){
      temp.info = (aux1->elem).info;
      if(cont == 0){
        printf("%d\n", temp.info);
        cont++;
      }
      else{
        printf("       %d\n", temp.info);
      }
      EmpilharElemento(aux, temp);
      DescerTopo(topo);
      aux1 = *topo;
    }
    while(*aux != NULL){
      temp = VerTopo(aux);
      EmpilharElemento(topo, temp);
      DescerTopo(aux);
    }
  }
  printf("\n");
  free(aux);
  cont = 0;
}

void LimparPilha(Pilha **topo){
  Pilha *aux, *aux1;
  aux = *topo;

  while(aux != NULL){
    aux1 = aux->prox;
    free(aux);
    aux = aux1;
  }
  *topo = NULL;
}
