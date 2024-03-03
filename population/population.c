#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int population, end_size;

    do
    {
        population = get_int("Start size: ");
    }
    while (population < 9);

    // TODO: Prompt for end size
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < population);

    // TODO: Calculate number of years until we reach threshold

    int n = 0;

    while (population < end_size)
    {
        int bornThatYear = population / 3;
        int passedThatYear = population / 4;

        population += bornThatYear;
        population -= passedThatYear;
        n++;
    }

    printf("Years: %i", n);
    // TODO: Print number of years
}
