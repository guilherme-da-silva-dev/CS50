#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int letter = 0;
    int sentences = 0;
    int words = 1;

    string text = get_string("Text: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        text[i] = toupper(text[i]);

        // Verify the number of letters
        if (text[i] >= 65 && text[i] <= 90)
        {
            letter++;
        }

        // Verify the number of words
        if (text[i] == 32)
        {
            words++;
        }

        // Verify the number of sentences (. == 46 | ! = 33 | ? = 63)
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }

    // calculate index
    double L = ((double) letter / words) * 100;
    double S = ((double) sentences / words) * 100;
    double index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
