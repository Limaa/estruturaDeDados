#include "Lista.h"

void iniciaLista(struct lista *l)
{
	l->n = 0;
	l->inicio = NULL;
	l->fim = NULL;
}
void destroyLista(struct lista *l)
{
	if(l->n != 0)
	{
		struct elementoLista *aux = l->inicio;
		while(aux != NULL)
		{
			struct elementoLista *auxProx = aux->next;
			free(aux);
			aux = auxProx;
		}
		l->n = 0;
		l->inicio = NULL;
		l->fim = NULL;
	}
}

int sizeLista(struct lista *l)
{
	return l->n;
}
int emptyLista(struct lista *l)
{
	if(l->n == 0)
		return 1;
	return 0;
}

void pushBackLista(struct lista *l, int c)
{
	struct elementoLista *pNovo = (struct elementoLista *)malloc(sizeof(struct elementoLista));
	pNovo->info = c;
	pNovo->next = NULL;
	pNovo->prev = NULL;

	if(l->n == 0)
	{
		l->inicio = pNovo;
		l->fim = pNovo;
	}
	else
	{
		l->fim->next = pNovo;
		pNovo->prev = l->fim;
		l->fim = pNovo;
	}
	l->n++;
}
void pushFrontLista(struct lista *l, int c)
{
	struct elementoLista *pNovo = (struct elementoLista *)malloc(sizeof(struct elementoLista));
	pNovo->info = c;
	pNovo->next = NULL;

	if(l->n == 0)
	{
		l->inicio = pNovo;
		l->fim = pNovo;
	}
	else
	{
		pNovo->next = l->inicio;
		l->inicio->prev = pNovo;
		l->inicio = pNovo;
	}
	l->n++;
}

int popBackLista(struct lista *l)
{
	int saida = 0;

	if (l->n != 0)
	{
		saida = l->fim->info;	
		struct elementoLista *aux = l->fim;
		l->fim = l->fim->prev;
		if(l->fim != NULL)
			l->fim->next = NULL;
		else
			l->inicio = NULL;
		free(aux);
		l->n--;
	}	
	return saida;
}
int popFrontLista(struct lista *l)
{
	int saida = 0;

	if (l->n != 0)
	{
		saida = l->inicio->info;	
		struct elementoLista *aux = l->inicio;
		l->inicio = l->inicio->next;
		if(l->inicio != NULL)
			l->inicio->prev = NULL;
		else
			l->fim = NULL;
		free(aux);
		l->n--;
	}	
	return saida;
}
