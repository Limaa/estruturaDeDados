#include <stdio.h>
#include "Pilha.h"

void imprimePilha(Pilha *p)
{
	printf("INICIO da pilha.\n");
	struct elementoPilha *aux = p->inicio;
	while(aux != NULL)
	{
		printf("%d\n", aux->info);
		aux = aux->next;
	}
	printf("FIM da pilha.\n");
}

int main(int argc, char *argv[])
{
	Pilha p;
	iniciaPilha(&p);

	if(emptyPilha(&p) == 1)
		printf("Pilha vazia, como esperado.\n");
	else
		printf("Pilha nao vazia, ERRO.\n");
	printf("Tamanho esperado: 0\n");
	printf("Tamanho size(): %d\n", sizePilha(&p));
	imprimePilha(&p);
	printf("\n");

	empilha(&p, 1);
	if(emptyPilha(&p) == 1)
		printf("Pilha vazia, ERRO.\n");
	else
		printf("Pilha nao vazia, como esperado.\n");
	printf("Tamanho esperado: 1\n");
	printf("Tamanho size(): %d\n", sizePilha(&p));
	imprimePilha(&p);
	printf("\n");
	
	int i = desempilha(&p);
	printf("Numero retirado: %d\n", i);
	if(emptyPilha(&p) == 1)
		printf("Pilha vazia, como esperado.\n");
	else
		printf("Pilha nao vazia, ERRO.\n");
	printf("Tamanho esperado: 0\n");
	printf("Tamanho size(): %d\n", sizePilha(&p));
	imprimePilha(&p);
	printf("\n");

	destroyPilha(&p);
	return 0;
}
