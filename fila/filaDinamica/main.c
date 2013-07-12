#include <stdio.h>
#include "filaDinamica.h"

int main(int argc, char *argv[])
{
	FilaDinamica fila;
	inicializa(&fila);
	
	if(empty(&fila))
		printf("Fila vazia...\n");

	printf("Incluindo elementos...\n");
	enfileira(&fila, 1);
	enfileira(&fila, 2);
	enfileira(&fila, 3);
	enfileira(&fila, 4);
	enfileira(&fila, 5);
	enfileira(&fila, 6);
	
	printf("Desenfileirando...\n");	
	printf("%d\n", desenfileira(&fila)); // retira 1
	printf("%d\n", desenfileira(&fila)); // retira 2
	printf("%d\n", desenfileira(&fila)); // retira 3
	printf("%d\n", desenfileira(&fila)); // retira 4
	printf("%d\n", desenfileira(&fila)); // retira 5
	printf("%d\n", desenfileira(&fila)); // retira 6
	
	enfileira(&fila, 10);
	
	destroy(&fila);

	return 0;
}
