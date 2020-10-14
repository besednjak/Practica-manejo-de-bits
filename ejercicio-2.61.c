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
#include "decimalABinario/decimalABinario.h"

void imprimirNumeroEnBinario(uint32_t x){
    char xBinario[CANTIDAD_BITS];
    decimalABinario(x, xBinario);
    printf("Binario: ");
    imprimirBinario(xBinario);
}

void cualquierBitEs1(uint32_t x){
    uint32_t y = 0xFFFFFFFF;
    printf("\nMascara A, ");
    imprimirNumeroEnBinario(y);
    uint32_t resultado = ((x&y) != 0)? 1 : 0;
    printf("A. Tiene algun bit en 1? Resultado: %d.\n", resultado);
}

void cualquierBitEs0(uint32_t x){
    uint32_t y = 0xFFFFFFFF;
    printf("\nMascara B, ");
    imprimirNumeroEnBinario(y);
    uint32_t resultado = ((~x&y) != 0)? 1 : 0;
    printf("B. Tiene algun bit en 0? Resultado: %d.\n", resultado);
}

void cualquierBitEs1EnByteMenosSignificativo(uint32_t x){
    uint32_t y = 0xFF;
    printf("\nMascara C, ");
    imprimirNumeroEnBinario(y);
    uint32_t resultado = ((x&y) != 0)? 1 : 0;
    printf("C. Tiene algun bit en 1 en el byte menos significativo? Resultado: %d.\n", resultado);
}

void cualquierBitEs0EnByteMasSignificativo(uint32_t x){
    uint32_t y = 0xFF000000;
    printf("\nMascara D, ");
    imprimirNumeroEnBinario(y);
    uint32_t resultado = ((~x&y) != 0)? 1 : 0;
    printf("D. Tiene algun bit en 0 en el byte mas significativo? Resultado: %d.\n", resultado);
}

int main(){

    int entrada = 0;

    printf("Ingrese un numero positivo: ");
    scanf("%d", &entrada);

    uint32_t x = (unsigned int) entrada;
    printf("Numero ingresado en ");
    imprimirNumeroEnBinario(x);

    /*A.*/ cualquierBitEs1(x);
    /*B.*/ cualquierBitEs0(x);
    /*C.*/ cualquierBitEs1EnByteMenosSignificativo(x);
    /*D.*/ cualquierBitEs0EnByteMasSignificativo(x);

    return 0;
}


