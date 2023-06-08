#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
    printf("%i\n", *(s + 3));
    //printf("%c\n", *(s + 100000)); só coloquei para ver o segmentation fault

    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
    printf("%i\n", s[3]);
}