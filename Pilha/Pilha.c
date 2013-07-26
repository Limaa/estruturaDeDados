#include "Pilha.h"

void iniciaPilha(struct pilha *p)
{
	p->n = 0;
	p->inicio = NULL;
}
void destroyPilha(struct pilha *p)
{
	if(p->n != 0)
	{
		struct elementoPilha *aux = p->inicio;
		while(aux != NULL)
		{
			struct elementoPilha *auxProx = aux->next;
			free(aux);
			aux = auxProx;
		}

		p->n = 0;
		p->inicio = NULL;
	}
}

int sizePilha(struct pilha *p)
{
	return p->n;
}
int emptyPilha(struct pilha *p)
{
	if (p->n == 0)
		return 1;
	return 0;
}

void empilha(struct pilha *p, int c)
{
	struct elementoPilha *pNovo = (struct elementoPilha *)malloc(sizeof(struct elementoPilha));
	if (pNovo == NULL)
	{
		printf("Nao foi possivel alocar memoria para a informacao (%c).\n",c);
		exit(-1);
	}

	pNovo->info = c;
	pNovo->next = p->inicio;

	p->inicio = pNovo;
	p->n++;
}
int desempilha(struct pilha *p)
{
	if (p->n != 0)
	{
		int saida;
		struct elementoPilha *paux = p->inicio;

		saida = paux->info;
		p->inicio = paux->next;
		p->n--;

		free(paux);

		return saida;
	}
	return '\0';
}
