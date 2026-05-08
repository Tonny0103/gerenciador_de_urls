#include "../include/lista_url.h"

#include <stdio.h>
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

    return lista;
}

void imprimir_lista(t_lista* lista) {
    t_lista* atual = lista;
    while (atual != NULL) {
        printf("%s|%s|%s\n", atual->url->endereco, atual->url->data, atual->url->hora);
        atual = atual->proximo;
    }
}

void editar_url(t_lista** item_lista, t_url* novo) {
    t_url* url_antiga = (*item_lista)->url;
    (*item_lista)->url = novo;
    liberar_url(url_antiga);
}

void liberar_lista(t_lista* lista) {
    t_lista* atual = lista;
    while (atual != NULL) {
        liberar_url(atual->url);
        t_lista* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}