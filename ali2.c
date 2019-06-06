/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Exercício Palindromo em C para a aula de Algoritmos e Estrutura de Dados 1 usando pilhas encadeadas
*   Assignment Palindrome in C language from the subject Algorithms and Data Structures 1 using Stacks
*   Finalizado em 23/09/2017 - Concluded in 09/23/2017
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char letra;
    struct no *anterior;
}ponto;

void inserir(ponto **main, char *word, int tam);
int pop(ponto **Point);
void imprimir(ponto *Point);
int pointerLength(ponto *Point);
int compara(ponto *Point);
void imprimir(ponto *Point);

int main(){
    ponto *palavra = NULL;
    printf("IDENTIFICACAO DE PALINDROMOS\n\n");
    printf("Entre com a palavra: ");
    char word[64];
    fgets(word, sizeof(word), stdin);
    int tam = strlen(&word)-1;
    inserir(&palavra, &word, tam);
    printf("\n");
    imprimir(palavra);
    if(compara(palavra))
        printf(" e palindromo");
    else
        printf(" nao e palindromo");
    return 0;
}

void inserir(ponto **main, char *word, int tam){
    int i;
    for(i = 0; i < tam; i++)
        push(main, word[i]);
}

void push (ponto **Point, char letra) {
    ponto *pont = malloc(sizeof(ponto));
    if(pont == NULL)
        printf("Memoria insulficiente\n");
    else{
       pont->anterior = *Point;
       pont->letra = letra;
       *Point = pont;
    }
}

int pop(ponto **Point) {
    if(Point != NULL){
        ponto *aux = (*Point)->anterior;
        free(*Point);
        (*Point) = aux;
        return 1;
    }
    return 0;
}

int pointerLength(ponto *Point){
    int i = 0, j = 0, k;
    ponto *aux;
    if(Point != NULL)
        for(aux = Point; aux != NULL; aux = aux->anterior)
            i++;
    return i;
}

int compara(ponto *Point){
    int j = 0, k;
    ponto *aux;
    if(Point != NULL){
        char auxiliar[pointerLength(Point)];
        for(aux = Point; aux != NULL; aux = aux->anterior)
            auxiliar[j++] = aux->letra;
        j--;
        aux = Point;
        for(k = j; k >= 0; k--){
            if(aux->letra != auxiliar[k])
                return 0;
            aux = aux->anterior;
        }
        return 1;
    }
    return 0;
}

void imprimir(ponto *Point){
    int j = 0, k;
    ponto *aux;
    if(Point != NULL){
        char auxiliar[pointerLength(Point)];
        for(aux = Point; aux != NULL; aux = aux->anterior)
            auxiliar[j++] = aux->letra;
        j--;
        for(k = j; k >= 0; k--)
            printf("%c", auxiliar[k]);
    }
    else
        printf("\tPilha vazia");
}