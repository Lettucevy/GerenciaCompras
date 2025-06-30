#ifndef LOJA_H
#define LOJA_H

#include "Produto.h"

typedef struct {
    Produto* inicio;
} Loja;

Loja* criarLoja();
void adicionarProdutoLoja(Loja* loja, Produto* produto);
void removerProdutoLoja(Loja* loja, int id);
Produto* buscarProdutoLoja(Loja* loja, int id);
void listarProdutosLoja(Loja* loja);
void liberarLoja(Loja* loja);

#endif