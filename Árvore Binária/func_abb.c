#include "headers_abb.h"

ABB** CriaArvore(){
    ABB **novo;

    novo = (ABB**) malloc(sizeof(ABB*));

    *novo = NULL;

    return novo;
}

int ABBExiste(ABB **raiz){
    if(raiz == NULL){
        return 0;       /*Caso de nao existir*/
    }
    else
        return 1;
}

int ABBEhVazia(ABB **raiz){
    if(*raiz == NULL){
        return 1;       /*Caso de ser vazia*/
    }
    else
        return 0;
}

int LimparLista(ABB *raiz){
    ABB *aux;
    aux = raiz;

    if(aux != NULL){
        LimparLista(aux->f_esq);
        LimparLista(aux->f_dir);
        aux->f_dir = NULL;
        aux->f_esq = NULL;
        free(aux);
        return 1;
    }
}

int Remove(ABB *raiz, int remove){
    int flag = 0;
    ABB *ant, *filho;
    if(raiz->info.valor == remove){

        if(raiz->f_dir == NULL && raiz->f_esq == NULL){ /*Para o caso de nao ter nenhum filho*/
            ant = raiz->pai;

            if((ant->f_dir)->info.valor == raiz->info.valor){ 
                free(raiz);
                ant->f_dir = NULL;
            }
            if((ant->f_esq)->info.valor == raiz->info.valor){ 
                free(raiz);
                ant->f_esq = NULL;
            }
            return 1;
        }
        
        /*if((raiz->f_dir != NULL && raiz->f_esq == NULL) || (raiz->f_dir == NULL && raiz->f_esq != NULL)){ Para o caso de ter um filho apenas
            
        }*/
        
    }
    if(raiz->info.valor > remove){
        return Remove(raiz->f_esq, remove);
    }
    if(raiz->info.valor < remove){
        return Remove(raiz->f_dir, remove);
    }
    else
        return 0;
}

int Busca(ABB *raiz, int busca){
    int flag = 0;

    if(raiz == NULL){
        return 0;
    }
    if(raiz->info.valor == busca){
        flag = 1;
    }
    if(raiz->info.valor > busca){
        return Busca(raiz->f_esq, busca);
    }
    if(raiz->info.valor < busca){
        return Busca(raiz->f_dir, busca);
    }
    else
        return flag;
}

void VisitaNode(ABB *nodo){
    
    printf("%d\n", nodo->info.valor);

}

void CaminhaInOrdem(ABB *nodo){
    if(nodo == NULL){
        return ;
    }
    CaminhaInOrdem(nodo->f_esq);
    VisitaNode(nodo);
    CaminhaInOrdem(nodo->f_dir);
}

void CaminhaPreOrdem(ABB *nodo){
    if(nodo == NULL){
        return ;
    }
    VisitaNode(nodo);
    CaminhaPreOrdem(nodo->f_esq);
    CaminhaPreOrdem(nodo->f_dir);
}

void CaminhaPosOrdem(ABB *nodo){
    if(nodo == NULL){
        return ;
    }
    CaminhaPosOrdem(nodo->f_esq);
    CaminhaPosOrdem(nodo->f_dir);
    VisitaNode(nodo);
}

void CaminhaProfundidade(ABB **raiz, int opcao){
    if(ABBEhVazia(raiz) == 0){
        if(opcao == 1){
            CaminhaPreOrdem(*raiz);
        }
        else if(opcao == 2){
            CaminhaInOrdem(*raiz);
        }
        else if(opcao == 3){
            CaminhaPosOrdem(*raiz);
        }
    }
}

int InsereCaminhaABB(ABB *nodo, Data novo){
    ABB *novo_nodo;

    if(novo.valor < nodo->info.valor){
        if(nodo->f_esq == NULL){
            novo_nodo = (ABB*) malloc(sizeof(ABB));
            if(novo_nodo != NULL){
                novo_nodo->info = novo;
                novo_nodo->pai = nodo;
                novo_nodo->f_esq = NULL;
                novo_nodo->f_dir = NULL;

                nodo->f_esq = novo_nodo;

                return 1;
            }
            else
                return 0;
        }
        else
            return InsereCaminhaABB(nodo->f_esq, novo);
    }
    else{
        if(novo.valor > nodo->info.valor){
            if(nodo->f_dir == NULL){
                novo_nodo = (ABB*) malloc(sizeof(ABB));
                if(novo_nodo != NULL){
                    novo_nodo->info = novo;
                    novo_nodo->pai = nodo;
                    novo_nodo->f_dir = NULL;
                    novo_nodo->f_esq = NULL;

                    nodo->f_dir = novo_nodo;
                    return 1;
                }
                else
                    return 0;
            }
            else{
                return InsereCaminhaABB(nodo->f_dir, novo);
            }
        }
    }
     
}

int InsereABB(ABB **raiz, Data novo){
    ABB *novo_no;

    if(ABBEhVazia(raiz)){
        novo_no = (ABB*) malloc(sizeof(ABB));

        if(novo_no != NULL){
            novo_no->info = novo;
            novo_no->pai = NULL;
            novo_no->f_dir = NULL;
            novo_no->f_esq = NULL;

            *raiz = novo_no;

            return 1;
        }
        else
            return 0;
    }
    else{
        return InsereCaminhaABB(*raiz, novo);
    }
}
