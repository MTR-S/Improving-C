cmake_minimum_required(VERSION 3.26)
project(Estudando_Ponteiros C)

set(CMAKE_C_STANDARD 99)

add_executable(Estudando_Ponteiros main.c
        ponteiros.c
        ponteiros.h
        estruturas.c
        estruturas.h
        alocacaoDinamica.c
        alocacaoDinamica.h
)
