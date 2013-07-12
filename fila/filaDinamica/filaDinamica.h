#include<stdlib.h>
#include<stdio.h>

struct elementoFila
{
	int info;
	struct elementoFila *pProx;
};

struct filaDinamica
{
	struct elementoFila *pPrim;
	struct elementoFila *pFim;
	int n;
};

typedef struct elementoFila elemento;
typedef struct filaDinamica FilaDinamica;

void inicializa(FilaDinamica *pf);
int size(FilaDinamica *pf);
int empty(FilaDinamica *pf);
void enfileira(FilaDinamica *pf, int x);
int desenfileira(FilaDinamica *pf);
void destroy(FilaDinamica *pf);
