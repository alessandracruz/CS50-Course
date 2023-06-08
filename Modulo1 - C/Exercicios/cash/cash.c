#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int coin_25 = 0;
    int coin_10 = 0;
    int coin_5 = 0;
    int coin_1 = 0;

    float cash;
    do
    {
        cash = get_float("Quanto devo? ");
    }
    while (cash <= 0);

    int cents = round(cash * 100);

    coin_25 = cents / 25;
    coin_10 = ((cents - (coin_25 * 25)) / 10);
    coin_5 = ((cents - (coin_25 * 25) - (coin_10 * 10)) / 5);
    coin_1 = ((cents - (coin_25 * 25) - (coin_10 * 10)) - (coin_5 * 5));

    printf("Você utilizará %i moeda(s) no troco!\n", coin_25 + coin_10 + coin_5 + coin_1);
}