all: clean fila
CFLAGS=-Wall -g -std=c99
clean:
	rm -f main
fila: main.c filaEstatica.c
	gcc -o main main.c filaEstatica.c -I.
