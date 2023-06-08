/* Testando maneiras diferentes de expressar alguma coisa na tela
int main(void)
{
    char c = '#';
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%c%c%c%c\n", c, c1, c2, c3);
    printf("%i%i%i%i\n", c, c1, c2, c3);
}
*/

#include <stdio.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%i %i %i\n", c1, c2, c3);
}