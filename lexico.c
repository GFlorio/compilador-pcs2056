#include <stdio.h>
#include <stdlib.h>
#include "lexico.h"
//
// Created by gabriel on 02/10/17.
//
#define PAU (-1)
#define S0 0
#define ASS 1
#define EQU 2
#define ID1 3
#define ID2 4
#define ZER 5
#define NUM 6
#define FLO 7
#define DEC 8
#define GTL 9
#define GTE 10
#define OPS 11
#define DEL 12
#define STR 13
#define ENS 14
#define NOT 15
#define NEQ 16

// Colunas são os estados, linhas são os caracteres recebidos, valores são o próximo estado.
int matriz_transicao[128][17] = {
        //S0 ass equ S1  S2  zer int flo dec gtl gte ops del STR ENS not neq
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        { S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0}, // new line
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU},
        //S0 ass equ S1  S2  zer NUM flo dec gtl gte ops del STR ENS not neq
        { S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0, S0}, // space
        {NOT,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // !
        {STR,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,ENS, S0, S0,PAU}, // "
        {STR,PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // #
        {STR,PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // $
        {STR,PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // %
        {STR,PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // '
        {DEL,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // (
        {DEL,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // )
        {OPS,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // *
        {OPS,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // +
        {DEL,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // ,
        {OPS,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // -
        {STR,PAU, S0, S0, S0,FLO,FLO,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU}, // .
        {OPS,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // /
        {ZER,STR, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 0
        {NUM,STR, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 1
        {NUM,STR, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 2
        {NUM,STR, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 3
        {NUM,STR, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 4
        {NUM,STR, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 5
        {NUM,STR, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 6
        {NUM,STR, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 7
        {NUM,STR, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 8
        {NUM,STR, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 9
        {STR,PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // :
        {STR,PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // ;
        {GTL,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // <
        {ASS,EQU, S0, S0, S0, S0, S0, S0, S0,GTE, S0, S0, S0,STR, S0,NEQ,PAU}, // =
        {GTL,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // >
        {STR,PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // ?
        {STR,PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // @
        //S0 ass equ S1  S2  zer int flo dec gtl gte ops del STR ENS not neq
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU}, // A
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU}, // Z
        {DEL,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // [
        {STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // backslash
        {DEL,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // ]
        {STR,PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // ^
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU}, // _ (underline)
        {STR,PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // `
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU}, // a
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,STR, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU}, // z
        {DEL,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // {
        {STR,PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // |
        {DEL,STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // }
        {STR,PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // ~
        {PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU,PAU}, // del
        //S0 ass equ S1  S2  zer int flo dec gtl gte ops del enl enf not neq
};

Token* getToken(FILE* fp) {
    int state = 0;
    int next_state = 0;
    char acumulado[64] = {'\0'};
    char* cursor = acumulado;
    int chr = 0;
    Token* token = (Token*) malloc(sizeof(Token));

    while ((chr = getc(fp)) != EOF) {
        next_state = matriz_transicao[chr][state];
        if (next_state == -1) {
            token->tipo = -1;
            token->valor = chr;
            return token;
        }
        if (next_state == 0) {
            token->tipo = state;
//            token->valor = calcula_valor(state, acumulado);
            return token;
        }
        *cursor = (char) chr;
        cursor += 1;

    }
    token->tipo = 0;
    token->valor = 0;
    return token;
}
