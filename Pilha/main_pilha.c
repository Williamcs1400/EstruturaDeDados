#include "HeadersPilha.h"
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int main(){
  Pilha **topo;
  Data aux;
  int op;
  topo = NULL;

  system(CLEAR);
  do{

    printf("Digite a operacao desejada para realizar na pilha:\n");
    printf("(1) - Criar/inicializar a pilha de dados\n");
    printf("(2) - Empilhar novos elementos\n");
    printf("(3) - Buscar elemento da pilha\n");
    printf("(4) - Remover elemento na pilha\n");
    printf("(5) - Imprimir Pilha\n");
    printf("(6) - Ver topo\n");
    printf("(7) - Liberar Pilha\n");
    printf("(0) - Sair\n");
    scanf("%d", &op);

    if(op == 1){
      system(CLEAR);
      topo = CriarPilha();
      printf("\nPilha criada com sucesso no endereco: %p \n\n", topo);
    }

    if(op == 2){
      system(CLEAR);
      if(PilhaExiste(topo) == 0){
        printf("A pilha nao existe\n");
      }
      else{
        printf("Digite o elemento que deseja empilhar: ");
        scanf("%d", &aux.info);
        EmpilharElemento(topo, aux);
        system(CLEAR);
        printf("\nElemento %d empilhado com sucesso\n\n", aux.info);
      }
    }

    if(op == 3){
      system(CLEAR);
      if(PilhaExiste(topo) == 0){
        printf("A pilha nao existe\n");
      }
      if(PilhaEhVazia(topo) == 1){
        printf("A pilha estah vazia\n");
      }
      else{
        printf("Digite o elemento que deseja buscar na pilha: ");
        scanf("%d", &aux.info);
        system(CLEAR);
        if(BuscarElemento(topo, aux) == -1){
          printf("\nO elemento nao estah na pilha\n\n");
        }
        else{
          printf("\nO elemento estah na pilha na posicao %d\n\n", BuscarElemento(topo, aux));
        }
      }
    }

    if(op == 4){
      system(CLEAR);
      if(PilhaExiste(topo) == 0){
        printf("A pilha nao existe\n");
      }
      if(PilhaEhVazia(topo) == 1){
        printf("A pilha estah vazia\n");
      }
      else{
        printf("Digite o elemento que deseja remover da pilha: ");
        scanf("%d", &aux.info);
        system(CLEAR);
        if(BuscarElemento(topo, aux) == -1){
          printf("\nO elemento nao estah na pilha\n");
        }
        else{
          if(RemoverElemento(topo, aux)){
            printf("\nElemento %d removido com sucesso\n", aux.info);
          }
        }
      }
    }

    if(op == 5){
      system(CLEAR);
      if(PilhaExiste(topo) == 0){
        printf("A pilha nao existe\n");
      }
      else{
        ImprimePilha(topo);
      }
    }

    if(op == 6){
      system(CLEAR);
      if(PilhaEhVazia(topo) == 0){
        aux = VerTopo(topo);
        printf("\nTopo => %d\n\n", aux.info);
      }
      else
        printf("\nA pilha eh vazia\n");
    }

    if(op == 7){
      system(CLEAR);
      LimparPilha(topo);
    }

  }while(op != 0);

  if(topo != NULL){
    LimparPilha(topo);
    free(topo);
  }

  return 0;
}
