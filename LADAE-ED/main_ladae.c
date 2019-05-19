#include"ladae.h"
#define SUCESSO 1
#define FALHA 0

int main()
{
    LADAE **lista;
    LADAE *node;
    Data aux;
    int r;
    
    int elem, op=-1, busca;
    
    lista = NULL;
    
    do
    {          
        printf("\n\t\tMenu interativo\n\n");
        printf("(1) Criar e Inicializar LADAE\n");
        printf("(2) Inserir elemento no inicio\n");
        printf("(3) Inserir elemento no final\n");
        printf("(4) Remover elemento no inicio\n");
        printf("(5) Remover elemento no final\n");
        printf("(6) Buscar um elemento na LADAE\n");
        printf("(7) Zerar LADAE\n");
        printf("(0) SAIR\n");
        printf("Digite sua opcao: ");
        scanf("%d",&op);
        
        if(op == 1){
            lista = criaLADAE();

            printf("Endereço do primeiro no da lista: %p\n",*lista);
            printf("Endereço da lista: %p\n",lista);
            
            printf("Lista LADAE inicializada com sucesso\n");
        }

        if(op == 2){
            if(ListaExiste(lista) == 0){
                printf("\nA lista nao existe\n");
            }
            else{
                printf("Digite um elemento: ");
                scanf("%d",&aux.info);
                if(insereInicioLADAE(lista,aux) == SUCESSO)
                {
                    printf("Elemento inserido %d com sucesso\n",elem);
                }
                printf("\n\n\t\t\tImprime lista\n");
                imprimeLADAE(lista);
                printf("\n\n");
            }
        }

        if(op == 3){
            
            if(ListaExiste(lista) == 0){
                printf("\nA lista nao existe\n");
            }
            else{
                printf("Digite um elemento: ");
                scanf("%d",&aux.info);
                if(insereFinalLadae(lista, aux) == 1){
                    printf("\n\n\t\t\tImprime lista\n");
                    imprimeLADAE(lista);
                    printf("\n\n");
                }
            }
        }

        if(op == 4){

            if(ListaExiste(lista) == 0){
                printf("\nA lista nao existe\n");
            }
            else{
                if(RemoveInicio(lista) == 1){
                    printf("Elemento removido com sucesso\n");
                }
                else{
                    printf("Não foi possivel remover o elemento");
                }
                printf("\n\n\t\t\tImprime lista\n");
                imprimeLADAE(lista);
                printf("\n\n");
            }
        }

        if(op == 5){
            if(ListaExiste(lista) == 0){
                printf("\nA lista nao existe\n");
            }
            else{
                if(RemoveFinal(lista) == 1){
                    printf("Elemento removido com sucesso\n");
                }
                else{
                    printf("Nao foi possivel remover o elemento\n");
                }
                printf("\n\n\t\t\tImprime lista\n");
                imprimeLADAE(lista);
                printf("\n\n");
                
            }
        }

        if(op == 6){
            if(ListaExiste(lista) == 0){
                printf("\nA lista nao existe\n");
            }
            else{
                printf("Digite o elemento a ser buscado na lista\n");
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

        if(op == 7){
            if(ListaExiste(lista) == 0){
                printf("\nA lista nao existe\n");
            }
            else{
                if(ZeraLista(lista) == 0){
                    printf("\nA lista ja estah vazia\n");
                }
                else if(ZeraLista(lista) == 1){
                    lista == NULL;
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
