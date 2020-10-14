//
// Created by besednjak on 10/11/20.
//
/*
2.60

Implementar la función:

uint32_t replace_byte(uint32_t val, int i, uint8_t rempl);

que devuelve el entero val con su i-ésimo byte cambiado al valor de rempl. Los bytes se numeran asignando i=0 al byte menos significativo e i=3 al más significativo.
*/

#include <stdio.h>
#include <stdint.h>
#include "decimalABinario.h"

//4 bytes = xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
//           byte 3   byte 2   byte 1   byte 0

void imprimirNumeroEnBinario(uint32_t x){
    char xBinario[CANTIDAD_BITS];
    decimalABinario(x, xBinario);
    printf("Binario: ");
    imprimirBinario(xBinario);
}

uint32_t borrarByte(uint32_t val, int posicion){
    uint32_t mascara = (0xff << (posicion * 8));
    uint32_t borrador = ~mascara;
    return (val & borrador);
}

uint32_t mascaraEn32Bits(uint8_t byteAMover, int posicion){
    uint32_t resultado = (uint32_t) byteAMover;
    resultado = (resultado << (posicion * 8));
    return resultado;
}

uint32_t replace_byte(uint32_t val, int i, uint8_t rempl){
    uint32_t reemplazoEn32Bits = mascaraEn32Bits(rempl, i);
    val = borrarByte(val, i);
    return (val | reemplazoEn32Bits);
}

int pedirByteACambiar(){
    int byteACambiar = -1;
    while(byteACambiar < 0 || byteACambiar > 3){
        printf("Ingrese el numero del byte que quiere cambiar, 0, 1, 2 o 3: \n\n");
        printf("4 Bytes: xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx\n");
        printf("             3        2        1        0   \n");
        scanf("%d", &byteACambiar);
    }
    return byteACambiar;
}

uint8_t pedirNumeroDeReemplazo(){
    int numeroParaReemplazar = -1;

    while(numeroParaReemplazar < 0 || numeroParaReemplazar > 255){
        printf("Ingrese el numero para usar como reemplazo (de 0 a 255): ");
        scanf("%d", &numeroParaReemplazar);
    }

    printf("Numero ingresado en ");
    imprimirNumeroEnBinario((uint32_t) numeroParaReemplazar);

    return (uint8_t) numeroParaReemplazar;
}

uint32_t pedirNumeroACambiar(){

    int entrada = 0;

    printf("Ingrese un numero positivo: ");
    scanf("%d", &entrada);

    printf("Numero ingresado en ");
    imprimirNumeroEnBinario((uint32_t) entrada);

    return (uint32_t) entrada;
}

int main(){
    uint32_t numeroACambiar = pedirNumeroACambiar();
    uint8_t numeroDeReemplazo = pedirNumeroDeReemplazo();
    int posicion = pedirByteACambiar();

    uint32_t resultado = replace_byte(numeroACambiar, posicion, numeroDeReemplazo);

    printf("Resultado en ");
    imprimirNumeroEnBinario(resultado);
    printf("Resultado en uint32_t: %u\n", resultado);

    return 0;
}
