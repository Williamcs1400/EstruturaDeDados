#include "Headers_Fila.h"

int main(){
  Fila **inicio;
  Data aux;
  int op;

  inicio = NULL;
  system(CLEAR);
  printf("\n");
  do{
    printf("(1) - Iniciar a fila\n");
    printf("(2) - Inserir elemento da fila\n");
    printf("(3) - Desenfileirar\n");
    printf("(4) - Imprimir Filaz\n");
    printf("(5) - Limpar Fila\n");
    printf("(0) - Sair do programa\n");
    printf("Selecione a operação desejada: ");
    scanf("%d", &op);

    if(op == 1){
      system(CLEAR);
      inicio = CriarFila();
      printf("\nA fila foi criada no endereco: %p\n\n", inicio);
    }

    if(op == 2){
      system(CLEAR);
      if(FilaExiste(inicio) == 0){
        printf("\nA fila nao existe\n\n");
      }
      else{
        printf("\nDigite o elemento que deseja enfileirar: ");
        scanf("%d", &aux.info);
        system(CLEAR);
        if(Enfileirar(inicio, aux) == 1){
          printf("\nO elemento %d foi enfileirado com sucesso\n\n", aux.info);
        }
        else{
          printf("\nNao foi possivel enfileirar o elemento desejado\n\n");
        }
      }
    }

    if(op == 3){
      system(CLEAR);
      if(Desenfileirar(inicio)){
        printf("\nO ex primeiro elemento foi desenfileirado com sucesso\n\n");
      }
      else
        printf("\nNao foi possivel desenfileirar\n\n");
    }

    if(op == 4){
      system(CLEAR);
      if(FilaExiste(inicio) == 0){
        printf("\nFila nao existe\n\n");
      }
      else if(FilaEhVazia(inicio) == 1){
        printf("\nFila estah vazia\n\n");
      }
      else{
        ImprimeFila(inicio);
      }
    }

    if(op == 5){
      system(CLEAR);
      LimparFila(inicio);
      printf("\nA fila foi zerada com sucesso\n\n");
    }

  }while(op != 0);

  LimparFila(inicio);
  free(inicio);
  inicio = NULL;
  return 0;
}
