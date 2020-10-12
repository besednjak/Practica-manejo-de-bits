//
// Created by besednjak on 10/11/20.
//

#ifndef DECIMALABINARIO_H
#define DECIMALABINARIO_H

#include <stdint.h>

#define CANTIDAD_BITS 32
#define MAX_UINT32 4294967295

void inicializarBinario(char binario[]);

void decimalABinario(uint32_t x, char binario[]);

void imprimirBinario(char binario[]);

#endif //DECIMALABINARIO_H
