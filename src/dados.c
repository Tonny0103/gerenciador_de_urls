#include <stdio.h>
#include "../include/dados.h"
#include <string.h>

t_lista* obter_dados() {
    t_lista* lista = NULL;
    FILE* arquivo = fopen("dados.txt", "r");

    if (arquivo != NULL) {
        char linha[2200];
        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            linha[strcspn(linha, "\n")] = '\0'; // remove o \n do final
            t_url* url = ler_url(linha);
            lista = inserir_url(lista, url);
        }
        fclose(arquivo);
    }

    return lista;
}
