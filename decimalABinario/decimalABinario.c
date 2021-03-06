//
// Created by besednjak on 10/11/20.
//

#include <stdio.h>
#include "decimalABinario.h"

void inicializarBinario(char binario[]){
    for(int i = 0; i < CANTIDAD_BITS; i++){
        binario[i] = '0';
    }
}

void decimalABinario(uint32_t decimal, char binario[]){
    inicializarBinario(binario);
    unsigned int contador = CANTIDAD_BITS - 1;
    unsigned int resto = 0;

    while(decimal > 0){
        resto = decimal%2;
        decimal /= 2;
        binario[contador] = resto == 1? '1' : '0';
        contador--;
    }
}

void imprimirNumeroEnBinario(uint32_t x){
    char xBinario[CANTIDAD_BITS];
    decimalABinario(x, xBinario);
    printf("Binario: ");
    imprimirFormato(xBinario);
}

void imprimirFormato(char binario[]){
    printf("\n");
    for(int i = 0; i < CANTIDAD_BITS; i++){
        printf("%c", binario[i]);
        if((i + 1) % 8 == 0){
            printf(" ");
        }
    }
    printf("\n");
}

