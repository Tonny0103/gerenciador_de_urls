/*
* =========================================
 * Disciplina  : Estrutura de Dados
 * Aluno       : Anthonny Gabriell Marins Alves
 * Turma       : Engenharia da Computação 2026.1
 * Data        : 09/05/2026
 * =========================================
 * Arquivo     : lista_url.h
 * Descrição   : Arquivo de cabeçalho para declaração dos tipos e funções referentes a lista duplamente encadeada de url.
 * =========================================
 */

#ifndef GERENCIADOR_DE_URLS_LISTA_H
#define GERENCIADOR_DE_URLS_LISTA_H

#include "url.h"

struct no {
    int indice;
    t_url* url;
    struct no* proximo;
    struct no* anterior;
};

typedef struct no t_lista;

t_lista* criar_no(t_url* url);
t_lista* inserir_url(t_lista* lista, t_url* url);
void editar_url(t_lista* item_lista, t_url* novo);
t_lista* remover_url(t_lista* item_lista);
void imprimir_lista(t_lista* lista);
void liberar_lista(t_lista* lista);
int tamanho_lista(t_lista* lista);

#endif //GERENCIADOR_DE_URLS_LISTA_H