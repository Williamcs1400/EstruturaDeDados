#include "Headers_Blockchain.h"
#include "sha256.h"

ListaTimes** CriarLista(){
  ListaTimes **novo;

  novo = (ListaTimes**) malloc(sizeof(ListaTimes*));

  *novo = NULL;

  return novo;
}

int ListaEhVazia(ListaTimes **inicio){
  if(*inicio == NULL){
    return 1;
  }
  else
    return 0;
}

int ListaExiste(ListaTimes **inicio){
  if(inicio == NULL){
    return 0;
  }
  else
    return 1;
}

void FazerStringHash(ListaTimes **inicio, ListaTimes *node, int vazio){
  ListaTimes *pont_aux;
  int i, tam_string;
  char *temp;
  char *aux;

  pont_aux = *inicio;

  BYTE buf[SHA256_BLOCK_SIZE];
  SHA256_CTX ctx;

  temp = (char*) malloc(sizeof(char) * 1000); /*30 bites x 10 transacoes = 900 - considerando os /0 fica mais ou menos 1000 */

  aux = temp;

  /*Copia as transacoes do bloco para a string temp*/
  if(vazio == 1){
    for(i = 0; i < node->fim; i++){
      sprintf(temp, "%s%s%s", node->clube[i].nome_clube_comprador, node->clube[i].nome_clube_vendedor, node->clube[i].nome_jogador);
      
      tam_string = strlen(node->clube[i].nome_clube_comprador) + strlen(node->clube[i].nome_clube_vendedor) + strlen(node->clube[i].nome_jogador);
      
      temp += tam_string; /*Atualizar a posicao de temp para nao sobreescrever*/
    } 
  }
  else{
    
    while(pont_aux->prox != node){  /*Atualizar o posisao do proximo ate o anterior do nodo atual*/
      pont_aux = pont_aux->prox;
    }
    for(i = 0; i < node->fim; i++){
      sprintf(temp, "%s%s%s%s", node->clube[i].nome_clube_comprador, node->clube[i].nome_clube_vendedor, node->clube[i].nome_jogador);
      
      tam_string = strlen(node->clube[i].nome_clube_comprador) + strlen(node->clube[i].nome_clube_vendedor) + strlen(node->clube[i].nome_jogador) + strlen(pont_aux->hash);
      
      temp += tam_string; /*Atualizar a posicao de temp para nao sobreescrever*/
    }
  }
  

  sha256_init(&ctx);
  sha256_update(&ctx, aux, strlen(aux));
  sha256_final(&ctx, node->hash);

  free(aux);
}

void InserirTime(ListaTimes **inicio){
  int i, opera = 1, cont = 0, flag = 0;
  DadosTimes temp;
  ListaTimes *aux, *novotime;
  aux = *inicio;

  novotime = (ListaTimes*) malloc(sizeof(ListaTimes));

  /*Insercao dos dados de todas as transacoes*/
  do{

    if(flag == 0){
      printf("Digite o nome do clube comprador: ");
      scanf("%s", temp.nome_clube_comprador);
      flag = 1;
    }

    printf("Digite o nome do clube vendedor: ");
    scanf("%s", temp.nome_clube_vendedor);

    printf("Digite o nome do jogador negociado: ");
    scanf("%s", temp.nome_jogador);

    printf("Digite o valor da transferencia do jogador em milhoes de euros: ");
    scanf("%f", &temp.valor_transferencia);

    /*Salvar essa transacao na lista*/
    novotime->clube[cont] = temp;
    cont++;

    if(cont == MAX - 1){
      printf("\nBloco estah cheio\n");
      break;
    }
    
    printf("Digite '1' para inserir mais uma transacao ou digite '0' para encerrar: ");
    scanf("%d", &opera);

    printf("\n");

  }while(opera != 0);

  novotime->fim = cont;
  novotime->prox = NULL;

  if(ListaEhVazia(inicio)){
    *inicio = novotime;
    FazerStringHash(inicio, *inicio, 1); /*Se ele for vazia ativa o modo de nao levar em consideracao as hash anteriores*/
  }
  else{
    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = novotime;
    FazerStringHash(inicio, aux, 0);  /*Se ele nao for vazia ativa o modo de levar em consideracao as hash anteriores*/
  }
}

int TamanhoPalavra(char palavra[30]){ /*Retorna tamanho da palavra para calcular a quantidade de espacos para printar*/

  return strlen(palavra);

}

void ImprimeEspacos(int tamanho){ /*Imprime espacos para a palavra ficar centralizada*/
  int i, qtd;

  qtd = 30 - tamanho;
  qtd = qtd / 2;

  for(i = 0; i < qtd; i++){
    printf(" ");
  }

}

void ImprimirLista(ListaTimes **inicio){
  ListaTimes *aux;
  aux = *inicio;
  int i;

  if(ListaEhVazia(inicio)){
    printf("\nA Lista de Times estah vazia\n");
  }
  else{

    printf("\n");
    printf(NEGRITO);

    ImprimeEspacos(TamanhoPalavra("ClubeComprador"));
    printf("Clube Comprador");
    ImprimeEspacos(TamanhoPalavra("ClubeComprador"));

    ImprimeEspacos(TamanhoPalavra("ClubeVendedor"));
    printf("Clube vendedor");
    ImprimeEspacos(TamanhoPalavra("ClubeVendedor"));

    ImprimeEspacos(TamanhoPalavra("NomeDoJogador"));
    printf("Nome do jogador");
    ImprimeEspacos(TamanhoPalavra("NomeDoJogador"));

    printf("Valor da Transferencia em milhoes de euros(€)");

    printf(RESET"\n\n");

    while(aux != NULL){

      for(i = 0; i < aux->fim; i++){

        ImprimeEspacos(TamanhoPalavra(aux->clube[i].nome_clube_comprador));
        printf(VERDE"%s", aux->clube[i].nome_clube_comprador);
        ImprimeEspacos(TamanhoPalavra(aux->clube[i].nome_clube_comprador));

        ImprimeEspacos(TamanhoPalavra(aux->clube[i].nome_clube_vendedor));
        printf(VERMELHO"%s", aux->clube[i].nome_clube_vendedor); 
        ImprimeEspacos(TamanhoPalavra(aux->clube[i].nome_clube_vendedor));

        ImprimeEspacos(TamanhoPalavra(aux->clube[i].nome_jogador));
        printf(AZUL"%s", aux->clube[i].nome_jogador);   
        ImprimeEspacos(TamanhoPalavra(aux->clube[i].nome_jogador));

        ImprimeEspacos(0);
        printf(AMARELO"       %.2fM€", aux->clube[i].valor_transferencia); 

        printf(RESET"\n");

      }
      aux = aux->prox;
    }
  }
}

int LimparLista(ListaTimes **inicio){
  ListaTimes *aux, *post;
  post = *inicio;

  while(post != NULL){
    aux = post->prox;
    free(post);
    post = aux;
  }
  *inicio = NULL;

  return 1;
}
