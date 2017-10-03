//
// Created by gabriel on 02/10/17.
//

#include <stdio.h>

#ifndef LEXICO_LEXICO_H
#define LEXICO_LEXICO_H

typedef struct Token {
    int tipo;
    int valor;
} Token;

Token* getToken(FILE* fp);

#endif //LEXICO_LEXICO_H
