#include <stdio.h>
#include <stdlib.h>
#include "FilaPedidos.h"

FilaPedidos * criarFila() {
    FilaPedidos* f = (FilaPedidos*)malloc(sizeof(FilaPedidos));
    f->inicio = f->fim = NULL;
    return f;
}
void enfileirarPedido(FilaPedidos* f, Carrinho* c) {
    Pedido* novo = (Pedido*)malloc(sizeof(Pedido));
    novo->carrinho = c;
    novo->prox = NULL;

    if (f->fim == NULL)
        f->inicio = f->fim = novo;
    else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}
void processarPedidos(FilaPedidos* f) {
    while (f->inicio) {
        Pedido* temp = f->inicio;
        printf("Processando Pedido (Total: R$ %.2f)\n", calcularTotal(temp->carrinho));
        listarCarrinho(temp->carrinho);
        liberarCarrinho(temp->carrinho);

        f->inicio = f->inicio->prox;
        free(temp);
    }
    f->fim = NULL;
}
void liberarFila(FilaPedidos* f) {
    while (f->inicio) {
        Pedido* temp = f->inicio;
        f->inicio = f->inicio->prox;
        free(temp);
    }
    free(f);
}