/*
* =========================================
 * Disciplina  : Estrutura de Dados
 * Aluno       : Anthonny Gabriell Marins Alves
 * Turma       : Engenharia da Computação 2026.1
 * Data        : 09/05/2026
 * =========================================
 * Arquivo     : nome_do_arquivo.c
 * Descrição   : Arquivo de implementação das funções referentes ao tipo abstrato de dado da url.
 * =========================================
 */

#include "../include/url.h"
#include <stdio.h>
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

void liberar_url(t_url* url) {
    free(url->endereco);
    free(url->data);
    free(url->hora);
    free(url);
}

void imprimir_url(t_url* url) {
    printf("URL: %s\n", url->endereco);
    printf("Data: %s\n", url->data);
    printf("Hora: %s\n", url->hora);
    printf("\n");
}

char* ler_endereco() {
    char endereco[2083];
    system("cls || clear");

    printf("Digite o endereco de URL:\n");
    scanf("%s", endereco);

    return strdup(endereco);
}

char* ler_data() {
    char data[11];
    system("cls || clear");

    printf("Digite a data de acesso da URL:\n");
    scanf("%10s", data);

    return strdup(data);
}

char* ler_hora() {
    char hora[9];
    system("cls || clear");

    printf("Digite a hora de acesso da URL:\n");
    scanf("%8s", hora);

    return strdup(hora);
}