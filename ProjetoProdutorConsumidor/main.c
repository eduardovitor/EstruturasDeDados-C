#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> 
#define TAM_PILHA 10
#define QTD_THREAD 5
//definição de constantes para serem utilizadas
sem_t semaforo;
struct lista{
  int info;
  struct lista *prox;
};
typedef struct lista Lista;


struct pilha{
    Lista *topo;
};
typedef struct pilha Pilha;

//criação da pilha
Pilha* criarPilha(){
    Pilha *nova=(Pilha*)malloc(sizeof(Pilha));
    nova->topo = NULL;
    return nova;
}
//função pra inserir elementos na pilha
void push(Pilha *pilha, int info){
  Lista *novoelemento=(Lista*)malloc(sizeof(Lista));
  novoelemento->info=info;
  novoelemento->prox=pilha->topo;
  pilha->topo=novoelemento;
}
//função pra remover elementos da pilha
int pop(Pilha *pilha){
  if(pilha->topo==NULL){
    printf("Pilha vazia \n");
    return -1; //a função tem retorno, então deve retornar sem pre algo
  }
  else{
    Lista *aux;
    int valor_retirado;
    aux=pilha->topo;
    valor_retirado=pilha->topo->info;
    pilha->topo=pilha->topo->prox;
    free(aux);
    return valor_retirado;
  }
}
//função pra visualizar os valores da pilha
void visualizarPilha(Pilha *p){
    Lista *aux=p->topo;
    if(aux==NULL){
      printf("C: Pilha sem elementos! \n");
    }
    else{
      printf("P:");
      while(aux!=NULL){
        printf(" %d ",aux->info);
        aux=aux->prox;
      }
    }
}
//função produtor
void* fun_produtor(Pilha *p, int info){
    int i;
    sem_wait(&semaforo);
    for(i=0;i<TAM_PILHA;i++){
      push(p,info+i);
    }
    sem_post(&semaforo);
    visualizarPilha(p);
    return NULL; //por algum motivo o compilador pede pra retornar alguma coisa ¨¨\(o-o)/¨¨
}
//função consumidor
void *fun_consumidor(Pilha *p){
    int i;
    sem_wait(&semaforo);
    for(i=0;i<TAM_PILHA;i++){
      pop(p);
    }
    sem_post(&semaforo);
    visualizarPilha(p);
    return NULL; //por algum motivo o compilador pede pra retornar alguma coisa ¨¨\(oo)/¨¨
}

int main(void) {
  int i;
  Pilha *p=criarPilha();
  pthread_t prod[QTD_THREAD]; //definição das threads
  pthread_t cons[QTD_THREAD];
  sem_init(&semaforo, 0, 1);
  for(i=0; i<QTD_THREAD; i++){
      pthread_create(&prod[i], NULL, fun_produtor(p, i), NULL); //criação de threads
      pthread_create(&cons[i], NULL, fun_consumidor(p), NULL);
  }
  sem_destroy(&semaforo);
}