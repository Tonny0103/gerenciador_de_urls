cmake_minimum_required(VERSION 4.1)
project(gerenciador_de_urls C)

set(CMAKE_C_STANDARD 11)

add_executable(gerenciador_de_urls main.c
        include/url.h
        src/url.c)
