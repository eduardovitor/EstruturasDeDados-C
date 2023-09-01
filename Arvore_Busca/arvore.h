struct arvore{
    char nome[50];
    struct arvore *dir;
    struct arvore *esq;
};
typedef struct arvore Arvore;


Arvore* criarArvore(char nome[], Arvore *a);
int procurarNomeArvore(char nome[], Arvore *a);
Arvore* removerNomeArvore(char nome[], Arvore *a);
void imprimirArvoreAlfabetica(Arvore *a);
void qtdPessoasDepoisNomeArvore(char nome[], Arvore *a);
