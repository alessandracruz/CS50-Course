#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        int n_key = strlen(key);

        if (n_key != 26)
        {
            printf("A chave deve conter 26 caracteres.\n");
            return (1);
        }
        char c[2][26];
        int i = 0;
        while (i < n_key)
        {
            c[0][i] = 'A' + i;
            c[1][i] = argv[1][i];
            i++;
        }
        i = 0;
        while (i < n_key)
        {
            int j = 0;
            int k = 0;
            while (k < n_key)
            {
                if (toupper(c[1][k]) == toupper(c[1][i]))
                    j++;
                if (j == 2)
                {
                    printf("Valor repetido, verificar a chave.\n");
                    return (1);
                }
                k++;
            }
            i++;
        }
        i = 0;
        while (i < strlen(key))
        {
            if (!isalpha(key[i]))
            {
                printf("Chave deve conter somente caracteres alfabéticos.\n");
                return (1);
            }
            i++;
        }
        if (strlen(key) == 26)
        {
            string text = get_string("plaintext: ");
            int n_text = strlen(text);

            printf("ciphertext: ");

            i = 0;
            while (i < n_text)
            {
                if (isalpha(text[i]))
                {
                    if (islower(text[i]))
                    {
                        int j = 0;
                        while (j < n_key)
                        {
                            if (tolower(c[0][j]) == text[i])
                                printf("%c", tolower(c[1][j]));
                            j++;
                        }
                    }
                    if (isupper(text[i]))
                    {
                        int j = 0;
                        while (j < n_key)
                        {
                            if (toupper(c[0][j]) == text[i])
                                printf("%c", toupper(c[1][j]));
                            j++;
                        }
                    }
                }
                else
                    printf("%c", text[i]);
                i++;
            }
            printf("\n");
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}