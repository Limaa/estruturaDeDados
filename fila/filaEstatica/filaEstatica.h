#define TAM 5
struct filaEstatica
{
	int ini;
	int fim;
	int n;
	int v[TAM];
};
typedef struct filaEstatica FilaEstatica;

void inicializa(FilaEstatica *pf);
int size(FilaEstatica *pf);
int empty(FilaEstatica *pf);
void enfileira(FilaEstatica *pf, int n);
int desenfileira(FilaEstatica *pf);
