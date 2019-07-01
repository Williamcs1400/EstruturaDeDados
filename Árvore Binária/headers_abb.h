#include <stdio.h>
#include <stdlib.h>

struct dados{
    int valor;
};

typedef struct dados Data;

struct node{
    Data info;
    struct node *pai;
    struct node *f_esq;
    struct node *f_dir;
};

typedef struct node ABB;

ABB** CriaArvore();

int ABBExiste(ABB **raiz);

int ABBEhVazia(ABB **raiz);

int InsereABB(ABB **raiz, Data novo);

int InsereCaminhaABB(ABB *nodo, Data novo);

void CaminhaProfundidade(ABB **raiz, int opcao);

void CaminhaInOrdem(ABB *nodo);

int Busca(ABB *raiz, int busca);

int Remove(ABB *raiz, int remove);

int LimparLista(ABB *raiz);
