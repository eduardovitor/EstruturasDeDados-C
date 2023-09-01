#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include <string.h>

Arvore* criarArvore(char nome[], Arvore *a){
    if(a==NULL){
       Arvore *nova=(Arvore*)malloc(sizeof(Arvore));
       strcpy(nova->nome,nome);
       nova->dir=NULL;
       nova->esq=NULL;
       return nova;
    }
    else{
      if(strcmp(nome,a->nome)>0){
          a->dir=criarArvore(nome,a->dir);
      }
      else{
          a->esq=criarArvore(nome,a->esq);
      }
      return a;
    }
}
int procurarNomeArvore(char nome[], Arvore *a){
     if(a==NULL){
        return 0;
     }
     if(strcmp(nome,a->nome)==0){
        return 1;
     }
     else if(strcmp(nome,a->nome)<0){
         procurarNomeArvore(nome,a->dir);
         procurarNomeArvore(nome,a->esq);
     }
     else if(strcmp(nome, a->nome)>0){
         procurarNomeArvore(nome,a->esq);
         procurarNomeArvore(nome,a->dir);
     }
}
Arvore* removerNomeArvore(char nome[], Arvore *a){
    if(a==NULL){
        return NULL;
    }
    else{
        if(strcmp(nome,a->nome)>0){
            a->dir=removerNomeArvore(a->nome,a->dir);
        }
        else if(strcmp(nome,a->nome)<0){
            a->esq=removerNomeArvore(a->nome,a->esq);
        }
        else{
            if(a->esq==NULL && a->dir==NULL){ //caso que não tem filhos
                Arvore *aux=a;
                free(aux);
                aux=NULL;
            }
            else if(a->esq==NULL && a->dir!=NULL){
                Arvore *aux=a; //um filho
                a=a->dir;
                free(aux);
            }
            else if(a->esq!=NULL && a->dir==NULL){
                Arvore *aux=a; //um filho
                a=a->esq;
                free(aux);
            }
            else{
              Arvore *aux = a->esq;
                while(aux->dir != NULL){
                    aux=aux->dir;
                }
                strcpy(a->nome,aux->nome);
                strcpy(aux->nome,nome);
                a->esq =removerNomeArvore(nome,a->esq);  //dois filhos
            }
       }
    }
}
void imprimirArvoreAlfabetica(Arvore *a){
    if(a==NULL){
        return;
    }
    imprimirArvoreAlfabetica(a->esq);
    printf("%s \n",a->nome);
    imprimirArvoreAlfabetica(a->dir);
}
int cont=1;
void qtdPessoasDepoisNomeArvore(char nome[], Arvore *a){
     if(a==NULL){
         return;
     }
     if(strcmp(a->nome,nome)>0){
         printf("%s(%d) \n",a->nome,cont);
         cont++;
     }
    qtdPessoasDepoisNomeArvore(nome,a->dir);
    qtdPessoasDepoisNomeArvore(nome,a->esq);
}