/* Exemplo para mostrar a imprecisão do retorno da função quando colocamos mais inputs do que a memória do computador suporta.
   Quando fazemos x = 1 e y = 10 o retorno é: 0.10000 com a precisão normal do tipo float.
   Mas quando colocamos x = 1 e y = 10 e pedimos um retorno de f com 50 casas decimais, começamos a ter uma imprecisão no retorno.
   O que significa que não existe capacidade de memória suficiente para retornar tanta precisão que estamos pedindo no input.
   Foi o que aconteceu no bug do milênio em janeiro de 2000.E o mundo está prestes a viver isso de novo em 19 de jan de 2038...
   Vai faltar bits novamente para acompanhar o tempo! Começamos a contar o tempo em segundos no mundo da computação em 1 jan de 1970.
   Com 32 bits, você só pode contar até 4 Bilhõese iremos atingir o quarto bilionésimo de segundo em 19 de jan de 2038.
   Então, ao menos que todos nós atualizemos nossos computadores, sistemas, satélite icorporados e qualquer hardware do dispositivos,
   estamos prestes a nos depararmos com esse problema, onde será novamente com 1 de janeiro de 1970 novamente.
   Por isso a gente precisa estar à frente desse problema! Assim, com todo o poder da linguagem C e toda sua capacidade, ainda existem
   limitações fundamentais. Por isso, precisamos sempre estar atentos à limitações do hardware.
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float x = get_float("x: ");
    float y = get_float("y: ");

    printf("%.50f\n", x / y);
}