#include "../include/navegacao.h"
#include <stdlib.h>

t_lista* navegar(t_lista* atual, int operacao) {
    if (operacao == 1 && atual->proximo != NULL) return atual->proximo;
    if (operacao == 2 && atual->anterior != NULL) return atual->anterior;
    return atual;
}