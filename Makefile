CFLAGS = -O2 -std=c99 -Wall -Wextra -pedantic
BINARIO = decimalABinario.c
main:
	clear
	"Seleccione un numero de ejercicio para ejecutar."

2.61: ejercicio-2.61.c
	gcc $(CFLAGS) $(BINARIO) ejercicio-2.61.c  -o 2.61

run-2.61: 2.61
	./2.61