#ifndef GERENCIADOR_DE_URLS_LISTA_H
#define GERENCIADOR_DE_URLS_LISTA_H

#include "url.h"

struct no {
    t_url* url;
    struct no* proximo;
    struct no* anterior;
};

typedef struct no t_lista;

void inserir_url(t_lista* lista, t_url* url);
void imprimir_lista(t_lista* lista);
void liberar_lista(t_lista* lista);

#endif //GERENCIADOR_DE_URLS_LISTA_H