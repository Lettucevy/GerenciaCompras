#include <stdio.h>
#include <stdlib.h>
#include "Loja.h"

Loja* criarLoja() {
    Loja* loja = (Loja*)malloc(sizeof(Loja));
    loja->inicio = NULL;
    return loja;
}
void adicionarProdutoLoja(Loja* loja, Produto* produto) {
    produto->prox = loja->inicio;
    loja->inicio = produto;
}
void removerProdutoLoja(Loja* loja, int id) {
    Produto* anterior = NULL, * atual = loja->inicio;
    while (atual && atual->id != id) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return;

    if (anterior == NULL) loja->inicio = atual->prox;
    else anterior->prox = atual->prox;

    free(atual);
}
Produto* buscarProdutoLoja(Loja* loja, int id) {
    Produto* atual = loja->inicio;
    while (atual) {
        if (atual->id == id) return atual;
        atual = atual->prox;
    }
    return NULL;
}
void listarProdutosLoja(Loja* loja) {
    Produto* atual = loja->inicio;
    while (atual) {
        imprimirProduto(atual);
        atual = atual->prox;
    }
}
void liberarLoja(Loja* loja) {
    Produto* atual = loja->inicio;
    while (atual) {
        Produto* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(loja);
}