#include <stdio.h>
#include <errno.h>  // for errno
#include <limits.h> // for INT_MAX, INT_MIN
#include <stdlib.h> // for strtol

int main(int argc, char *argv[])
{
    // If none CLI argument are privided, these variables remain untouched
    long width = 21;      // Default width
    char character = 'x'; // default character

    long width = 10; // Default width: 10
    char base = argv[1][0]; // TODO: Default character
    errno = 0;
    char *p;

    if (argc == 3)
    {
        width = strtol(argv[2], &p, 10);
    }

    if (errno != 0 || *p != '\0' || width > 100 || width < 1)
    {
        printf("Error processing your 2nd CLI argument (width of the tree) (int).\n");
        printf("Enter value between 1-100.\n");
        return 1;
    }

    // Execute until number of characters to write is greater or equal to two-thirds of provided width
    // Each iteration increase numbers of characters to print by 2
    for (int chars_amount = 1; chars_amount <= width * 0.75; chars_amount += 2) // First part. Ends when width hits 75% of maximum value
    {

        // Execute until number of characters to write is greater or equal to provided width
        for (int i = width, chars_amount = 1; chars_amount <= width; chars_amount += 2)
        {
            for (int k = 0; k < ((i - chars_amount) / 2); k++) // Empty characters before
            {
                printf(" ");
            }

            for (int l = 0; l < chars_amount; l++) // Print out provided character 'chars_amount' times.
            {
                printf("%c", base);
            }

        for (int k = 0; k < ((width - chars_amount) / 2); k++) // Empty characters after
        {
            printf(" ");
        }
        printf("\n"); // Next line
    }

    for (int chars_amount = 1; chars_amount <= width; chars_amount += 2) // Same loop but full width this time, and 'skip' some of the first iterations using 'if' statement
    {
        if (chars_amount > width * 0.2) // Start drawing second part of the tree from 20% of the width
        {
            for (int k = 0; k < ((width - chars_amount) / 2); k++)
            {
                printf(" ");
            }

            for (int l = 0; l < chars_amount; l++)
            {
                printf("%c", character);
            }

            for (int k = 0; k < ((width - chars_amount) / 2); k++)
            {
                printf(" ");
            }
            printf("\n");
        }
    }

    for (int trunk = width / 10, chars_amount = trunk; trunk >= 0; trunk--) // Trunk length. Always at least one.
    {
        if (chars_amount % 2 == 0) // If trunk width would be an even number, add one for keeping symmetry
        {
            chars_amount++;
        }
        for (int k = 0; k < ((width - chars_amount) / 2); k++) // Empty characters before
        {
            printf(" ");
        }

        for (int r = 0; r < chars_amount; r++) // Trunk width
        {
            printf("%c", character);
        }

        for (int k = 0; k < ((width - chars_amount) / 2); k++) // Empty characters after
        {
            printf(" ");
        }
        printf("\n"); // Next line
    }
    return 0;
}