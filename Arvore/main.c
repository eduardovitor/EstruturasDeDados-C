
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {
    Arvore *a=criarArvore(3,NULL,NULL);
    Arvore *a2=criarArvore(6,a,NULL);
    Arvore *a3=criarArvore(5,a2,NULL);
    Arvore *a4=criarArvore(10,NULL,NULL);
    a3=inserirArvoreDireita(a3,a4);
    imprimirArvore(a3);
    printf("\n");
    elementosFolhas(a3);
}

