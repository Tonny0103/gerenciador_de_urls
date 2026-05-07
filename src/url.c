#include "../include/url.h"

#include <stdlib.h>
#include <string.h>

t_url* ler_url(char* linha) {
    char *token;
    const char *separador = "|";
    t_url* url = malloc(sizeof(t_url));

    token = strtok(linha, separador);
    url->endereco = strdup(token);

    token = strtok(NULL, separador);
    url->data = strdup(token);

    token = strtok(NULL, separador);
    url->hora = strdup(token);

    return url;
}