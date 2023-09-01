struct arvore{
    int info;
    struct arvore *esq;
    struct arvore *dir;
};
typedef struct arvore Arvore;


Arvore* criarArvore(int info, Arvore *esq, Arvore *dir);
Arvore* inserirArvoreDireita(Arvore *a, Arvore *nova);
Arvore* inserirArvoreEsquerda(Arvore *a, Arvore *nova);
void imprimirArvore(Arvore *a);
int quantidadeFolhas(Arvore *a);
void elementosFolhas(Arvore *a);
int somaElementosArvore(Arvore *a);