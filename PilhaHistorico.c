#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaHistorico.h"

PilhaHistorico* criarPilha() {
    PilhaHistorico* p = (PilhaHistorico*)malloc(sizeof(PilhaHistorico));
    p->topo = NULL;
    return p;
}
void push(PilhaHistorico* p, const char* descricao) {
    Acao* nova = (Acao*)malloc(sizeof(Acao));
    strcpy_s(nova->descricao, sizeof(nova->descricao), descricao);
    nova->prox = p->topo;
    p->topo = nova;
}
void pop(PilhaHistorico* p) {
    if (!p->topo) return;
    Acao* temp = p->topo;
    p->topo = p->topo->prox;
    free(temp);
}
void imprimirHistorico(PilhaHistorico* p) {
    Acao* atual = p->topo;
    while (atual) {
        printf("- %s\n", atual->descricao);
        atual = atual->prox;
    }
}
void liberarPilha(PilhaHistorico* p) {
    while (p->topo) pop(p);
    free(p);
}