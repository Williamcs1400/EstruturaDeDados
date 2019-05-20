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
      ImprimePilha(topo);
    }
  }while(op != 0);

  return 0;
}
