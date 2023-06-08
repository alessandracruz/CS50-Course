#include <stdio.h>

int main(void)
{
    int n = 50;
    //printf("%i\n", *&n); é o mesmo que escrever printf("%i\n, n)
    printf("%p\n", &n);
}

