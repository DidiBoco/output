#include <stdio.h>
#include <string.h>
#include "orcamento.h"

void adicionar_transacao(orcamento *orcamento, char *descricao, float valor){
    if(orcamento->num_transacoes >= MAX_TRANSACOES){
        printf("Limite de transações atingido.\n");
        return;
    }

    orcamento->transacoes[orcamento->num_transacoes] = (transacao){.valor = valor};

    strncpy(orcamento->transacoes[orcamento->num_transacoes].descricao, descricao, sizeof(orcamento->transacoes[orcamento->num_transacoes].descricao) - 1);

    orcamento->num_transacoes++;

    orcamento->saldo += valor;
}

void mostrar_transacao(orcamento *orcamento){

    printf("\nTransacoes realizadas: %d\n", orcamento->num_transacoes);

    for(int i=0; i<orcamento->num_transacoes; i++){
        printf("Descricao: %s | Valor: %.2f\n", orcamento->transacoes[i].descricao, orcamento->transacoes[i].valor);
    }

    printf("Saldo atual: %.2f\n", orcamento->saldo);
}

void reinicializarOrcamento(orcamento *orcamento){
    FILE *arquivo = fopen("dados.txt", "w");
    if (arquivo != NULL) {
        fclose(arquivo);
    }
    else{
        printf("Erro ao limpar o arquivo.\n");
        return;
    }

    orcamento->num_transacoes = 0;
    orcamento->saldo = 0;
}

void salvaDados(orcamento *orcamento) {
    FILE *arquivo;
    arquivo = fopen("dados.txt", "wb");

    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return;
    }

    fwrite(&orcamento->num_transacoes, sizeof(orcamento->num_transacoes), 1, arquivo);

    fwrite(orcamento->transacoes, sizeof(transacao), orcamento->num_transacoes, arquivo);

    fwrite(&orcamento->saldo, sizeof(orcamento->saldo), 1, arquivo);

    fclose(arquivo);
}

void mostrarDados(orcamento *orcamento) {
    FILE *arquivo;
    arquivo = fopen("dados.txt", "rb");

    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return;
    }

    fread(&orcamento->num_transacoes, sizeof(orcamento->num_transacoes), 1, arquivo);

    fread(orcamento->transacoes, sizeof(transacao), orcamento->num_transacoes, arquivo);

    fread(&orcamento->saldo, sizeof(orcamento->saldo), 1, arquivo);

    fclose(arquivo);
}