#include <stdio.h>

typedef struct {
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual) {
    produto->preco = produto->preco * (1.0 - percentual / 100.0);
}

int main() {
    Produto p1 = {1, 100.0};

    printf("Produto ID: %d\n", p1.id);
    printf("Preço original:             R$ %.2f\n", p1.preco);

    aplicar_desconto(&p1, 10.0);

    printf("Preço após 10%% de desconto: R$ %.2f\n", p1.preco);

    return 0;
}
