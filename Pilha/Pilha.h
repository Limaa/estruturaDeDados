#include <stdlib.h>
#include <stdio.h>

struct elementoPilha
{
	int info;
	struct elementoPilha *next;
};

struct pilha
{
	int n; // numero de elementos na pilha
	struct elementoPilha *inicio;
};

typedef struct pilha Pilha;

void iniciaPilha(struct pilha *p);
void destroyPilha(struct pilha *p);

int sizePilha(struct pilha *p);
int emptyPilha(struct pilha *p);

void empilha(struct pilha *p, int c);
int desempilha(struct pilha *p);

