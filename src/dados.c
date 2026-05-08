#include <stdio.h>
#include "../include/dados.h"

t_lista* obter_dados() {
    t_lista* lista = NULL;
    FILE* arquivo = fopen("dados.txt", "r");

    if (arquivo != NULL) {
        char linha[256];
        while (fscanf(arquivo, "%255s", linha) != EOF) {
            t_url* url = ler_url(linha);
            lista = inserir_url(lista, url);
        }
        fclose(arquivo);
    }

    return lista;
}