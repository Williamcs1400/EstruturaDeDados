#include <stdio.h>

struct rac
{
    int numerador;
    int denominador;
};

typedef struct rac Racional;

Racional Adicao(Racional var1, Racional var2);

Racional Multiplicacao(Racional var1, Racional var2);

void Imprimir(Racional result, int op);
