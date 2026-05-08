#include <stdio.h>
#include <stdlib.h>
#include "include/url.h"
#include "include/lista_url.h"
#include "include/menu.h"

int main(void) {
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

    menu(lista);

    liberar_lista(lista);

    return 0;
}
