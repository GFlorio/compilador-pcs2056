//
// Created by gabriel on 02/10/17.
//

#include <stdio.h>

#ifndef LEXICO_LEXICO_H
#define LEXICO_LEXICO_H

typedef enum {
    IDENTIFICADOR,
    INTEIRO,
    FLOAT,
    COMPARADOR,
    OPERADOR,
    STRING,
    COMENTARIO,
    DELIMITADOR,
    FIM,
    ERRO
} Tipo;

typedef struct Token {
    Tipo tipo;
    void* valor;
} Token;


Token* getToken(FILE* fp);

#endif //LEXICO_LEXICO_H
