#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utilitarios.h"
#include "pilha.h"

int main() {
    PILHA p;
    char aux[100];
    int *dado , *x , *y ;

    pilha_inicializar(&p);

    printf("================================\n");
    printf("Calculadora polonesa reversa\n");
    printf("================================\n");
    putchar('\n');
    printf(" Digite os operandos e tecle [Enter]\n");
    printf("  Os operadores validos sao +, -, * e /\n"); //pilha_pop x
    printf("  q :sai\n");//exit x
    printf("  l :exibe a pilha\n");//pilha_peek x
    printf("  s :troca o topo com o elemento anterior\n");//pilha switch x
    printf("  d :descarta topo\n");//pilha_pop x
    putchar('\n');
    do
    {
        while(!ler_String(&aux, "", 100));

        //comandos
        if(strcmp(aux, "q") == 0){
            if (pilha_PEEK(&p , &dado) != ERRO_UNDERFLOW)
            {
                printf("tchau!");
            }
        }
        if(strcmp(aux, "l") == 0){
            if (pilha_PEEK(&p , &dado) != ERRO_UNDERFLOW)
            {
                printf("lista\n");
                continue;
            }
            printf("Pilha está vazia\n");
        }
        if(strcmp(aux, "s") == 0){
            if (pilha_POP(&p , &dado) != ERRO_UNDERFLOW) {
                x = dado;

            if (pilha_POP(&p , &dado) != ERRO_UNDERFLOW) {
                y = dado;
                pilha_PUSH(&p , &x);
                pilha_PUSH(&p , &y);
                printf("troca\n");
                continue;
            }


            }

            printf("Pilha está vazia\n");
        }
        if(strcmp(aux, "d") == 0){
            if (pilha_POP(&p , &dado) != ERRO_UNDERFLOW)
            {
                printf("%d-",dado);
                printf("deleta topo\n");
                continue;
            }
            printf("Pilha está vazia\n");
        }
        //opareção
        if(strcmp(aux, "+") == 0){
            if (pilha_OPERACAO(&p , &dado ,SUM) != ERRO_UNDERFLOW)
            {
                pilha_PUSH(&p , &dado);
                printf("%d\n",dado);
                continue;
            }
            printf("falta operador!\n");
        }
        if(strcmp(aux, "-") == 0){
            if (pilha_OPERACAO(&p , &dado ,SUB) != ERRO_UNDERFLOW)
            {
                pilha_PUSH(&p , &dado);
                printf("%d\n",dado);
                continue;
            }
            printf("falta operador!\n");
        }
        if(strcmp(aux, "*") == 0){
            if (pilha_OPERACAO(&p , &dado ,MULT) != ERRO_UNDERFLOW)
            {
                pilha_PUSH(&p , &dado);
                printf("%d\n",dado);
                continue;
            }
            printf("falta operador!\n");
        }
        if(strcmp(aux, "/") == 0){
            if (pilha_OPERACAO(&p , &dado ,DIV) != ERRO_UNDERFLOW)
            {
                pilha_PUSH(&p , &dado);
                printf("%d\n",dado);
                continue;
            }
            printf("falta operador!\n");
        }
        //pilha_push
        dado = atoi(aux);

        if(dado < 0 || dado > 0){
            if (pilha_PUSH(&p , &dado) != ERRO_UNDERFLOW) {
                printf("%d\n", dado);
            }
        }
    } while (strcmp(aux, "q") != 0);
    pilha_destruir(&p);
    return 0;
}
