#include <stdio.h>
#include "headersLAEAS.h"

int main(){
    Celula lista;
    int opera;

    Inicializa(&lista);
    PreencherLista(&lista);

    do{
        printf("\nDigite a operação que deseja fazer: \n");
        printf("Digite 1 para imprimir a lista\n");
        printf("Digite 2 para inserir elemento no inicio da lista;\n");
        printf("Digite 3 para inserir elemento no final da lista;\n");
        printf("Digite 4 para remover elemento no inicio da lista;\n");
        printf("Digite 5 para inserir elemento no inicio da lista;\n");
        printf("Digite 0 para encerrar.\n");
        scanf("%d", &opera);

        if(opera == 1)
            ImprimeLista(lista);

        if(opera == 2)
            InserirInicio(&lista);

        if(opera == 3)
            InserirFinal(&lista);

        if(opera == 4)
        	RemoverInicio(&lista);

        if(opera == 5)
        	RemoveFinal(&lista);

    }while(opera != 0);


    return 0;
}