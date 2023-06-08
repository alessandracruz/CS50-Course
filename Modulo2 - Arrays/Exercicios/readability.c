#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int counter_letter = 0;
    int counter_words = 0;
    int counter_sentences = 0;
    string text = get_string("Digite um texto: ");
    int i = 0;

    while (i < strlen(text))
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
            counter_letter++;
        if (text[i] == ' ')
            counter_words++;
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            counter_sentences++;
        i++;
    }
    counter_words++;

    float L = (float) counter_letter * 100 / (float) counter_words;
    float S = (float) counter_sentences * 100 / (float) counter_words;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index >= 16)
        printf("Grade 16+\n");
    else
    {
        if (index <= 1)
            printf("Before Grade 1\n");
        else
            printf("Grade %i\n", (int)round(index));
    }
    return 0;
}
