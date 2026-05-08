#include "../include/lista_url.h"

#include <stdlib.h>

t_lista* criar_no(t_url* url) {
    t_lista* no = malloc(sizeof(t_lista));
    no->url = url;
    no->proximo = NULL;
    no->anterior = NULL;
    return no;
}

t_lista* inserir_url(t_lista* lista, t_url* url) {
    t_lista* novo = criar_no(url);

    if (lista == NULL) return novo;

    t_lista* atual = lista;
    while (atual->proximo != NULL) atual = atual->proximo;

    atual->proximo = novo;
    novo->anterior = atual;

    return novo;
}