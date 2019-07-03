#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> /*Para usar a funcao 'srand's*/
//#include "sha256.h"


/*Definir cores para imprimir no terminal*/
#define PRETO "\033[30m"
#define VERMELHO "\033[31m"
#define VERDE "\033[32m"
#define AMARELO "\033[33m"
#define AZUL "\033[34m"
#define ROXO "\033[35m"
#define CIANO "\033[36m"
#define NEGRITO "\033[1m"
#define RESET "\033[0m"  /*Reseta a cor do terminal*/

/*Tamanho do bloco de transacoes*/
#define MAX 10

/*Defines para gerar o hash*/
#define GERA 50
#define TAM_PALAVRA 5

/*Declaracao para conseguir limpar a tela em ambos os sistemas operacionais*/
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

/*Estrutura dos dados a serem relacionados com cada clube*/
struct inf{
  char nome_clube_comprador[30];
  char nome_clube_vendedor[30];
  char nome_jogador[30];
  float valor_transferencia;
};

typedef struct inf DadosTimes;

/*Estrutura de lista para relacionar cada time com suas caracteristicas*/
struct nodes{
  DadosTimes clube[MAX];
  int fim;                /*Saber onde acabam as transacoes digitadas pelo usuario*/
  unsigned char hash[32];          /*Valor inteiro gerado a partir de caracteres aleatorios*/
  struct nodes *prox;
};

typedef struct nodes ListaTimes;

/*Estrutura de arvore para armmazenar os blocos*/
struct Arvore{ 
    /*????????????????????????????*/
    struct node *pai;
    struct node *f_esq;
    struct node *f_dir;
};

typedef struct Arvore ABB;

ListaTimes** CriarLista(); /*Aloca dinamicamente uma lista e retorna o endereco*/

int ListaEhVazia(ListaTimes **inicio); /*Retorna 1 se eh vazia 0 se nao for vazia*/

int ListaExiste(ListaTimes **inicio); /*Retorna 1 se a lista existe ou 0 se nao existe*/

void InserirTime(ListaTimes **inicio); /*Funcao que permite inserir todas as informacoes do time*/

void ImprimirLista(ListaTimes **inicio); /*Imprime todos os times indicando as informacoes*/

int LimparLista(ListaTimes **inicio); /*Percorre a lista e limpa todos os times*/

void FazerStringHash(ListaTimes **inicio, ListaTimes *node, int vazio); /*Concatena strings para poder fazer o hash*/
