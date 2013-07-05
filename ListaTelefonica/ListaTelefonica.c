/*
	Autores: Guilherme Lima e Erico Sganzerla
	Data: 29.06.2013
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

struct  endereco 
{   
	char nome[50];
	char email[40];
	char telefone[12];
	struct endereco *next;
}*inicio;

// inicializa a pilha.
void inicializa()
{inicio = NULL;}

//funcao para ler um texto
void leia(char *texto, char *v)
{
	printf("\n %s", texto);
	do
	{
		gets(v);
	} while ( (strlen(v) < 1) == TRUE);
}

int empty()
{
	if (inicio==NULL) 
		return TRUE;
	return FALSE;
}

void retire(void)
{
	char nome[80];
	struct endereco *andarilho, *anterior;
	int com;
	if (empty())
	{
		printf("\n**A agenda estah vazia!"); return;
	};
	leia("\n**Insira nome para retirada:",nome);
	andarilho=inicio;
	anterior = NULL;
	while(andarilho)
	{
		com = strcmp(andarilho->nome,nome);
		if (com != 0)
		{
			anterior=andarilho;
			andarilho=andarilho->next;
		}
		else 
		{
			if (andarilho == inicio)
			{
				inicio=andarilho->next;
				return;
			}
			andarilho = andarilho->next;
			anterior->next = andarilho;
			return;
		}
	}
}

struct endereco *find(char *nome)
{
	struct endereco *p;
	p=inicio;
	while(p)
	{
		if(strcmp(nome,p->nome)==0) 
			return p;
		else 
			p=p->next;
	}
	return NULL;
}

int insereOrdemAlfabetica(struct endereco *v)
{
	struct endereco *andarilho, *anterior;
	int com;
	if (empty())
	{
		v->next = NULL;
		inicio = v;
		return TRUE;
	}
	andarilho=inicio;
	anterior = NULL;
	while(andarilho)
	{
		com = strcmp(andarilho->nome,v->nome);
		if (com < 0)
		{
			anterior=andarilho; 
			andarilho=andarilho->next;
		}
		else 
		{
			v->next = andarilho;
			if (anterior)  
				anterior->next = v;
			else 
				inicio=v;
			return TRUE;
		}
	}
	// insere no final.
	anterior->next = v;
	v->next = NULL;
	return TRUE;
}

void entradaDeDados()
{
	struct endereco *novo = (struct endereco *) malloc(sizeof(struct endereco));

	if (!novo) 
	{
		printf("\n Sem memoria!"); 
		return;
	}
	leia("Nome:", novo->nome );
	leia("email:", novo->email );
	leia("Telefone:", novo->telefone );
	insereOrdemAlfabetica(novo);
}

void imprime()
{
	struct endereco *andarilho;
	andarilho=inicio;
	if (empty())
	{
		printf("**A agenda estah vazia!\n"); 
		return;
	}
	printf("**Conteudo da Agenda: \n");
	while (andarilho)
	{
		printf("Nome: %s\n",andarilho->nome);
		printf("Email: %s\n",andarilho->email);
		printf("Telefone: %s\n",andarilho->telefone);
		andarilho=andarilho->next;
	}
}

int salvar()
{
	FILE *fp;
	struct endereco *andarilho;
	andarilho=inicio;
	if ( (fp= fopen("agenda.txt","a+")) == NULL)
	{
		printf("\nERRO: Nao foi possivel escrever dados no arquivo");
		printf("'agenda.txt' !");
		return FALSE;
	}

	while (andarilho)
	{
		fprintf(fp,"\n\nNome: %s",andarilho->nome);
		fprintf(fp,"\nEmail: %s",andarilho->email);
		fprintf(fp,"\nTelefone: %s",andarilho->telefone);
		andarilho=andarilho->next;
	}
	fclose(fp);
	return TRUE;
}

int lerArquivo()
{
	FILE *fp;
	struct endereco *novo;
	inicializa();
	if ( (fp= fopen("agenda.txt","a+")) == NULL)
	{
		printf("\nERRO: Nao foi possivel abrir o arquivo");
		printf("'agenda.txt' !");
		return FALSE;
	}

	while (!feof(fp))
	{
		novo = (struct endereco *) malloc(sizeof(struct endereco));
		fscanf(fp,"\n\nNome: %s",novo->nome);
		fscanf(fp,"\nEmail: %s",novo->email);
		fscanf(fp,"\nTelefone: %s",novo->telefone);
		insereOrdemAlfabetica(novo);
	}
	fclose(fp);
	return TRUE;
}

// apresenta opcoes na tela do usuario.
int menu()
{
	int o=-1;
	printf("\n\n");
	for(int i = 0; i < 70; i++) printf("-");
	printf("\n\nExemplo de Lista:");
	printf("\n Agenda Telefonica");
	printf("\n Selecione a opcao:");
	printf("\n\t 1-Inserir um contato na agenda por ordem alfabetica.");
	printf("\n\t 2-Retirar um registro.");
	printf("\n\t 3-Listar a agenda completa.");
	printf("\n\t 4-Salvar.");
	printf("\n\t 5-Carregar agenda.");
	printf("\n\t 6-Procurar por nome.");
	printf("\n\t 7-Encerrar o programa.");

	printf("\n\t ? >"); scanf("%u",&o);
	return o;
}

void pause()
{
	fflush(stdin);
	printf("Aperte qualquer tecla para continuar...\n");
	getchar();
}

int main(void)
{
	int op = 0;
	inicializa();

	char nome[50];
	struct endereco *printName = (struct endereco *) malloc(sizeof(struct endereco));

	while(1)
	{
		op=menu();
		switch (op)
		{
			case 1:  entradaDeDados(); break;
			case 2:  retire(); break;
			case 3:  
				 imprime(); 
				 pause();
				 break;
			case 4:  
				 if (!salvar()) 
					 printf("\n*Erro!");
				 break;
			case 5:   
				 if (!lerArquivo()) 
					 printf("\n Erro de leitura !");
				 break;
			case 6:
				 printf("Digite o nome: ");
				 scanf("%s", nome);   
				 printName = find(nome);
				 if (printName != NULL)
				 {
					 printf("Nome: %s\n",printName->nome);
					 printf("Email: %s\n",printName->email);
					 printf("Telefone: %s\n",printName->telefone);
				 }
				 else
				 {
					 printf("Nao foi possivel localizar.\n");
				 }
				 pause();
				 break;
			case 7:
				 printf("\nFIM!");
				 exit(0);
		}
	}
	return 0;
}
