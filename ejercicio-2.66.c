//
// Created by besednjak on 10/14/20.
//
/*
2.66

Implementar la función:

int leftmost_one(uint32_t val);

que devuelve una máscara indicando el bit más significativo en val que está a 1. Por ejemplo, se devuelve 0x8000 para val=0xFF00 y 0x4000 para val=0x6600.
*/
#include <stdio.h>
#include <stdint.h>
#include "decimalABinario/decimalABinario.h"

uint32_t definirBorrador(uint32_t val){
    uint32_t borrador = 0x80000000;
    while ((borrador & val) == 0){
        borrador = borrador >> 1;
    }
    return borrador;
}

int leftmost_one(uint32_t val){
    uint32_t borrador = definirBorrador(val);
    return (int)(val & borrador);
}

uint32_t pedirNumero(){
    uint32_t entrada = 0;

    printf("Ingrese un numero positivo: ");
    scanf("%u", &entrada);

    printf("Numero ingresado en ");
    imprimirNumeroEnBinario(entrada);

    return entrada;
}

int main(){
    uint32_t val = pedirNumero();
    int resultado = leftmost_one(val);
    printf("Resultado en ");
    imprimirNumeroEnBinario((uint32_t) resultado);
    printf("Resultado en Int: %d\n", resultado);

    return 0;
}