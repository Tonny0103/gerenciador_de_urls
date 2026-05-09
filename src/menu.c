#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lista_url.h"
#include "../include/navegacao.h"

void menu_editar(t_lista* atual) {
    int op = 0;

    while (op != 4) {
        system("cls || clear");
        printf("=== Editando URL ===\n");
        printf("1 - Endereco : %s\n", atual->url->endereco);
        printf("2 - Data     : %s\n", atual->url->data);
        printf("3 - Hora     : %s\n", atual->url->hora);
        printf("4 - Voltar\n");
        printf("\nOpcao: ");
        scanf("%d", &op);

        if (op < 1 || op > 3) continue;

        t_url* novo = malloc(sizeof(t_url));
        novo->endereco = strdup(atual->url->endereco);
        novo->data     = strdup(atual->url->data);
        novo->hora     = strdup(atual->url->hora);

        if (op == 1) { free(novo->endereco); novo->endereco = ler_endereco(); }
        if (op == 2) { free(novo->data);     novo->data     = ler_data(); }
        if (op == 3) { free(novo->hora);     novo->hora     = ler_hora(); }

        editar_url(atual, novo);
    }
}


void menu(t_lista* lista) {
    int op = 0;
    t_lista* atual = lista;
    while (op != 3) {
        if (atual != NULL) {
            system("cls || clear");
            printf("URL: %s\n", atual->url->endereco);
            printf("Data: %s\n", atual->url->data);
            printf("Hora: %s\n", atual->url->hora);
            printf("\n");
            if (atual->proximo != NULL) printf("1 - Proxima URL\n");
            if (atual->anterior != NULL) printf("2 - URL Anterior\n");
            printf("3 - Editar\n");
            printf("4 - Sair\n");
            scanf("%d", &op);
            if (op == 3) menu_editar(atual);
            else atual = navegar(atual, op);
        }
    }
}
