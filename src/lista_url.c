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
    t_lista *no = malloc(sizeof(t_lista));

    no->url = url;
    no->proximo = NULL;
    no->anterior = lista;

    return no;
}
