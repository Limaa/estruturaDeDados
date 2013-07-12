#include "filaEstatica.h"

void inicializa(FilaEstatica *pf)
{
	pf->ini = 0;
	pf->fim = 0;
	pf->n = 0;
}
int size(FilaEstatica *pf)
{
	return pf->n;
}
int empty(FilaEstatica *pf)
{
	if(pf->n == 0)
		return 1;
	return 0;
}
void enfileira(FilaEstatica *pf, int n)
{
	if(pf->n != TAM)
	{
		if(pf->fim == TAM)
			pf->fim = 0;
		pf->v[pf->fim] = n;
		pf->fim++;
		pf->n++;
	}
}
int desenfileira(FilaEstatica *pf)
{
	int saida = 0;
	if(pf->n != 0)
	{
		if(pf->ini == TAM)
			pf->ini = 0;
		saida = pf->v[pf->ini];
		pf->ini++;
		pf->n--;
	}
	return saida;
}
