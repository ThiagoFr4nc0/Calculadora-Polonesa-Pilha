#include <stdio.h>
#include "utilitarios.h"
#include "pilha.h"
char menu();
int main() {
    char opcao[500];
    PILHA p;
    char dado;
    pilha_inicializar(&p);

    do
    {
        opcao[500] = menu();
        switch (opcao[500])
        {
            case 1:
                break;
            case 'q':
                printf("Tchau!\n");
            default:
                printf("Opcao invalida\n");
        }
    } while (opcao != "q");

    return 0;
}
char menu()
{
    char opcao[500];
    printf("================================\n");
    printf("Calculadora polonesa reversa\n");
    printf("================================\n");
    putchar('\n');
    printf(" Digite os operandos e tecle [Enter]\n");
    printf("  Os operadores validos sao +, -, * e /\n");
    printf("  q :sai\n");
    printf("  l :exibe a pilha\n");
    printf("  s :troca o topo com o elemento anterior\n");
    printf("  d :descarta topo\n");
    putchar('\n');
    while(!ler_String(&opcao, "", 500));
    return (char) opcao;
}