#ifndef CARRINHO_H
#define CARRINHO_H

#include "Produto.h"

typedef struct Carrinho {
    Produto* inicio;
} Carrinho;

Carrinho* criarCarrinho();
void adicionarProduto(Carrinho* c, Produto* p);
void removerProduto(Carrinho* c, int id);
void listarCarrinho(const Carrinho* c);
void liberarCarrinho(Carrinho* c);
float calcularTotal(const Carrinho* c);

#endif