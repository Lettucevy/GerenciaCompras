#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Produto.h"
#include "Loja.h"
#include "Carrinho.h"
#include "FilaPedidos.h"
#include "PilhaHistorico.h"

void menuPrincipal() {
    printf("\n==== MENU ====\n");
    printf("1. Adicionar produto à loja\n");
    printf("2. Remover produto da loja\n");
    printf("3. Listar produtos da loja\n");
    printf("4. Adicionar produto ao carrinho\n");
    printf("5. Remover produto do carrinho\n");
    printf("6. Listar carrinho\n");
    printf("7. Finalizar compra\n");
    printf("8. Ver histórico\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}
int main() {
    Loja* loja = criarLoja();
    Carrinho* carrinho = criarCarrinho();
    FilaPedidos* pedidos = criarFila();
    PilhaHistorico* historico = criarPilha();

    int opcao;
    do {
        menuPrincipal();
        scanf_s("%d", &opcao);
        getchar();

        switch (opcao) {
        case 1: {
            int id, quantidade;
            char nome[50];
            float preco;

            printf("ID do produto: ");
            scanf_s("%d", &id);
            getchar();

            printf("Nome do produto: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = 0;

            printf("Preço: R$ ");
            scanf_s("%f", &preco);

            printf("Quantidade em estoque: ");
            scanf_s("%d", &quantidade);

            Produto* p = criarProduto(id, nome, preco, quantidade);
            adicionarProdutoLoja(loja, p);

            char log[100];
            sprintf_s(log, sizeof(log), "Produto adicionado à loja: %s (ID %d)", nome, id);
            push(historico, log);
            break;
        }
        case 2: {
            int id;
            printf("ID do produto para remover da loja: ");
            scanf_s("%d", &id);

            removerProdutoLoja(loja, id);

            char log[100];
            sprintf_s(log, sizeof(log), "Produto removido da loja: ID %d", id);
            push(historico, log);
            break;
        }
        case 3:
            printf("\nProdutos disponíveis na loja:\n");
            listarProdutosLoja(loja);
            break;
        case 4: {
            int id;
            printf("ID do produto para adicionar ao carrinho: ");
            scanf_s("%d", &id);

            Produto* p = buscarProdutoLoja(loja, id);
            if (p && p->quantidadeDisponivel > 0) {
                if (adicionarProdutoComEstoque(carrinho, p)) {
                    printf("Produto adicionado ao carrinho!\n");
                    char log[100];
                    sprintf_s(log, sizeof(log), "Produto adicionado ao carrinho: %s (ID %d)", p->nome, p->id);
                    push(historico, log);
                }
            }
            else {
                printf("Produto indisponível ou não encontrado.\n");
            }
            break;
        }
        case 5: {
            int id;
            printf("ID do produto para remover do carrinho: ");
            scanf_s("%d", &id);
            removerProdutoCarrinho(carrinho, loja, id);

            char log[100];
            sprintf_s(log, sizeof(log), "Produto removido do carrinho: ID %d", id);
            push(historico, log);
            break;
        }
        case 6:
            printf("\nCarrinho:\n");
            listarCarrinho(carrinho);
            printf("Total: R$ %.2f\n", calcularTotal(carrinho));
            break;
        case 7:
            enfileirarPedido(pedidos, carrinho);
            carrinho = criarCarrinho();
            printf("Compra finalizada!\n");
            push(historico, "Compra finalizada e enviada para pedidos");
            break;
        case 8:
            printf("\nHistórico de ações:\n");
            imprimirHistorico(historico);
            break;
        case 0:
            printf("Encerrando...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    printf("\nProcessando pedidos pendentes...\n");
    processarPedidos(pedidos);

    liberarFila(pedidos);
    liberarPilha(historico);
    liberarCarrinho(carrinho);
    liberarLoja(loja);

    return 0;
}