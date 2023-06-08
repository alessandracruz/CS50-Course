#include <stdio.h>

int main(void)
{
    //print 10 hashes
    for (int i = 0; i <= 10; i++)
    {
        //printf para debugar o código. Estava i <= 10, então imprimia 11 hashs e não 10
        //o printf ajuda a ver o problema e ajudar.
       // printf("i is now %i\n", i);
        printf("#\n");
    }
}