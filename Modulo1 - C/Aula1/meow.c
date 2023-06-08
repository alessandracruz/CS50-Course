#include <stdio.h>

/* Abaixo alguns exemplos de loop para imprimir meow 3x na tela:

A primeira, usando FOR. A segunda, usando WHILE e a terceira, criando uma função auxiliar chamada meow.

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("meow\n");
    }
}

int main(void)
{
    int i = 0;

    while (i < 3)
    {
        printf("meow\n");
        i++;
    }
}
*/

/* Essa é a maneira com que a gente está acostumado a escrever: funções auxiliares primeiro e depois a main.
   Mas, não é a maneira correta para quem vai pegar o código e ler e só encontrar a main lá embaixo.
   Para corrigir isso, normalmente, os programadores citam a função auxiliar logo no início e entram com a main depois.

void meow(void)
{
    printf("meow\n");
}

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}
*/

void meow(void);

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}

void meow(void)
{
    printf("meow\n");
}
