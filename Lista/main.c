#include <stdio.h>
#include "Lista.h"

void imprimeLista(Lista *l)
{
	printf("COMECO da lista\n");
	struct elementoLista *aux = l->inicio;
	while(aux != NULL)
	{
		printf("%d\n", aux->info);
		aux = aux->next;
	}
	printf("FIM da lista\n");
}

int main(int argc, char *argv[])
{
	Lista l;
	iniciaLista(&l);
	
	// empty(), size()
	if(emptyLista(&l) == 1)
		printf("Lista vazia, como esperado\n");
	else
		printf("Lista nao esta vazia, ERRO\n");
	printf("Tamanho esperado: 0\n");
	printf("Tamanho size(): %d\n", sizeLista(&l));
	imprimeLista(&l);
	printf("\n");

	// pushBack(), empty(), size()
	pushBackLista(&l, 1);
	if(emptyLista(&l) == 1)
		printf("Lista vazia, ERRO\n");
	else
		printf("Lista nao esta vazia, como esperado\n");
	printf("Tamanho esperado: 1\n");
	printf("Tamanho size(): %d\n", sizeLista(&l));
	imprimeLista(&l);
	printf("\n");
	
	// popBack(), empty(), size()
	int i = popBackLista(&l);
	printf("Valor retirado: %d\n", i);
	if(emptyLista(&l) == 1)
		printf("Lista vazia, como esperado\n");
	else
		printf("Lista nao esta vazia, ERRO\n");
	printf("Tamanho esperado: 0\n");
	printf("Tamanho size(): %d\n", sizeLista(&l));
	imprimeLista(&l);
	printf("\n");

	// pushFront(), empty(), size()
	pushFrontLista(&l, 1);
	if(emptyLista(&l) == 1)
		printf("Lista vazia, ERRO\n");
	else
		printf("Lista nao esta vazia, como esperado\n");
	printf("Tamanho esperado: 1\n");
	printf("Tamanho size(): %d\n", sizeLista(&l));
	imprimeLista(&l);
	printf("\n");
	
	// popFront(), empty(), size()
	i = popFrontLista(&l);
	printf("Valor retirado: %d\n", i);
	if(emptyLista(&l) == 1)
		printf("Lista vazia, como esperado\n");
	else
		printf("Lista nao esta vazia, ERRO\n");
	printf("Tamanho esperado: 0\n");
	printf("Tamanho size(): %d\n", sizeLista(&l));
	imprimeLista(&l);
	printf("\n");


	destroyLista(&l);
	printf("Tamanho esperado: 0\n");
	printf("Tamanho size(): %d\n\n", sizeLista(&l));
	return 0;
}
