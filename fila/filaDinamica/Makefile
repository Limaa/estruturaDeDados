all: clean fila
CFLAGS=-Wall -g -std=c99
clean:
	rm -f main
fila: main.c filaDinamica.c
	gcc -o main main.c filaDinamica.c -I.
