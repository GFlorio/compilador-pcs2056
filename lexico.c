#include <stdio.h>
#include <stdlib.h>
#include "lexico.h"
#include "valor.h"
//
// Created by gabriel on 02/10/17.
//
#define PAU (-1)
#define S0 0    // Estado inicial
#define ASS 1   // Assignment =
#define EQU 2   // Equals ==
#define ID1 3   // Primeiro caractere de um identificador
#define ID2 4   // Demais caracteres de um identificador
#define ZER 5   // O número 0
#define NUM 6   // Outros inteiros
#define FLO 7   // Ponto flutuante
#define DEC 8   // Números decimais
#define GTL 9   // < ou >
#define GTE 10  // >= ou <=
#define OPS 11  // + - * /
#define DEL 12  // Delimitadores
#define STR 13  // Dentro de uma string
#define ENS 14  // Final da string
#define NOT 15  // !
#define NEQ 16  // !=


Tipo calcula_tipo(int state) {
    switch (state) {
        case ID1:
        case ID2:
            return IDENTIFICADOR;
        case ZER:
        case NUM:
            return INTEIRO;
        case FLO:
        case DEC:
            return FLOAT;
        case EQU:
        case GTL:
        case GTE:
        case NEQ:
            return COMPARADOR;
        case ASS:
        case OPS:
        case NOT:
            return OPERADOR;
        case DEL:
            return DELIMITADOR;
        case ENS:
            return STRING;
        case STR:
            return COMENTARIO;
        default:
            return ERRO;
    }
}


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
        {NOT, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // !
        {STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,ENS, S0, S0,PAU}, // "
        {PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // #
        {PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // $
        {PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // %
        {PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // %
        {PAU, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // '
        {DEL, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // (
        {DEL, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // )
        {OPS, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // *
        {OPS, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // +
        {DEL, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // ,
        {OPS, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // -
        {PAU, S0, S0, S0, S0,FLO,FLO,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU}, // .
        {OPS, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // /
        {ZER, S0, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 0
        {NUM, S0, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 1
        {NUM, S0, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 2
        {NUM, S0, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 3
        {NUM, S0, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 4
        {NUM, S0, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 5
        {NUM, S0, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 6
        {NUM, S0, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 7
        {NUM, S0, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 8
        {NUM, S0, S0, S0,ID2,PAU,NUM,DEC,DEC, S0, S0, S0, S0,STR, S0, S0,PAU}, // 9
        {STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // :
        {STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // ;
        {GTL, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // <
        {ASS,EQU, S0, S0, S0, S0, S0, S0, S0,GTE, S0, S0, S0,STR, S0,NEQ,PAU}, // =
        {GTL, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // >
        {STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // ?
        {STR, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // @
        //S0 ass equ S1  S2  zer int flo dec gtl gte ops del STR ENS not neq
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU}, // A
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU}, // Z
        {DEL,S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // [
        {STR,S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // backslash
        {DEL,S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // ]
        {STR,S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // ^
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU}, // _ (underline)
        {STR,S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // `
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU}, // a
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU},
        {ID1,S0, S0,ID2,ID2,PAU,PAU,PAU,PAU, S0, S0, S0, S0,STR, S0, S0,PAU}, // z
        {DEL,S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // {
        {STR,S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // |
        {DEL,S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // }
        {STR,S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0,STR, S0, S0,PAU}, // ~
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
            token->tipo = ERRO;
            token->valor = malloc(sizeof(char));
            *((char*) token->valor) = (char) chr;
            return token;
        }
        if (next_state == 0) {
            if (state == 0) continue; // Consumir espaços extras.
            token->tipo = calcula_tipo(state);
            token->valor = calcula_valor(token->tipo, acumulado);
            fseek(fp, -1, SEEK_CUR);
            return token;
        }
        state = next_state;
        *cursor = (char) chr;
        cursor += 1;
    }
    token->tipo = FIM;
    token->valor = 0;
    return token;
}
