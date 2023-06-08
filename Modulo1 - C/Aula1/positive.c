//Abstrações

#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

int main(void)
{
    int i = get_positive_int();
    printf("%i\n", i);
}

// do while -> um loop while que verifica a condição primeiro e depois faz alguma coisa

int get_positive_int(void)
{
    int n;
    
    do
    {
        n = get_int("Positive Interger: ");
    }
    while (n < 1);
    return (n);
}