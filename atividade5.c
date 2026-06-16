#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual) {
    produto->preco = produto->preco * (1.0 - percentual / 100.0);
}

void imprimir_produtos(Produto *ptr, int quantidade) {
    printf("%-5s %-20s %s\n", "ID", "Produto", "Preco");
    printf("----------------------------------\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%-5d Produto #%-11d R$ %.2f\n",
               (ptr + i)->id,
               (ptr + i)->id,
               (ptr + i)->preco);
    }
    printf("----------------------------------\n");
}

int main() {
    int quantidade;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &quantidade);

    Produto *estoque = (Produto *) malloc(quantidade * sizeof(Produto));

    if (estoque == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return 1;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Produto %d ---\n", i + 1);
        printf("ID:    ");
        scanf("%d", &(estoque + i)->id);
        printf("Preco: ");
        scanf("%f", &(estoque + i)->preco);
    }

    printf("\n=== Estoque Cadastrado ===\n");
    imprimir_produtos(estoque, quantidade);

    aplicar_desconto(estoque, 10.0);

    printf("\n=== Apos 10%% de desconto no Produto #1 ===\n");
    imprimir_produtos(estoque, quantidade);

    free(estoque);
    printf("\nMemoria liberada com sucesso.\n");

    return 0;
}
