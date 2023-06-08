#include <stdio.h>
#include <cs50.h>

void draw(int h);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

//fazeno o mesmo código de maneira recursiva, precisamos tomar cuidado para não dar overflow de memória
// proque estamos chamando a função dentro do código de maneira recursiva e pode dar segmentation Fault.
// Para que isso não ocorra é importante colocar a condição if (h == 0) return.
void draw(int h)
{
    if (h == 0)
        return;

    draw(h - 1);

    for (int i = 0; i < h; i++)
    {
        printf("#");
    }
    printf("\n");
}