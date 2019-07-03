/*Universidade de Brasilia
  Instituto de Ciencias Exatas
  Departamento de Ciencia da Computacao
  Estrutura de Dados - 1/2019
  Aluno: William Coelho da Silva
  Professor: Vinicius Ruela Pereira Borges
  Matricula: 180029274
  Turma: A
  Versao do compilador: gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04)*/

#include "Headers_Blockchain.h"
#include "sha256.h"

int main(){
  ListaTimes **inicio = NULL;
  int operacao;


  system(CLEAR);

  do{
    printf(NEGRITO"\n(1) - Criar uma lista de times\n");
    printf("(2) - Adicionar informacoes de compra de um jogador\n");
    printf("(3) - Imprimir Lista\n");
    printf("(4) - Limpar toda a lista de times\n");
    printf("(0) - Sair do menu e encerrar o programa\n");

    printf("Selecione o que deseja fazer: ");
    scanf("%d", &operacao);

    if(operacao == 1){
      system(CLEAR);
      inicio = CriarLista();
      printf(VERDE"\nLista de times criada no endereco %p\n"RESET, inicio);
    }

    if(operacao == 2){

      system(CLEAR);

      if(ListaExiste(inicio) == 0){
        printf(VERMELHO"\nLista de times nao existe\n"RESET);
      }

      else{
        InserirTime(inicio);
        system(CLEAR);
      }
    }

    if(operacao == 3){
      system(CLEAR);
      if(ListaExiste(inicio) == 0){
        printf(VERMELHO"\nLista de times nao existe\n"RESET);
      }
      else if(ListaEhVazia(inicio)){
        printf(AMARELO"\nLista estah vazia\n"RESET);
      }
      else
        ImprimirLista(inicio);
    }

    if(operacao == 4){
      system(CLEAR);
      if(ListaExiste(inicio) == 0){
        printf(VERMELHO"\nLista de times nao existe\n"RESET);
      }
      else if(ListaEhVazia(inicio)){
        printf(AMARELO"\nA lista estah vazia\n"RESET);
      }
      else if(LimparLista(inicio)){
        printf(VERDE"\nA lista foi zerada com sucesso\n"RESET);
      } 
    }

  }while(operacao != 0);

  /*Limpar a lista ao final mesmo se o usuario nao escolher essa opcao no menu interativo*/  
  if(ListaExiste(inicio)){
    if(LimparLista(inicio)){
      printf(VERDE"\nA lista foi zerada com sucesso\n"RESET);
    }
  }

  printf("\nEncerrando operacoes...\n\n\n");

  return 0;
}
