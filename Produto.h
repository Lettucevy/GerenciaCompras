#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto {
    int id;
    char nome[50];
    float preco;
    int quantidadeDisponivel;
    struct Produto* prox;
} Produto;

Produto* criarProduto(int id, const char* nome, float preco, int quantidade);
void imprimirProduto(const Produto* p);

#endif