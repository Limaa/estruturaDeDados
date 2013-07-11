/*
 *	Autor: Guilherme Lima e Erico Sganzerla
 *	Data: 04.07.2013
 *
 */

#include "ListaCircular.h"

void inicializa(ListaCircular *lista)
{
	lista->pPrim = NULL;
	lista->pAtual = NULL;
}
void destroy(ListaCircular *lista)
{
	if(size(lista)!= 0)
	{
		Elemento *paux = lista->pPrim->pProx;
		Elemento *pauxProx;
		while(paux != lista->pPrim)
		{
			pauxProx = paux->pProx;
			free(paux);
			paux = pauxProx;
		}
		free(lista->pPrim);
	}
}

int size(ListaCircular *lista)
{
	int cont = 1;
	Elemento* aux = NULL;

	if (lista->pPrim != NULL)
	{
		aux = lista->pPrim->pProx;
		while (aux != lista->pPrim)
		{
			cont++;
			aux = aux->pProx;
		}

		return cont;
	}
	else
	{
		return 0;
	}
}
void adicionar(ListaCircular *lista, int num)
{
	Elemento *pd = (Elemento *)malloc(sizeof(Elemento));
	pd->pProx = NULL;
	pd->pAnt = NULL;
	pd->info = num;

	if(lista->pPrim == NULL)
	{
		lista->pPrim = pd;
		lista->pPrim->pAnt = pd;
		lista->pPrim->pProx = pd;
		lista->pAtual = pd;
		lista->pAtual->pProx = pd;
		lista->pAtual->pAnt = pd;
	}
	else
	{
		lista->pAtual->pProx = pd;
		pd->pAnt = lista->pAtual;
		pd->pProx = lista->pPrim;
		lista->pAtual = pd;
		lista->pPrim->pAnt = pd;
	}
}
int remover(ListaCircular *lista, int num)
{
	if(size(lista)!= 0)
	{
		Elemento *paux = lista->pPrim;
		do
		{
			if(paux->info == num)
			{
				paux->pAnt->pProx = paux->pProx;
				paux->pProx->pAnt = paux->pAnt;
				free(paux);
				return num;
			}
			paux = paux->pProx;
		} while(paux != lista->pPrim);
	}
	return 0;
}
ListaCircular *concat(ListaCircular *lista1, ListaCircular *lista2)
{
	if(size(lista1) == 0)
		return copy(lista2);
	if(size(lista2) == 0)
		return copy(lista1);
	
	ListaCircular *pSaida = copy(lista1);
	ListaCircular *aux = copy(lista2);

	pSaida->pAtual->pProx = aux->pPrim;
	aux->pPrim->pAnt = pSaida->pAtual;
	aux->pAtual->pProx = pSaida->pPrim;
	pSaida->pPrim->pAnt = aux->pAtual;
	
	pSaida->pAtual = aux->pAtual;
	return pSaida;
}

ListaCircular *copy(ListaCircular *lista)
{
	ListaCircular *pSaida = (ListaCircular *)malloc(sizeof(ListaCircular));
	inicializa(pSaida);

	if(size(lista)!= 0)
	{
		Elemento *paux = lista->pPrim;
		do
		{
			adicionar(pSaida, paux->info);
			
			paux = paux->pProx;
		} while(paux != lista->pPrim);
	}
	
	return pSaida;
}

ListaCircular *intercalar(ListaCircular *lista1, ListaCircular *lista2)
{
	if(size(lista1) == 0)
		return copy(lista2);
	if(size(lista2) == 0)
		return copy(lista1);
	
	ListaCircular *lista = (ListaCircular *)malloc(sizeof(ListaCircular));
	inicializa(lista);
	
	int tam1 = size(lista1);
	int tam2 = size(lista2);
	int bigger = 0;
	if(tam1 > tam2)
		bigger = tam1;
	else
		bigger = tam2;

	Elemento *paux1 = lista1->pPrim;
	Elemento *paux2 = lista2->pPrim;
	
	int i = 0;
	for(i = 0; i < bigger; i++)
	{
		if(tam1 != 0)
		{
			adicionar(lista, paux1->info);
			paux1 = paux1->pProx;
			tam1--;
		}
		if(tam2 != 0)
		{
			adicionar(lista, paux2->info);
			paux2 = paux2->pProx;
			tam2--;
		}
	}
	return lista;
}

void print(ListaCircular *lista)
{
	if(size(lista) != 0)
	{
		printf("Inicio da listaCircular......\n");
		Elemento *paux = lista->pPrim;
		do
		{
			printf("%d\n", paux->info);
			paux = paux->pProx;
		} while(paux != lista->pPrim);
		printf("Fim da listaCircular......\n");
	}
	else
		printf("listaCircular vazia.\n");
}
