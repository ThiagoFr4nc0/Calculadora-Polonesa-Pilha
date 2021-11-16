cmake_minimum_required(VERSION 3.20)
project(Calculadora_Pilha C)

set(CMAKE_C_STANDARD 99)

add_executable(Calculadora_Pilha main.c utilitarios.c utilitarios.h pilha.c pilha.h)
