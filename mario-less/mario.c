#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    int pos;
    for (int c1 = 1; c1 <= n; c1++)
    {
        pos = n;
        for (int c2 = 0; c2 < n; c2++)
        {
            if (pos > c1)
            {
                printf(" ");
            }

            else
            {
                printf("#");
            }

            pos--;
        }
        printf("\n");
    }
}
