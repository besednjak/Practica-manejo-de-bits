//
// Created by besednjak on 10/11/20.
//

/*
2.61
Escribir expresiones en C que devuelvan 1 cuando cada una de las las siguientes condiciones sean verdaderas, o 0 cuando no. Asumir que x es de tipo uint32_t.

A. Si cualquier bit de x es 1
B. Si cualquier bit de x es 0
C. Si cualquier bit en el byte menos significativo de x es 1
D. Si cualquier bit en el byte más significativo de x es 0

El código debe seguir las reglas de programación para enteros a nivel bit. Como restricción adicional, no se permite el uso de operadores de igualdad (==) y desigualdad (!=).
*/

#include <stdio.h>
#include <stdint.h>
#include "decimalABinario.h"

int main(){

    int entrada = 0;

    printf("Ingrese un numero positivo: ");
    scanf("%d", &entrada);

    uint32_t x = (unsigned int) entrada;
    char xBinario[CANTIDAD_BITS];
    decimalABinario(x, xBinario);
    imprimirBinario(xBinario);
    return 0;
}