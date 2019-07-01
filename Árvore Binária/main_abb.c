#include "headers_abb.h"
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int main(){
    ABB **raiz = NULL;
    Data aux;
    int op, ordem, busca, remove;

    system(CLEAR);

    do{
        printf("\n(1) - Cria e inicializa a arvore binaria\n");
        printf("(2) - Inserir um elemento na arvore\n");
        printf("(3) - Imprimir Arvore\n");
        printf("(4) - Buscar elemento na arvore\n");
        printf("(5) - Remover elemento da arvore\n");
        printf("(6) - Limpar a arvore binaria\n");
        printf("(0) - Encerra o programa\n");
        printf("Digite a operacao desejada: ");
        scanf("%d", &op);


        if(op == 1){
            system(CLEAR);
            raiz = CriaArvore();

            printf("\nArvore inicializada com sucesso\n");
        }

        if(op == 2){
            system(CLEAR);

            if(ABBExiste(raiz) == 0){
                printf("\nA arvore nao existe\n");
            }
            else{
                printf("Digite o valor que deseja inserir: ");
                scanf("%d", &aux.valor);

                if(InsereABB(raiz, aux) == 0){
                    printf("\nNao foi possivel inserir - erro na alocacao do no");
                }
                else
                    printf("\nElemento inserido com sucesso\n");
            }
        }

        if(op == 3){
            system(CLEAR);
            if(ABBExiste(raiz) == 0){
                printf("A arvore nao existe\n");
            }
            else if(ABBEhVazia(raiz) == 1){
                printf("A arvore estah vazia\n");
            }
            else{
                printf("\n(1) - Imprimir PosOrdem\n");
                printf("(2) - Imprimir InOrdem\n");
                printf("(3) - Imprimir PreOrdem\n");
                printf("Digite a opcao desejada: ");
                scanf("%d", &ordem);

                system(CLEAR);
                CaminhaProfundidade(raiz, ordem);
            }
        }

        if(op == 4){
            system(CLEAR);
            if(ABBExiste(raiz) == 0){
                printf("A arvore nao existe\n");
            }
            else if(ABBEhVazia(raiz) == 1){
                printf("A arvore estah vazia\n");
            }
            else{
                printf("\nDigite o valor que deseja buscar na arvore: ");
                scanf("%d", &busca);

                if(Busca(*raiz, busca) == 1){
                    printf("O elemento %d estah na arvore binaria\n", busca);
                }
                else
                    printf("O elemento %d nao estah na arvore binaria\n", busca);
            }
        }

        if(op == 5){
            system(CLEAR);
            if(ABBExiste(raiz) == 0){
                printf("A arvore nao existe\n");
            }
            else if(ABBEhVazia(raiz) == 1){
                printf("A arvore estah vazia\n");
            }
            else{
                printf("\nDigite o elemento que deseja remover na arvore: ");
                scanf("%d", &remove);

                if(Busca(*raiz, remove) == 0){
                    printf("O elemento %d nao pode ser removido pois nao estah na arvore\n", remove);
                }
                else{
                    if(Remove(*raiz, remove) == 1){
                        printf("O elemento %d foi removido com sucesso\n", remove);
                    }
                }
            }
        }

        if(op == 6){
            system(CLEAR);
            if(ABBExiste(raiz) == 0){
                printf("A arvore nao existe\n");
            }
            else if(ABBEhVazia(raiz) == 1){
                printf("A arvore estah vazia\n");
            }
            else{
                if(LimparLista(*raiz)){
                    printf("Lista limpa com sucesso\n");
                }
            }
        }
        if(op == 10)
        printf("raiz: %d", (*raiz)->info.valor);


    }while(op != 0);

    if(ABBExiste(raiz) == 0){
        printf("A arvore nao existe\n");
    }
    else if(ABBEhVazia(raiz) == 1){
        printf("A arvore estah vazia\n");
    }
    else{
        if(LimparLista(*raiz)){
            printf("Lista limpa com sucesso\n");
        }
    }
    
    return 0;
}