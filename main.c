#include <stdio.h>
#include <stdlib.h>
#include "lexico.h"

int main(int argc, char *argv[]) {
    Token* token;
    FILE* fp = fopen("../programa", "r");
    do {
        token = getToken(fp);
        switch (token->tipo) {
            case INTEIRO:
                printf("Token recebido. Tipo: INTEIRO. Valor: %d\n", *((int*) token->valor));
                break;
            case FLOAT:
                printf("Token recebido. Tipo: FLOAT. Valor: %f\n", *((float*) token->valor));
                break;
            case OPERADOR:
                printf("Token recebido. Tipo: OPERADOR. Valor: %s\n", (char*) token->valor);
                break;
            case DELIMITADOR:
                printf("Token recebido. Tipo: DELIMITADOR. Valor: %s\n", (char*) token->valor);
                break;
            case COMPARADOR:
                printf("Token recebido. Tipo: COMPARADOR. Valor: %s\n", (char*) token->valor);
                break;
            case IDENTIFICADOR:
                printf("Token recebido. Tipo: IDENTIFICADOR. Valor: %s\n", (char*) token->valor);
                break;
            case STRING:
                printf("Token recebido. Tipo: STRING. Valor: %s\n", (char*) token->valor);
                break;
            case COMENTARIO:
                printf("Token recebido. Tipo: COMENTARIO. Valor: %s\n", (char*) token->valor);
                break;
            case FIM:
                printf("Token recebido. Tipo: FIM.\n");
                return 0;
            case ERRO:
                printf("Erro lexico! Caractere %c nao esperado!\n", (char) token->valor);
                return 666;
        }
        free(token->valor);
        free(token);
    } while(token->tipo != 0);
    fclose(fp);
    return 0;
}