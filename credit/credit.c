#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num = get_long("Number: ");
    long control = num;
    long luhn = 0;
    int c = 0;
    int sum = 0;
    int firstdigits;

    while (control > 0)
    {

        // Change digit
        if (c > 0)
        {
            control = control / 10;
        }

        if (c % 2 == 0) // Do the second step
        {
            sum += control % 10;
        }
        else
        {                                           // Do the first step
            luhn += ((control % 10) * 2) % 10;      // Takes the second digit
            luhn += ((control % 10) * 2) / 10 % 10; // Takes the first digit
        }

        if (control <= 99 && control > 9) // Takes the two first digits
        {
            firstdigits = control;
        }
        c++;
    }

    luhn += sum;
    c--;

    if (luhn % 10 == 0)
    {
        if (c == 15 && (firstdigits == 34 || firstdigits == 37)) // Verify if is American Express
        {
            printf("AMEX\n");
        }

        else if (c == 16 && (firstdigits >= 51 && firstdigits <= 55)) // Verify if is MasterCard
        {
            printf("MASTERCARD\n");
        }

        else if (c == 13 || (c == 16 && (firstdigits / 10 % 10) == 4)) // Verify VISA
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
