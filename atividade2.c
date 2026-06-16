#include <stdio.h>

void aplicar_desconto(float *preco, float percentual) {
    *preco = *preco * (1.0 - percentual / 100.0);
}

int main() {
    float preco = 100.0;

    printf("Preço original:         R$ %.2f\n", preco);

    aplicar_desconto(&preco, 10.0);

    printf("Preço após 10%% de desconto: R$ %.2f\n", preco);

    return 0;
}
