/*
 *	Autor: Guilherme Lima e Erico Sganzerla
 *	Data: 04.07.2013
 *
 */

#include<stdio.h>
#include "ListaCircular.h"

int main(int argc, char *argv[])
{
	ListaCircular lista1;
	inicializa(&lista1);

	adicionar(&lista1, 1);
	adicionar(&lista1, 2);
	adicionar(&lista1, 3);
	adicionar(&lista1, 4);
	adicionar(&lista1, 5);

	print(&lista1);
	printf("Numero de elementos na lista: %i\n\n\n", size(&lista1));

	printf("Removendo o numero 5...\n");
	remover(&lista1, 5);
	print(&lista1);
	printf("Numero de elementos na lista: %i\n\n\n", size(&lista1));
	
	ListaCircular lista2;
	inicializa(&lista2);	
	adicionar(&lista2, 5);
	adicionar(&lista2, 6);
	adicionar(&lista2, 7);
	adicionar(&lista2, 8);
	
	ListaCircular *lista3;
	printf("Concatenando lista 1 com lista 2.\n");
	printf("LISTA - 1\n");
	print(&lista1);
	printf("LISTA - 2\n");
	print(&lista2);
	lista3 = concat(&lista1, &lista2);
	printf("Lista concatenada.\n");
	print(lista3);
	printf("\n\n");
	
	ListaCircular *lista4;
	printf("Intercalando lista 1 com lista 2.\n");
	printf("LISTA - 1\n");
	print(&lista1);
	printf("LISTA - 2\n");
	print(&lista2);
	lista4 = intercalar(&lista1, &lista2);
	printf("Lista intercalada.\n");
	print(lista4);
	printf("\n\n");

	ListaCircular *lista5;
	printf("Fazendo uma copia da lista 2.\n");
	lista5 = copy(&lista2);
	printf("Lista original.\n");
	print(&lista2);
	printf("Lista copiada.\n");
	print(lista5);
	

	destroy(&lista1);
	destroy(&lista2);
	destroy(lista3);
	destroy(lista4);
	destroy(lista5);
}
