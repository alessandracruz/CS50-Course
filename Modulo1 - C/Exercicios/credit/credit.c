#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int long card = get_long("Digite o número do cartão: ");
    int count = 0;
    int check = 0;
    int result = 0;
    int long first;
    int long second;

    while (card > 0)
    {
        if (count % 2 == 0)
            result = result + (card % 10);
        else
        {
            check = (card % 10) * 2;
            if (check % 10 != 0 || check % 10 == 0)
                check = (check % 10) + (check / 10);
            result = result + check;
        }
        second = first;
        first = card;
        count++;
        card = card / 10;
    }
    if ((result % 10 == 0) && (first == 4 || first == 3 || first == 5))
    {
        if ((second == 34 || second == 37) && (count == 15))
            printf("AMEX\n");
        else
        {
            if ((second >= 51 && second <= 55) && (count == 16))
                printf("MASTERCARD\n");
            else
            {
                if ((first == 4) && (count == 13 || count == 16))
                    printf("VISA\n");
                else
                    printf("INVALID\n");
            }
        }
    }
    else
        printf("INVALID\n");
}