#include <stdio.h>
#include <cs50.h>

int main(void)
{   //creating a variable to store the height value
    int h;
    do
    {
        h = get_int("Altura: ");
    }
    while (h < 1 || h > 8);

    int i = 0;
    //checking if the counter of rows is smaller than the input height
    while (i < h)
    {
        int j = 0;
        //checking if the number of columns is less than the input height
        while (j < h)
        {
            //checking if the sum of rows and columns is less than the row number minus the input height
            if (i + j < h - 1)
                printf(" ");
            else
                printf("#");
            j++;
        }
        printf("\n");
        i++;
    }
}
/*
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (i + j < h - 1)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}
*/


