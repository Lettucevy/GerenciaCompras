#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Produto.h"

Produto* criarProduto(int id, const char* nome, float preco, int quantidade) {
    Produto* novo = (Produto*)malloc(sizeof(Produto));
    novo->id = id;
    strcpy_s(novo->nome, sizeof(novo->nome), nome);
    novo->preco = preco;
    novo->quantidadeDisponivel = quantidade;
    novo->prox = NULL;
    return novo;
}
void imprimirProduto(const Produto* p) {
    printf("ID: %d | Nome: %s | Preço: R$ %.2f | Estoque: %d\n",
        p->id, p->nome, p->preco, p->quantidadeDisponivel);
}