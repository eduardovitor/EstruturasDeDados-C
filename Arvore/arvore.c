#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

Arvore* criarArvore(int info, Arvore *esq, Arvore *dir){
    Arvore *nova=(Arvore*)malloc(sizeof(Arvore));
    nova->info=info;
    nova->esq=esq;
    nova->dir=dir;
    return nova;
}
Arvore* inserirArvoreEsquerda(Arvore *a, Arvore *nova){
    a->esq=nova;
    return a;
}
Arvore* inserirArvoreDireita(Arvore *a, Arvore *nova){
    a->dir=nova;
    return a;
}
void imprimirArvore(Arvore *a){
    if(a==NULL){
        return;
    }
    imprimirArvore(a->esq);
    imprimirArvore(a->dir);
    printf(" %d ",a->info);
}
int quantidadeFolhas(Arvore *a){
    if(a==NULL){
        return 0;
    }
    if(a->dir==NULL && a->esq==NULL){
        return 1;
    }
    return quantidadeFolhas(a->esq)+quantidadeFolhas(a->dir);
}
void elementosFolhas(Arvore *a){
    if(a==NULL){
        return;
    }
    if(a->dir==NULL && a->esq==NULL){
        printf("%d\n", a->info);
    }
    elementosFolhas(a->dir);
    elementosFolhas(a->esq);
}
int soma=0;
int somaElementosArvore(Arvore *a){
    if(a==NULL){
       return 0; 
    }
    somaElementosArvore(a->dir);
    somaElementosArvore(a->esq);
    soma=soma+a->info;
    return soma;
}