#ifndef PILHA_HISTORICO_H
#define PILHA_HISTORICO_H

typedef struct Acao {
    char descricao[100];
    struct Acao* prox;
} Acao;
typedef struct {
    Acao* topo;
} PilhaHistorico;

PilhaHistorico* criarPilha();
void push(PilhaHistorico* p, const char* descricao);
void pop(PilhaHistorico* p);
void imprimirHistorico(PilhaHistorico* p);
void liberarPilha(PilhaHistorico* p);

#endif