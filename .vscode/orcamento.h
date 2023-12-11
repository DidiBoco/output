#define MAX_TRANSACOES 100

typedef struct{
    char descricao[100];
    float valor;
}transacao;

typedef struct{
    int num_transacoes;
    transacao transacoes[MAX_TRANSACOES];
    float saldo;
}orcamento;