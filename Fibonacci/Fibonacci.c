/*
	Autores: Guilherme Lima e Erico Sganzerla
	Data: 02.07.2013
	
	Codigo base: Tânia Preto e Bruno Chang
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

struct  Fibonacci
{
long int numero;
struct Fibonacci *next;
struct Fibonacci *prev;
}  *lista;

// inicializa a pilha
void inicializaSerie()
{
	struct Fibonacci *elemento[2];
	elemento[0]= (struct Fibonacci *) malloc(sizeof(struct Fibonacci));
	elemento[0]->numero=1;
	elemento[1]= (struct Fibonacci *) malloc(sizeof(struct Fibonacci));
	elemento[1]->numero=1;
	elemento[0]->next = elemento[1];
	elemento[0]->prev = NULL;
	elemento[1]->prev = elemento[0];
	elemento[1]->next = NULL;
	lista=elemento[1];
}

void geraSerie(int n)
{
	struct Fibonacci *novo;
	long int n1=0; long int n2=0;
	for (int i=3; i <= n; i++)
	{
		novo= (struct Fibonacci *) malloc(sizeof(struct Fibonacci));
		n1 = lista->numero;
		lista=lista->prev;
		n2 =lista->numero;
		lista=lista->next;
		novo->numero = (n1+n2);
		novo->prev=lista;
		novo->next=NULL;
		lista->next=novo;
		lista=novo;
	}
}

void imprime()
{
	while(lista->prev){lista=lista->prev;}
	printf("\n Serie de Fibonacci: %ld ", lista->numero);
	while(lista->next)
	{ lista=lista->next;
	printf(" %ld ", lista->numero);
	}
}

void imprimeInvertida()
{
	printf("\n Serie de Fibonacci: %ld ", lista->numero);
	while(lista->prev){lista=lista->prev;
	printf(" %ld ", lista->numero);}
	while(lista->next) {lista=lista->next;}
}

int menu()
{
	int o=-1;
	printf("\n\n");
	for(int i = 0; i < 70; i++) printf("-");
	printf("\n\nExemplo de Lista Duplamente Encadeada:");
	printf("\n Selecione a opcao:");
	printf("\n\t 1-Inicializar a Serie");
		printf("\n\t 2-Gerar a Serie com n elementos");
		printf("\n\t 3-Ultimo Elemento");
		printf("\n\t 4-Imprime a Serie invertida");
		printf("\n\t 5-Imprime a Serie");
		printf("\n\t 6-Limpar a Tela");
		printf("\n\t 7-Excluir um elemento");
		printf("\n\t 8-Encerrar o programa");
		printf("\n\t ? >"); scanf("%u",&o);
	return o;
}

void imprimeUltimo()
{
	printf("\nUltimo Elemento : %ld",lista->numero);
}

void excluiNumero(int numero)
{
	struct Fibonacci* aux1;
	struct Fibonacci* aux2;
	struct Fibonacci* aux3;

	aux1 = lista;
	
	while (aux1 != NULL)
	{
		aux2 = aux1->prev;
		aux3 = aux1->next;

		if (numero == aux1->numero)
		{
			free(aux1);
			if (aux3 != NULL) aux3->prev = aux2;
			if (aux2 != NULL) aux2->next = aux3;
		}
		aux1 = aux2;
	}
}

void excluirElementoFunc()
{
	printf("Digite o numero a ser excluido: ");
	int n;
	scanf("%i", &n);
	excluiNumero(n);
}

int main(void)
{
	int op = 0;
	int k=2;

	inicializaSerie();

	for(;;)
	{
		op=menu();
		switch (op)
		{
		case 1:   inicializaSerie();
			break;
		case 2:   printf("\n Quantidade de elementos? >");
			scanf("%i",&k);
			inicializaSerie();
			geraSerie(k); break;
		case 3:   imprimeUltimo();  break;
		case 4:   imprimeInvertida(); break;
		case 5:   imprime(); break;
		case 6:   system("cls"); break; 
		case 7:   excluirElementoFunc(); break; 
		case 8:   printf("\nFIM!");exit(0);
		}
	}
	return 0;
}
