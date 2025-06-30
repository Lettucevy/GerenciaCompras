#ifndef FILAPEDIDOS_H
#define FILAPEDIDOS_H

#include "Carrinho.h"

typedef struct Pedido {
    Carrinho* carrinho;
    struct Pedido* prox;
} Pedido;

typedef struct {
    Pedido* inicio;
    Pedido* fim;
} FilaPedidos;

FilaPedidos* criarFila();
void enfileirarPedido(FilaPedidos* f, Carrinho* c);
void processarPedidos(FilaPedidos* f);
void liberarFila(FilaPedidos* f);

#endif