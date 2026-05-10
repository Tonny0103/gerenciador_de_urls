/*
* =========================================
 * Disciplina  : Estrutura de Dados
 * Aluno       : Anthonny Gabriell Marins Alves
 * Turma       : Engenharia da Computação 2026.1
 * Data        : 09/05/2026
 * =========================================
 * Arquivo     : menu.c
 * Descrição   : Arquivo de implementação das funções referentes ao menu.
 * =========================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/navegacao.h"
#include "../include/menu.h"
#include "../include/dados.h"

void menu_ir_para_endereco(t_lista** atual) {
    system("cls || clear");

    t_lista* inicio = *atual;
    while (inicio != NULL && inicio->anterior != NULL) inicio = inicio->anterior;
    if (tamanho_lista(inicio) >= 10) {
        printf("=== Limite atingido ===\n");
        printf("O historico ja possui 10 URLs. Remova uma antes de adicionar.\n");
        printf("\nPressione ENTER para voltar...");
        getchar(); getchar();
        return;
    }

    time_t t = time(NULL);
    struct tm* tm_info = localtime(&t);

    t_url* url = malloc(sizeof(t_url));
    char endereco[2084];
    char data[11];
    char hora[9];

    printf("=== Ir para o endereco URL ===\n");
    printf("Endereco: ");
    scanf("%2083s", endereco);

    strftime(data, sizeof(data), "%d/%m/%Y", tm_info);
    strftime(hora, sizeof(hora), "%H:%M:%S", tm_info);

    url->endereco = strdup(endereco);
    url->data     = strdup(data);
    url->hora     = strdup(hora);

    *atual = inserir_url(*atual, url);
    while ((*atual)->proximo != NULL) *atual = (*atual)->proximo;
}

void menu_editar(t_lista* atual) {
    int op = 0;

    while (op != 4) {
        system("cls || clear");
        printf("=== Editando URL ===\n");
        printf("1 - Endereco : %s\n", atual->url->endereco);
        printf("2 - Data     : %s\n", atual->url->data);
        printf("3 - Hora     : %s\n", atual->url->hora);
        printf("4 - Voltar\n");
        printf("\nOpcao: ");
        scanf("%d", &op);

        if (op < 1 || op > 3) continue;

        t_url* novo = malloc(sizeof(t_url));
        novo->endereco = strdup(atual->url->endereco);
        novo->data     = strdup(atual->url->data);
        novo->hora     = strdup(atual->url->hora);

        if (op == 1) { free(novo->endereco); novo->endereco = ler_endereco(); }
        if (op == 2) { free(novo->data);     novo->data     = ler_data(); }
        if (op == 3) { free(novo->hora);     novo->hora     = ler_hora(); }

        editar_url(atual, novo);
    }
}

void menu_principal(t_lista** lista) {
    int op = 0;
    t_lista* inicio = *lista;
    t_lista* atual = *lista;

    while (op != 6) {
        system("cls || clear");

        int tamanho = tamanho_lista(*lista);

        printf("=== Menu Principal ===\n");
        if (atual == NULL) {
            printf("Nenhuma URL cadastrada! Use a opcao 2 para adicionar.\n");
            printf("\n");
            printf("2 - Ir para o endereco\n");
            printf("5 - Sair\n");
        } else {
            printf("%d de %d\n", atual->indice + 1, tamanho);
            printf("URL: %s\n", atual->url->endereco);
            printf("Data: %s\n", atual->url->data);
            printf("Hora: %s\n", atual->url->hora);
            printf("\n");
            printf("1 - Editar URL\n");
            printf("2 - Ir para o endereco\n");
            if (atual->proximo != NULL) printf("3 - Proxima URL\n");
            if (atual->anterior != NULL) printf("4 - URL Anterior\n");
            printf("5 - Remover URL\n");
            printf("6 - Sair\n");
        }
        printf("\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                menu_editar(atual);
                break;
            case 2:
                menu_ir_para_endereco(&atual);
                inicio = atual;
                while (inicio->anterior != NULL) inicio = inicio->anterior;
                *lista = inicio;
                break;
            case 3:
                atual = navegar(atual, 1);
                break;
            case 4:
                atual = navegar(atual, 2);
                break;
            case 5:
                atual = remover_url(atual);
                if (atual != NULL) {
                    inicio = atual;
                    while (inicio->anterior != NULL) inicio = inicio->anterior;
                } else {
                    inicio = NULL;
                }
                *lista = inicio;
                break;
            case 6: return;
            default:
                printf("Digite uma opcao valida!\n");
        }
    }
}

void menu() {
    t_lista* lista = obter_dados();
    menu_principal(&lista);
    salvar_dados(lista);
    liberar_lista(lista);
}