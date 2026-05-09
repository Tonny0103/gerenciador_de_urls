/*
* =========================================
 * Disciplina  : Estrutura de Dados
 * Aluno       : Anthonny Gabriell Marins Alves
 * Turma       : Engenharia da Computação 2026.1
 * Data        : 09/05/2026
 * =========================================
 * Arquivo     : nome_do_arquivo.c
 * Descrição   : Arquivo de cabeçalho do tipo abstrato de dado da url e suas funções.
 * =========================================
 */

#ifndef GERENCIADOR_DE_URLS_URL_H
#define GERENCIADOR_DE_URLS_URL_H

struct url {
    char* endereco;
    char* data;
    char* hora;
};

typedef struct url t_url;

t_url* ler_url(char* linha);
void liberar_url(t_url* url);
void imprimir_url(t_url* url);
char* ler_endereco();
char* ler_data();
char* ler_hora();

#endif //GERENCIADOR_DE_URLS_URL_H