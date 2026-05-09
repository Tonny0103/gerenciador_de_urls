/*
* =========================================
 * Disciplina  : Estrutura de Dados
 * Aluno       : Anthonny Gabriell Marins Alves
 * Turma       : Engenharia da Computação 2026.1
 * Data        : 09/05/2026
 * =========================================
 * Arquivo     : dados.c
 * Descrição   : Arquivo de implementação das funções referentes ao acesso dos dados de persistência.
 * =========================================
 */

#include <stdio.h>
#include "../include/dados.h"
#include <string.h>

t_lista* obter_dados() {
    t_lista* lista = NULL;
    FILE* arquivo = fopen("dados.txt", "r");

    if (arquivo != NULL) {
        char linha[2200];
        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            linha[strcspn(linha, "\n")] = '\0'; // remove o \n do final
            t_url* url = ler_url(linha);
            lista = inserir_url(lista, url);
        }
        fclose(arquivo);
    }

    return lista;
}

void salvar_dados(t_lista* lista) {
    FILE* arquivo = fopen("dados.txt", "w");
    t_lista* atual = lista;
    while (atual != NULL) {
        fprintf(arquivo, "%s|", atual->url->endereco);
        fprintf(arquivo, "%s|", atual->url->data);
        fprintf(arquivo, "%s\n", atual->url->hora);
        atual = atual->proximo;
    }
    fclose(arquivo);
}