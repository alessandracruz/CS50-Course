#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    if (x < y)
    {
        printf("x é menor do que y!\n");
    }
    else if (x > y)
    {
        printf("x é maior do que y!\n");
    }
    else
        printf("x é igual a y!\n");
}