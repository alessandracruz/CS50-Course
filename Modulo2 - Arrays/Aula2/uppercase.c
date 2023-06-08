/* Programa para transformar em maiúscula as letras minúsuculas e, abaixo, usando a bibliteca
   para isso a ctype.h

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            printf("%c", s[i] - 32);
        else
            printf("%c", s[i]);
    }
    printf("\n");
}
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
       printf("%c", toupper(s[i]));
    }
    printf("\n");
}
