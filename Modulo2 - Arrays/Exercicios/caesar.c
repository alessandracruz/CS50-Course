#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2 && isdigit(argv[1][0]))
    {
        int key = 0;
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            key = (key * 10) + (argv[1][i] - '0');
        }

        if (key < 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        string text = get_string("plaintext: ");

        int n = strlen(text);

        int i = 0;
        while (i < n)
        {
            if (isalpha(text[i]))
            {
                if (isupper(text[i]))
                    text[i] = ((text[i] - 'A' + key) % 26) + 'A';
                else
                    text[i] = ((text[i] - 'a' + key) % 26) + 'a';
            }
            i++;
        }
        printf("ciphertext: %s\n", text);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}