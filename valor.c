//
// Created by gabriel on 03/10/17.
//

#include <stdlib.h>
#include <string.h>
#include "lexico.h"

void* valor_operador(const char* acumulado) {
    void* result_point;

    result_point = malloc(sizeof(char));
    *((char*) result_point) = *acumulado;
    return result_point;
}

void* valor_comparador(const char* acumulado) {
    void* result_point;

    result_point = malloc(sizeof(char));
    *((char*) result_point) = acumulado[0]+acumulado[1];
    return result_point;
}

void* valor_inteiro(const char* acumulado) {
    void* result_point;
    int total = 0;

    while (*acumulado != 0) {
        total *= 10;
        total += *acumulado-48;
        acumulado++;
    }
    result_point = malloc(sizeof(int));
    *((int*) result_point) = total;
    return result_point;
}

void* valor_float(const char* acumulado) {
    void* result_point;
    int decimal = 0;
    float divisor = 1.0;
    float total = 0.0;

    while (*acumulado != 0) {
        if (*acumulado == '.') {
            decimal = 1;
            acumulado++;
            continue;
        }
        if (decimal)
            divisor *= 10.0;
        total *= 10;
        total += *acumulado-48;
        acumulado++;
    }
    result_point = malloc(sizeof(float));
    *((float*) result_point) = total/divisor;
    return result_point;
}

void* valor_string(const char* acumulado) {
    void* result_point;
    int tam;

    for(tam = 0; acumulado[tam] != 0; tam++);
    result_point = malloc(tam * sizeof(char));
    strcpy(result_point, acumulado);

    return result_point;
}

void* calcula_valor(Tipo tipo, char* acumulado) {
    void* result_point;
    switch (tipo) {
        case OPERADOR:
        case DELIMITADOR:
            return valor_operador(acumulado);
        case COMPARADOR:
            return valor_comparador(acumulado);
        case INTEIRO:
            return valor_inteiro(acumulado);
        case FLOAT:
            return valor_float(acumulado);
        case IDENTIFICADOR:
        case STRING:
        case COMENTARIO:
            return valor_string(acumulado);
        case FIM:
            result_point = malloc(sizeof(int));
            *((int*) result_point) = 0;
            return result_point;
        case ERRO:
        default:
            return acumulado;
    }
}
