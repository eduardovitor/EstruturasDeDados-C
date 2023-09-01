
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {
    Arvore *a=NULL;
    int r=0;
    a=criarArvore("João",a);
    a=criarArvore("Cleiton",a);
    a=criarArvore("Ana",a);
    a=criarArvore("Zuleide",a);
    a=criarArvore("Daniel",a);
    a=criarArvore("Vitor",a);
    a=criarArvore("Mateus",a);
    a=removerNomeArvore("Cleiton",a);
    imprimirArvoreAlfabetica(a);
}

