
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 10
struct listanomes{
    char nome[50];
};
typedef struct listanomes ListaNomes;

void BubbleSort(ListaNomes lista[]){
        int qtdtrocas=0;
        char aux[50];
        int i=0;
        int i2=0;
        for(i=1;i<TAM*10;i++){
          for(i2=0;i2<TAM-1;i2++){
              if(strcmp(lista[i2].nome,lista[i2+1].nome)>0){
                  strcpy(aux,lista[i2].nome);
                  strcpy(lista[i2].nome,lista[i2+1].nome);
                  strcpy(lista[i2+1].nome,aux);
                  qtdtrocas++;
              }
          }
        }
        printf("%d trocas foram realizadas \n",qtdtrocas);
}
int separar(ListaNomes lista[],int esq, int dir ){
    int qtdtrocas=0;
    int i=esq+1;
    int j=dir;
    char pivo[50];
    strcpy(pivo,lista[esq].nome);
    while(i<=j){
        if(strcmp(lista[i].nome,pivo)<=0){
            i++;
        }
        else if(strcmp(lista[j].nome,pivo)>0){
            j--;
        }
        else if(i<=j){
            char aux[50];
            strcpy(aux,lista[i].nome);
            strcpy(lista[i].nome,lista[j].nome);
            strcpy(lista[j].nome,aux);
            i++;
            j--;
            qtdtrocas++;
        }
    }
    char aux[50];
    strcpy(aux,lista[esq].nome);
    strcpy(lista[esq].nome,lista[j].nome);
    strcpy(lista[j].nome,aux);
    qtdtrocas++;
    printf(" %d \n", qtdtrocas);
    return j;
}
void quickSort(ListaNomes lista[], int esq, int dir){
    if(esq<dir){
        int j=separar(lista, esq, dir);
        quickSort(lista,esq,j-1);
        quickSort(lista,j+1,dir);
    }
}
void OrdenarVetor(ListaNomes lista[], int metodo){
    if(metodo==1){ //BubbleSort
        BubbleSort(lista);
    }   
    else if(metodo==2){
        quickSort(lista,0,TAM-1);
    }
}
int PesquisarVetor(ListaNomes lista[], int modo, char nome[]){
    if(modo==1){
        int i=0; //Pesquisa Sequencial
        int num_comp=0;
        for(i=0;i<TAM;i++){
            if(strcmp(lista[i].nome, nome)==0){
                num_comp++;
                printf("%d comparacoes foram realizadas \n",num_comp);
                return 1;
            }
            num_comp++;
        }
    }
    else if(modo==2){
      int i; //Pesquisa Binária
      int num_comp=1;
      int metade=TAM/2;
      int retorno=strcmp(nome,lista[metade-1].nome);
      if(retorno==0){
          printf("%d comparacoes foram realizadas \n",num_comp);
          return 1;
      }
      else if(retorno<0){
          int i;
          for(i=0;i<metade-2;i++){
            if(strcmp(nome,lista[i].nome)==0){
                num_comp++;
                printf("%d comparacoes foram realizadas \n",num_comp);
                return 1;
            }
            num_comp++;
          }
      }
      else if(retorno>0){
          int i;
          for(i=metade;i<TAM;i++){
              if(strcmp(nome,lista[i].nome)==0){
                  num_comp++;
                  printf("%d comparacoes foram realizadas \n",num_comp);
                  return 1;
              }
              num_comp++;
          }
      }
    }
}
void ImprimirVetor(ListaNomes lista[]){
    int i=0;
    while(i<TAM){
        printf("%s \n",lista[i].nome);
        i++;
    }
}
void lerNomes(ListaNomes lista[]){
    int i;
    for(i=0;i<TAM;i++){
       printf("Digite o nome(%d): \n ",i+1);
       scanf("%s",lista[i].nome);
    }
}
int main(int argc, char** argv) {
    ListaNomes nomes[10]={"Zuleide","Pedro","Ronaldo","Lionel","Cassandra","Mane","Salah","Yolanda","Wagner","Vitor"};
  //  lerNomes(nomes);
    OrdenarVetor(nomes,2);
    PesquisarVetor(nomes,2,"Salah");
    ImprimirVetor(nomes);
}

