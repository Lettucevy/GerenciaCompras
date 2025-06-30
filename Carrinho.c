#include <stdio.h>
#include <stdlib.h>
#include "Loja.h"
#include "Carrinho.h"

Carrinho* criarCarrinho() {
    Carrinho* c = (Carrinho*)malloc(sizeof(Carrinho));
    c->inicio = NULL;
    return c;
}

int adicionarProdutoComEstoque(Carrinho* c, Produto* p) {
    if (p->quantidadeDisponivel <= 0) return 0;

    Produto* novo = criarProduto(p->id, p->nome, p->preco, 1);
    novo->prox = c->inicio;
    c->inicio = novo;
    p->quantidadeDisponivel--;
    return 1;
}
void removerProdutoCarrinho(Carrinho* c, Loja* loja, int id) {
    Produto* anterior = NULL, * atual = c->inicio;

    while (atual && atual->id != id) {
        anterior = atual;
        atual = atual->prox;
    }
    if (!atual) return;

    if (anterior) anterior->prox = atual->prox;
    else c->inicio = atual->prox;

    Produto* estoque = buscarProdutoLoja(loja, id);
    if (estoque) estoque->quantidadeDisponivel++;

    free(atual);
}
void listarCarrinho(const Carrinho* c) {
    Produto* atual = c->inicio;
    while (atual) {
        printf("ID: %d | %s | R$ %.2f\n", atual->id, atual->nome, atual->preco);
        atual = atual->prox;
    }
}
float calcularTotal(const Carrinho* c) {
    float total = 0;
    Produto* atual = c->inicio;
    while (atual) {
        total += atual->preco;
        atual = atual->prox;
    }
    return total;
}
void liberarCarrinho(Carrinho* c) {
    Produto* atual = c->inicio;
    while (atual) {
        Produto* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(c);
}