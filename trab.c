#include <stdio.h>
#define MAX 6

struct lista{
    int elem[MAX];
    int fim;
};

typedef struct lista Lista;

int main(){
    int i, posi = 0;
    Lista aux;
    aux.fim = -1;

    for(i = 0; i < MAX; i++){
        scanf("%d", &aux.elem[i]);
        aux.fim++;
    }

    for(i = 0; posi <= aux.fim; i++){
        printf("%d ", aux.elem[posi]);
        posi = i % MAX;
    }
    printf("\n");

    return 0;
}