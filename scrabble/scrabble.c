#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Calculates the score to an specific word
int score(string w1);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = score(word1);
    int score2 = score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

int score(string w1)
{
    int scorepoints = 0;
    for (int i = 0, n = strlen(w1); i < n; i++)
    {
        w1[i] = toupper(w1[i]);

        // Add one point if the letter is: A E I L N O R S T U
        if (w1[i] == 'A' || w1[i] == 'E' || w1[i] == 'I' || w1[i] == 'L' || w1[i] == 'N' || w1[i] == 'O' || w1[i] == 'R' ||
            w1[i] == 'S' || w1[i] == 'T' || w1[i] == 'U')
        {
            scorepoints += 1;
        }

        // Add two points if the letter is: D G
        else if (w1[i] == 'D' || w1[i] == 'G')
        {
            scorepoints += 2;
        }

        // Add three points if the letter is: B C M P
        else if (w1[i] == 'B' || w1[i] == 'C' || w1[i] == 'M' || w1[i] == 'P')
        {
            scorepoints += 3;
        }

        // Add four points if the letter is: F H V W Y
        else if (w1[i] == 'F' || w1[i] == 'H' || w1[i] == 'V' || w1[i] == 'W' || w1[i] == 'Y')
        {
            scorepoints += 4;
        }

        // Add five points if the letter is: K
        else if (w1[i] == 'K')
        {
            scorepoints += 5;
        }

        // Add eight points if the letter is: J X
        else if (w1[i] == 'J' || w1[i] == 'X')
        {
            scorepoints += 8;
        }

        // Add eight points if the letter is: J X
        else if (w1[i] == 'Q' || w1[i] == 'Z')
        {
            scorepoints += 8;
        }
    }
    return scorepoints;
}
