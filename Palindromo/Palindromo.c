/*
	Autores: Guilherme Lima e Erico Sganzerla
	Data: 01.07.2013
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Elemento
{
	char info;
	struct Elemento *pAnterior;
};

struct PilhaChar
{
	int quantidade;
	struct Elemento *pTopo;
};


void inicia( struct PilhaChar *pilha )
{
	pilha->quantidade = 0;
	pilha->pTopo = NULL;
}

int size( struct PilhaChar *pilha )
{
	return pilha->quantidade;
}

int empty( struct PilhaChar *pilha )
{
	if ( pilha->quantidade == 0)
		return 1;
	return 0;
}

void empilha( struct PilhaChar *pilha, char c)
{
	struct Elemento *pNovo = (struct Elemento *)malloc(sizeof(struct Elemento));
	if ( pNovo == NULL)
	{
		printf("Nao foi possivel alocar memoria para a informacao (%c).\n",c);
		exit(-1);
	}

	pNovo->info = c;
	pNovo->pAnterior = pilha->pTopo;

	pilha->pTopo = pNovo;
	pilha->quantidade++;
}

char desempilha( struct PilhaChar *pilha )
{
	if (!empty(pilha))
	{
		char saida;
		struct Elemento *paux = pilha->pTopo;

		saida = paux->info;
		pilha->pTopo = paux->pAnterior;
		pilha->quantidade--;

		free( paux );

		return saida;
	}
	return '\0';
}

int main()
{
	struct PilhaChar pilha;
	inicia(&pilha);
	
	char buffer[MAX_SIZE] = {0};
	char bufferAux[MAX_SIZE] = {0};

	printf("Digite a palavra: ");
	scanf("%s", buffer);

	int i = 0;
	for(i = 0; buffer[i] != '\0'; i++)
		empilha(&pilha, buffer[i]);
	for(i = 0; size(&pilha) != 0; i++)
		bufferAux[i] = desempilha(&pilha);

	if (strcmp(bufferAux, buffer) == 0)
		printf("E palindromo.\n");
	else
		printf("Nao e palindromo.\n");

	fflush(stdin);
	printf("Digite qualquer tecla para sair...\n");
	getchar();
	return 0;
}
