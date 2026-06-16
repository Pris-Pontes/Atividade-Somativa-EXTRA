#include <stdio.h>

int main() {
    float preco = 100.0;
    float *ptr = &preco;

    printf("Preço original: R$ %.2f\n", preco);

    *ptr = *ptr * 1.10;

    printf("Preço após aumento de 10%%: R$ %.2f\n", preco);

    return 0;
}
