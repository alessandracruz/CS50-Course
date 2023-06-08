#include <cs50.h>
#include <stdio.h>

int get_negative_int(void);

int main(void)
{
    int i = get_negative_int();
    printf("%i\n", i);
}

int get_negative_int(void)
{
    int n;
    do
    {
        n = get_int("Negatuve Interger: ");
    }
    //para rodar o debug e vô-lo funcionando a condição anterior inserida para o while foi while (n < 0)
    //depois que o debug rodou, vimos o erro e ajustamos a condição do loop
    while (n >= 0);
    return (n);
}