#include <stdio.h>
#include <stdlib.h>
#include "lexico.h"

int main(int argc, char *argv[]) {
    Token* token;
    FILE* fp = fopen(argv[1], "r");
    do {
        token = getToken(fp);
        if(token->tipo == -1) {
            printf("Erro lexico! Caractere %c nao esperado!", (char) token->valor);
            return 666;
        }
        printf("Token recebido. Tipo: %d. Valor: %d", token->tipo, token->valor);
        free(token);
    } while(token->tipo != 0);
    fclose(fp);
    return 0;
}