#include "filaDinamica.h"

void inicializa(FilaDinamica *pf)
{
	pf->pPrim = NULL;
	pf->pFim = NULL;
	pf->n = 0;
}

int size(FilaDinamica *pf)
{
	return pf->n;
}

int empty(FilaDinamica *pf)
{
	if(pf->n == 0)
		return 1;
	return 0;
}

void enfileira(FilaDinamica *pf, int x)
{
	struct elementoFila *pNovo = (struct elementoFila *)malloc(sizeof(struct elementoFila));
	if(pNovo == NULL)
	{
		printf("Sem memoria suficiente...Saindo do programa.\n");
		exit(-1);
	}
	pNovo->info = x;
	pNovo->pProx = NULL;

	if(pf->n == 0)
	{
		pf->pPrim = pNovo;
		pf->pFim = pNovo;
	}
	else
	{
		pf->pFim->pProx = pNovo;
		pf->pFim = pNovo;
	}
	pf->n++;
}

int desenfileira(FilaDinamica *pf)
{
	int saida = -1;
	if(pf->n != 0)
	{
		struct elementoFila *aux = pf->pPrim->pProx;
		saida = pf->pPrim->info;
		free(pf->pPrim);
		pf->pPrim = aux;
		pf->n--;
	}
	return saida;
}
void destroy(FilaDinamica *pf)
{
	if(pf->n != 0)
	{
		struct elementoFila *aux = pf->pPrim;
		while(aux != NULL)
		{
			aux = aux->pProx;
			free(pf->pPrim);
			pf->pPrim = aux;
			pf->n--;
		}
	}
}
