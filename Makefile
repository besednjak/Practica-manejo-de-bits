CFLAGS = -O2 -std=c99 -Wall -Wextra -pedantic
BINARIO = decimalABinario/decimalABinario.c
main:
	clear
	echo "Seleccione un numero de ejercicio para ejecutar."

2.61: ejercicio-2.61.c
	gcc $(CFLAGS) $(BINARIO) ejercicio-2.61.c  -o 2.61

run-2.61: 2.61
	./2.61

2.60: ejercicio-2.60.c
	gcc $(CFLAGS) $(BINARIO) ejercicio-2.60.c  -o 2.60

run-2.60: 2.60
	./2.60

2.66: ejercicio-2.66.c
	gcc $(CFLAGS) $(BINARIO) ejercicio-2.66.c  -o 2.66

run-2.66: 2.66
	./2.66

check: 2.61 2.60 2.66
	echo "Si no se rompe esta todo ok(?"
	rm 2.61 2.60 2.66