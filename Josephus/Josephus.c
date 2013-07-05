/*
	Autores: Guilherme Lima e Erico Sganzerla
	Data: 27.06.2013


	Há um grupo de soldados circundado por uma força inimiga esmagadora. Não há esperanças de vitória sem a chegada de reforços, mas existe apenas um cavalo disponível para escapar. Os soldados entram num acordo para determinar qual deles deverá escapar e trazer ajuda. Eles formam um círculo e cada soldado recebe um número inteiro  n e um sentido de rotação z.  Um de seus nomes é sorteado também. 
Começando pelo soldado cujo nome foi sorteado, eles começam a contar ao longo do círculo no sentido da informação z armazenada pelo soldado. 
Quando a contagem alcança n, o soldado referenciado pela contagem é retirado. As informações n e z desse soldado serão utilizadas para a nova contagem. 
O processo continua de maneira que, toda vez que n é alcançado no sentido indicado por z, outro soldado sai do círculo. Os valores de n e z são modificados pelas informações armazenadas no soldado retirado. Todo soldado retirado do círculo não entra mais na contagem. O último soldado que restar deverá montar no cavalo e escapar. 
O problema é determinar a seqüência na qual os soldados são eliminados do círculo e o soldado que escapará.


*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Pessoa
{
	char nome[50];
	int numero;
	int direcao;
	struct Pessoa* pAnt;
	struct Pessoa* pProx;
} *inicio, *fim;

enum Direcao {horario=0, anti_horario=1};

void lerArquivo(char* s)
{
	FILE* fp = fopen(s, "r");

	if (fp == NULL) 
	{
		printf("Erro ao abrir o arquivo\n");
		return ;
	}

	while (!feof(fp))
	{
		struct Pessoa* p = (struct Pessoa*)malloc(sizeof(struct Pessoa));
		p->pAnt = NULL;
		p->pProx = NULL;

		fscanf(fp,"%i", &p->direcao);
		fgetc(fp);
		fscanf(fp, "%i", &p->numero);
		fgetc(fp);
		fscanf(fp, "%s", p->nome);

		if (inicio == NULL) // se nao tiver nenhum elemento na lista
		{
			inicio = p;
			fim = p;
		}
		else // se tiver elementos na lita
		{
			fim->pProx = p;
			p->pAnt = fim;
			fim = p;
		}
	}

	// amarra o fim da lista com o comeco
	fim->pProx = inicio;
	inicio->pAnt = fim;

	fclose(fp);
}

void mostraLista()
{
	struct Pessoa* p = inicio;
	do
	{
		printf("%i %i %s\n", p->direcao, p->numero, p->nome);
		p = p->pProx;
	} while (p!=inicio);
}

int size()
{
	int saida = 0;
	struct Pessoa* p = inicio;;

	do
	{
		saida++;
		p = p->pProx;
	} while (p!=inicio);

	return saida;
}

//exclui um elemento especifico da lista
void excluir(struct Pessoa* p)
{
	if (inicio == p)
		inicio = p->pProx;
	if (fim == p)
		fim = p->pProx;

	(p->pAnt)->pProx = p->pProx;
	(p->pProx)->pAnt = p->pAnt;
	free(p);
}

//limpa a lista inteira
void clear()
{
	struct Pessoa* p = inicio;
	fim = inicio->pAnt;

	while (inicio->pProx != fim)
	{
		p = inicio->pProx;
		excluir(inicio);
		inicio = p;
	}

	if (inicio == fim)
		free(inicio);
	else
	{
		free(inicio);
		free(fim);
	}
	inicio = fim = NULL;
}

struct Pessoa* anda(struct Pessoa* p, int n)
{
	struct Pessoa* aux = p;
	for (int i=0;i<n;i++)
	{
		switch (p->direcao)
		{
			case horario:
				aux = aux->pProx;
				break;
			case anti_horario:
				aux = aux->pAnt;
				break;
		}
	}
	return aux;
}

struct Pessoa* caminha(struct Pessoa* p)
{
	struct Pessoa* aux;
	aux = anda(p,p->numero);
	if (aux == p)
		aux = anda(p,1);
	return aux;
}

void executar(struct Pessoa* p)
{
	struct Pessoa* aux;
	while (size() != 1)
	{
		aux = caminha(p);
		printf("O soldado sorteado foi %s e o retirado foi %s\n", aux->nome, p->nome);
		excluir(p);
		p = aux;
	}

	printf("O soldado que ira utilizar o cavalo sera %s\n",aux->nome);
}
struct Pessoa* find(char* s)
{
	struct Pessoa* p = inicio;

	do
	{
		if (strcmp(p->nome,s) == 0)
			return p;
		else
			p = p->pProx;
	} while (p != inicio);

	return NULL;
}

int main()
{
	lerArquivo("teste.txt");
	mostraLista();

	char nome[50];
	printf("Digite o nome do soldado que ira comecar: ");
	scanf("%s",nome);

	struct Pessoa* p = find(nome);
	executar(p);

	clear();
	system("pause");
	return 0;
}
