/*
* =========================================
 * Disciplina  : Estrutura de Dados
 * Aluno       : Anthonny Gabriell Marins Alves
 * Turma       : Engenharia da Computação 2026.1
 * Data        : 09/05/2026
 * =========================================
 * Arquivo     : dados.h
 * Descrição   : Arquivo de cabeçalho das funções referentes ao acesso dos dados de persistência.
 * =========================================
 */

#ifndef GERENCIADOR_DE_URLS_DADOS_H
#define GERENCIADOR_DE_URLS_DADOS_H

#include "lista_url.h"

t_lista* obter_dados();
void salvar_dados(t_lista* lista);

#endif //GERENCIADOR_DE_URLS_DADOS_H