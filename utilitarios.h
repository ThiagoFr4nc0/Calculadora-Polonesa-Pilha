
#ifndef CALCULADORA_PILHA_UTILITARIOS_H
#include <stdbool.h>
#define CALCULADORA_PILHA_UTILITARIOS_H
bool ler_Inteiro(long int *iLongo, const char *prompt, long int limite_inferior, long int limite_superior);
bool ler_String(char *buffer, const char *prompt, int tamanho);
#endif //CALCULADORA_PILHA_UTILITARIOS_H
