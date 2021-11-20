#include <stdlib.h>
#include "pilha.h"
#include "utilitarios.h"

ERRO_PILHA pilha_inicializar (PILHA *pilha)
{
    *pilha = NULL;
    return ERRO_SUCESSO;
}

ERRO_PILHA pilha_destruir (PILHA *pilha)
{
    PILHA aux, ant;

    aux = *pilha;
    ant = NULL;
    while (aux != NULL)
    {
        ant = aux;
        aux = aux->sucessor;
        free(ant);
    }
    *pilha = NULL;
    return ERRO_SUCESSO;
}

ERRO_PILHA pilha_PUSH (PILHA *pilha, const TIPO_DADO *dado)
{
    PILHA novo;

    novo = (PILHA) malloc(sizeof (NO_PILHA));
    if (novo == NULL)
    {
        return ERRO_OVERFLOW;
    }

    novo->dado = *dado;
    novo->sucessor = *pilha;
    *pilha = novo;

    return ERRO_SUCESSO;
}

ERRO_PILHA pilha_POP (PILHA *pilha, TIPO_DADO *dado)
{
    PILHA aux;

    aux = *pilha;
    if (aux == NULL) // pilha vazia
    {
        return ERRO_UNDERFLOW;
    }
    *pilha = aux->sucessor;
    if (dado != NULL)
    {
        *dado = aux->dado;
    }
    free(aux);
    return ERRO_SUCESSO;
}

ERRO_PILHA pilha_PEEK (PILHA *pilha, TIPO_DADO *dado)
{
    PILHA aux, ant;

    aux = *pilha;
    ant = NULL;
    if (*pilha == NULL) // vazia
    {
        return ERRO_UNDERFLOW;
    }
    while (aux != NULL)
    {
        ant = aux;
        aux = aux->sucessor;
        printf("%d \n",*ant);
    }
    return ERRO_SUCESSO;

}

ERRO_PILHA pilha_OPERACAO (PILHA *pilha, TIPO_DADO *dado ,CRITERIO opcao )
{
    PILHA aux,ant;
    int x , y;

    aux = *pilha;
    ant = *pilha;

    if (ant == NULL) // pilha vazia
    {
        return ERRO_UNDERFLOW;
    }
    *pilha = ant->sucessor;
    if (dado != NULL)
    {
        *dado = ant->dado;
        x = *dado;
    }
    aux = *pilha;
    if (aux == NULL) // pilha vazia
    {
        return ERRO_UNDERFLOW;
    }
    *pilha = aux->sucessor;
    if (dado != NULL)
    {
        *dado = aux->dado;
        y = *dado;
    }
    if(ant != NULL || aux != NULL) {
        free(ant);
        free(aux);
    }
    switch (opcao)
    {
        case SUM:
            *dado = x + y;
            break;
        case SUB:
            *dado = x - y;
            break;
        case MULT:
            *dado = x * y;
            break;
        case DIV:
            *dado = x / y;
            break;
    }
    return ERRO_SUCESSO;
}

bool pilha_esta_cheia(const PILHA *pilha)
{
    return false;
}

bool pilha_esta_vazia(const PILHA *pilha)
{
    return (*pilha == NULL);
}