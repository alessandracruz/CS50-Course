#include <cs50.h>
#include <stdio.h>

/* exemplo de função truncada, caso o numerador seja menor do que o denominador
   para resolver: ou você muda o tipo das variáveis para float e usa get_float
   ou você casta o tipo da variável.

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    float z = x / y;

    printf("A divisão das variáveis é igual a: %f\n", z);
}
*/

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    float z = (float) x / (float) y;

    printf("A divisão das variáveis é igual a: %f\n", z);
}
