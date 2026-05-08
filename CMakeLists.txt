cmake_minimum_required(VERSION 4.1)
project(gerenciador_de_urls C)

set(CMAKE_C_STANDARD 11)

add_executable(gerenciador_de_urls main.c
        include/url.h
        src/url.c
        include/lista_url.h
        src/lista_url.c
        include/navegacao.h
        src/navegacao.c
        include/menu.h
        src/menu.c
        include/dados.h
        src/dados.c)

configure_file(dados.txt dados.txt COPYONLY)