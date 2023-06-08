#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

/* Dá erro, mesmo que a gente digite strings iguais porque, da forma que o código está escrito, estamos
   comparando os endereços das strings e não o conteúdo delas.
    if (s == t)
        printf("Same\n");
    else
        printf("Different\n");
*/

    printf("%s\n", s);
    printf("%s\n", t);
    printf("%p\n", s);
    printf("%p\n", t);
}