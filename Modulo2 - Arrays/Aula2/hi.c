/* Maneira diferente de escrever (curiosa). Para ver que uma string = array de char e mostra o '\0'
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "HI!";

    printf("%c%c%c\n", s[0], s[1], s[2]);
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
}
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "HI!";

    printf("%s\n", s);
}