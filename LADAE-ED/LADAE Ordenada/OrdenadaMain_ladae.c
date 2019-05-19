#include"Ordenanaladae.h"
#define SUCESSO 1
#define FALHA 0
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int main()
{
    LADAE **lista;
    LADAE *node;
    Data aux;
    int r;
    
    int elem, op=-1, busca, remove;
    
    lista = NULL;
    system(CLEAR);
    
    do
    {          
        printf("\n\t\tMenu interativo - LADAE Ordenada\n\n");
        printf("(1) Criar e Inicializar LADAE\n");
        printf("(2) Inserir elemento\n");
        printf("(3) Remover um elemento\n");
        printf("(4) Buscar um elemento na LADAE\n");
        printf("(5) Zerar LADAE\n");
        printf("(0) SAIR\n");
        printf("Digite sua opcao: ");
        scanf("%d",&op);
        
        if(op == 1){
            lista = criaLADAE();
            system(CLEAR);
            printf("Endereço do primeiro no da lista: %p\n",*lista);
            printf("Endereço da lista: %p\n",lista);
            printf("Lista LADAE inicializada com sucesso\n");
        }

        if(op == 2){
            system(CLEAR);
            if(ListaExiste(lista) == 0){
                printf("\nA lista nao existe\n");
            }
            else{
                printf("Digite um elemento: ");
                scanf("%d",&aux.info);
                if(insereLADAE(lista,aux) == SUCESSO)
                {
                    printf("Elemento inserido %d com sucesso\n",elem);
                }
                printf("\n\n\t\t\tImprime lista\n");
                imprimeLADAE(lista);
                printf("\n\n");
            }
        }

        if(op == 3){
            system(CLEAR);
            if(ListaExiste(lista) == 0){
                printf("\nA lista nao existe\n");
            }
            else{
                printf("Digite o elemento que deseja remover a lista: ");
                scanf("%d", &remove);
                if(RemoveElemento(lista, remove) == 1){
                    printf("Elemento removido com sucesso\n");
                }
                else{
                    printf("Não foi possivel remover o elemento, ele nao estah na lista");
                }
                printf("\n\n\t\t\tImprime lista\n");
                imprimeLADAE(lista);
                printf("\n\n");
            }
        }

        if(op == 4){
            system(CLEAR);
            if(ListaExiste(lista) == 0){
                printf("\nA lista nao existe\n");
            }
            else{
                printf("Digite o elemento a ser buscado na lista: ");
                scanf("%d", &busca);
                if(BuscarElemento(lista, busca) == -2){
                    printf("A lista estah vazia\n");
                }
                else if(BuscarElemento(lista, busca) == -1){
                    printf("O elemento não estah na lista\n");
                }
                else{
                    printf("O elemento estah na lista na posicao %d\n", BuscarElemento(lista, busca));
                }
            }
        }

        if(op == 5){
            system(CLEAR);
            if(ListaExiste(lista) == 0){
                printf("\nA lista nao existe\n");
            }
            else{
                if(ZeraLista(lista) == 0){
                    printf("\nA lista ja estah vazia\n");
                }
                else if(ZeraLista(lista) == 1){
                    printf("\n\n\t\t\tImprime lista\n");
                    imprimeLADAE(lista);
                    printf("\n\n");
                }
            }
        }
        
    }while(op != 0);
    
    printf("Encerrando as operações...\n");
    
    liberaLADAE(lista);
    
    return 0;
}
