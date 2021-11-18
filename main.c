#include <stdio.h>
#include <string.h>
#include "utilitarios.h"
#include "pilha.h"

int main() {
    PILHA p;
    char aux[50];
    int *dado , *x , *y;

    pilha_inicializar(&p);

    printf("================================\n");
    printf("Calculadora polonesa reversa\n");
    printf("================================\n");
    putchar('\n');
    printf(" Digite os operandos e tecle [Enter]\n");
    printf("  Os operadores validos sao +, -, * e /\n"); //pilha_pop /
    printf("  q :sai\n");//exit x
    printf("  l :exibe a pilha\n");//pilha_peek x
    printf("  s :troca o topo com o elemento anterior\n");//pilha switch /
    printf("  d :descarta topo\n");//pilha_pop x
    putchar('\n');
    do
    {
        while(!ler_String(&aux, "", 50));

        //comandos
        if(strcmp(aux, "q") == 0){
            printf("tchau!");
        }
        if(strcmp(aux, "l") == 0){
            if (pilha_PEEK(&p , &dado) != ERRO_UNDERFLOW)
            {
                printf("//",dado);
            }
            printf("lista");
        }
        if(strcmp(aux, "s") == 0){
            if (pilha_TROCA(&p , &dado) != ERRO_UNDERFLOW)
            {
                printf("@");

            }
            x = dado;
            if (pilha_TROCA(&p , &dado)!= ERRO_UNDERFLOW) {

                printf("#");
            }
            y = dado;
            pilha_PUSH(&p , &x);
            pilha_PUSH(&p , &y);
            printf("troca");
        }
        if(strcmp(aux, "d") == 0){
            if (pilha_POP(&p , &dado) != ERRO_UNDERFLOW)
            {
                printf("%s/",aux);
                printf("%d",dado);
            }
            printf("deleta topo");
        }
        //opareção
        if(strcmp(aux, "+") == 0|| strcmp(aux, "-") == 0|| strcmp(aux, "*") == 0|| strcmp(aux, "/") == 0){
            if (pilha_OPERACAO(&p , &dado) != ERRO_UNDERFLOW)
            {
                printf("//");
                pilha_PUSH(&p , &dado);
                printf("%d",dado);
            }
            printf("!\n");
        }
        //pilha_push
        dado = atoi(aux);
        if(dado < 0 || dado > 0){
            if (pilha_PUSH(&p , &dado) != ERRO_UNDERFLOW) {
                printf("%s/", aux);
                printf("%d", dado);
            }
        }
    } while (strcmp(aux, "q") != 0);
    pilha_destruir(&p);
    return 0;
}
