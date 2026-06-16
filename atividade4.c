#include <stdio.h>

typedef struct {
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual) {
    produto->preco = produto->preco * (1.0 - percentual / 100.0);
}

void imprimir_produtos(Produto *ptr, int quantidade) {
    printf("%-5s %-20s %s\n", "ID", "Produto", "Preço");
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
    Produto estoque[3] = {
        {1, 49.90},
        {2, 129.99},
        {3, 19.50}
    };

    printf("=== Estoque Original ===\n");
    imprimir_produtos(estoque, 3);

    aplicar_desconto(&estoque[1], 10.0);

    printf("\n=== Após 10%% de desconto no Produto #2 ===\n");
    imprimir_produtos(estoque, 3);

    return 0;
}
