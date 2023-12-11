#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
    orcamento orcamento;

    mostrarDados(&orcamento);

    char descricao[100];
    float valor;

    printf("\nBem vindo!\nO que gostaria de fazer?\n");

    while(1){
        int opcao;

        printf("\nAdicionar transacao (1)\nVer transacoes (2)\nReiniciar o orcamento (3)\nSair (4)\n\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nDescricao da transacao: ");
                getchar();
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = '\0';

                printf("Valor da transacao: ");
                scanf("%f", &valor);

                adicionar_transacao(&orcamento, descricao, valor);

                salvaDados(&orcamento);

                break;
            case 2:
                mostrar_transacao(&orcamento);

                break;
            case 3:
                reinicializarOrcamento(&orcamento);

                break;
            case 4:
                printf("\nSaindo...\n");
                exit(0);
            default:
                printf("\nOpcao invalida!\n");
        }
    }

    return 0;
}