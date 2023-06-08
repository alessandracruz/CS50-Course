#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Altura: ");
    }
    while(h < 1 || h > 8);

    int i = 0;
    while (i < h)
    {
        int j = 0;
        while (j < h)
        {
            if ((i + j) < (h - 1))
                printf(" ");
            else
                printf("#");
            j++;
        }
        printf("  ");
        int k = 0;
        while (k < h)
        {
            if ((i + k) >= (h - 1))
                printf("#");
            k++;
        }
        printf("\n");
        i++;
    }
}
