/*Podemos escrever assim, variável por variável ou na forma de array como representado mais abaixo.

int main(void)
{
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    printf("Average: %f\n", ((score1 + score2 + score3) / 3.0));
}

int main <stdio.h>
{
    int scores[3];
    scores[0] = 72;
    scores[1] = 73;
    scores[2] = 33;
}

Dessa forma abaixo, está correto, mas ainda não está com um design bacana! Pode melhorar!

#include <stdio.h>
#include <cs50.h>

int mai(void)
{
    int scores[3];
    scores[0] = get_int("Score: ");
    scores[1] = get_int("Score: ");
    scores[2] = get_int("Score: ");

    printf("Average: %f\n", ((score[0] + score[1] + score[2]) / 3.0));
}
*/

#include <stdio.h>
#include <cs50.h>

float average(int lenght, int array[]);

const int TOTAL = 3;

int main(void)
{
    int scores[TOTAL];
    for (int i = 0; i < TOTAL; i++)
    {
        scores[i] = get_int("Scores: ");
    }

    printf("Average: %f\n", average(TOTAL, scores));
}

float average(int lenght, int array[])
{
    int sum = 0;
    for (int i = 0; i < lenght; i++)
    {
        sum = sum + array[i];
    }
    return (sum / (float) lenght);
}