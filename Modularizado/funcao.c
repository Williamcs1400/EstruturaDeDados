#include "headers.h"

Racional Adicao(Racional var1, Racional var2){
    Racional resultado;

    resultado.numerador = (var1.numerador * var2.denominador) + (var2.numerador * var1.denominador);
    resultado.denominador = var1.denominador * var2.denominador;

    return resultado;
}

Racional Multiplicacao(Racional var1, Racional var2){
    Racional resultado;

    resultado.numerador = var1.numerador * var2.numerador;
    resultado.denominador = var1.denominador * var2.denominador;
    
    return resultado;
}

void Imprimir(Racional result, int op){
    if(op == 0){
        printf("A adicao: %d/%d\n", result.numerador, result.denominador);
    }
    if(op == 1){
        printf("A multiplicacao: %d/%d\n", result.numerador, result.denominador);
    }
}
