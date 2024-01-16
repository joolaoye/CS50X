#include <cs50.h>
#include <stdio.h>
int main(void)
{

    int size;
    do
    {
        size = get_int("input size: ");
    }


    while (size < 1 || size > 8);


    int row, column;
    for (row = 0; row < size; row += 1)
    {

        for (column = 0; column < size; column += 1)
        {
            if (row + column < size - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }

        }

        printf("  ");

        for (column = 0; column <= row; column += 1)
        {
            printf("#");
        }
        printf("\n");
    }
}