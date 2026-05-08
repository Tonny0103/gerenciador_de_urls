#include<stdio.h>
#include <stdlib.h>
#include "../include/lista_url.h"
#include "../include/navegacao.h"

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
            printf("3 - Sair\n");
            scanf("%d", &op);
            atual = navegar(atual, op);
        }
    }
}
