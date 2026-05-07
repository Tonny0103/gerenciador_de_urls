#ifndef GERENCIADOR_DE_URLS_URL_H
#define GERENCIADOR_DE_URLS_URL_H

struct url {
    char endereco[2083];
    char data[11];
    char hora[9];
};

typedef struct url t_url;

t_url* ler_url(char* linha);
void editar_url(t_url* url);

#endif //GERENCIADOR_DE_URLS_URL_H