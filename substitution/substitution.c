#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argv[2] != 0)
    {
        printf("Too many arguments for key!\n");
        return 1;
    }

    // Verify if the argument isn't empty
    if (argc == 1)
    {
        printf("You must type an argument to execute the program!\n");
        return 1;
    }

    string key = argv[1];

    // Verify if you type 26 letters
    if (strlen(key) != 26)
    {
        printf("Your key must have 26 letters!\n");
        return 1;
    }

    // Verify if you type only unique letters
    for (int i = 0; i < 26; i++)
    {
        // If the letter fits into A-Z
        if (toupper(key[i]) < 65 || toupper(key[i]) > 90)
        {
            printf("You must insert only letters!\n");
            return 1;
        }

        // Verify if the letter has already been typed somewhere
        for (int c = 0, n = strlen(key); c < n; c++)
        {
            if (key[c] == key[i] && c != i)
            {
                printf("You must type only unique letters!\n");
                return 1;
            }
        }
    }

    // Collect message
    int index = 0;
    string message = get_string("plaintext:  ");

    // Build Cypher Text
    printf("ciphertext: ");
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        index = (int) toupper(message[i]) - 65;
        if (isupper(message[i]))
        {
            printf("%c", toupper(key[index]));
        }
        else if (islower(message[i]))
        {
            printf("%c", tolower(key[index]));
        }
        else
        {
            printf("%c", message[i]);
        }
    }

    printf("\n");
    return 0;
}
