#include "include/dados.h"
#include "include/menu.h"

int main(void) {
    t_lista* lista = obter_dados();
    menu(lista);
    salvar_dados(lista);
    liberar_lista(lista);

    return 0;
}
