/*
* =========================================
 * Disciplina  : Estrutura de Dados
 * Aluno       : Anthonny Gabriell Marins Alves
 * Turma       : Engenharia da Computação 2026.1
 * Data        : 09/05/2026
 * =========================================
 * Arquivo     : menu.h
 * Descrição   : Arquivo de cabeçalho das funções referentes ao menu.
 * =========================================
 */

#ifndef GERENCIADOR_DE_URLS_MENU_H
#define GERENCIADOR_DE_URLS_MENU_H

#include "lista_url.h"

void menu();
void menu_principal(t_lista* lista);
void menu_editar(t_lista* atual);
void menu_ir_para_endereco(t_lista* atual);

#endif //GERENCIADOR_DE_URLS_MENU_H