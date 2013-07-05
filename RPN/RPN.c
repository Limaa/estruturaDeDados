/*
	Autores: Guilherme Lima e Erico Sganzerla
	Data: 04.07.2013
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Elemento
{
	int info;
	struct Elemento *pAnterior;
};

struct PilhaInt
{
	int quantidade;
	struct Elemento *pTopo;
};


void inicia( struct PilhaInt *pilha )
{
	pilha->quantidade = 0;
	pilha->pTopo = NULL;
}

int size( struct PilhaInt *pilha )
{
	return pilha->quantidade;
}

int empty( struct PilhaInt *pilha )
{
	if ( pilha->quantidade == 0)
		return 1;
	return 0;
}

void empilha( struct PilhaInt *pilha, int c)
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

int desempilha( struct PilhaInt *pilha )
{
	if (!empty(pilha))
	{
		int saida;
		struct Elemento *paux = pilha->pTopo;

		saida = paux->info;
		pilha->pTopo = paux->pAnterior;
		pilha->quantidade--;

		free( paux );

		return saida;
	}
	return '\0';
}

void destroy( struct PilhaInt *pilha)
{
	while (!empty(pilha))
	{
		desempilha(pilha);
	}
}
int main()
{
	struct PilhaInt pilha;
	inicia(&pilha);
	
	char equation[MAX_SIZE] = {0};
	char buff[MAX_SIZE] = {0};

	printf("Digite a equacao: ");
	int a = 0;
	do
	{
		equation[a] = getchar();
		a++;
	}while (equation[a-1] != '\n');

	int i = 0;
	int k = 0;
	for(i = 0; equation[i] != '\0'; i++)
	{
		if ('0' <= equation[i] && equation[i] <= '9') 
		{
			buff[k] = equation[i];
			k++;
		}
		else if (equation[i] == ' ' && k != 0) 
		{
			int num1 = atoi(buff);
			empilha(&pilha, num1);
			int j;
			for (j = 0; j < k; j++)
			{
				buff[j] = 0;
			}
			k = 0;
		}
		else if (equation[i] == '*') 
		{
			int num1 = desempilha(&pilha);
			int num2 = desempilha(&pilha);
			empilha(&pilha, num1 * num2);
		}
		else if (equation[i] == '/') 
		{
			int num1 = desempilha(&pilha);
			int num2 = desempilha(&pilha);
			if (num1 == 0) 
			{
				printf("**Nao e possivel dividir por zero...\n");
				exit(0);
			}
			empilha(&pilha, num2 / num1);
		}
		else if (equation[i] == '-') 
		{
			int num1 = desempilha(&pilha);
			int num2 = desempilha(&pilha);
			empilha(&pilha,num2 - num1);
		} 
		else if (equation[i] == '+') 
		{
			int num1 = desempilha(&pilha);
			int num2 = desempilha(&pilha);
			empilha(&pilha, num1 + num2);
		}
		else if (equation[i] == '\n') 
		{
			int num1 = desempilha(&pilha);
			printf("%d \n", num1);
		}
		else if (equation[i] != ' ')
		{
			printf("%c\n", equation[i]);
			printf("**Erro...\n");
			exit(1);
		}
	}

	destroy(&pilha);

	fflush(stdin);
	printf("Digite qualquer tecla para sair...\n");
	getchar();
	return 0;
}
