/*
 *	Autor: Guilherme Lima e Erico Sganzerla
 *	Data: 04.07.2013
 *
 */

#include<stdlib.h>
#include<stdio.h>

struct elemento
{
	int info;
	struct elemento *pAnt;
	struct elemento *pProx;
};

struct listaCircular
{
	struct elemento *pPrim;
	struct elemento *pAtual;
};

typedef struct elemento Elemento;
typedef struct listaCircular ListaCircular;

void inicializa(ListaCircular *lista);
void destroy(ListaCircular *lista);

int size(ListaCircular *lista);
void adicionar(ListaCircular *lista, int num);
int remover(ListaCircular *lista, int num);
ListaCircular *concat(ListaCircular *lista1, ListaCircular *lista2);
ListaCircular *copy(ListaCircular *lista);
ListaCircular *intercalar(ListaCircular *lista1, ListaCircular *lista2);

void print(ListaCircular *lista);
