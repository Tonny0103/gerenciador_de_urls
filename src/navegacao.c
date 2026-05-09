/*
* =========================================
 * Disciplina  : Estrutura de Dados
 * Aluno       : Anthonny Gabriell Marins Alves
 * Turma       : Engenharia da Computação 2026.1
 * Data        : 09/05/2026
 * =========================================
 * Arquivo     : nome_do_arquivo.c
 * Descrição   : Arquivo de implementação das funções referentes a navegação.
 * =========================================
 */

#include "../include/navegacao.h"
#include <stdlib.h>

t_lista* navegar(t_lista* atual, int operacao) {
    if (operacao == 1 && atual->proximo != NULL) return atual->proximo;
    if (operacao == 2 && atual->anterior != NULL) return atual->anterior;
    return atual;
}