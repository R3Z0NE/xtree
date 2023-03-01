#include <stdio.h>
#include <errno.h>  // for errno
#include <limits.h> // for INT_MAX, INT_MIN
#include <stdlib.h> // for strtol

int main(int argc, char *argv[])
{
    // If none CLI argument are privided, these variables remain untouched
    long width = 21;      // Default width
    char character = 'x'; // default character

    if (argc >= 3) // If 'character' and 'width' CLI arguments are specified
    {
        errno = 0;
        char *p;
        width = strtol(argv[2], &p, 10); // Convert second CLI argument to long and store it as width

        if (errno != 0 || *p != '\0' || width > 200 || width < 1)
        {
            printf("Error processing your 2nd CLI argument (width of the tree) (int).\n");
            printf("Enter value between 1-200.\n");
            return 1;
        }
    }

    if (argc >= 2) // If at least 'character' CLI argument is specified
    {
        character = argv[1][0]; // Store first character of CLI argument as character to create tree with
    }

    // Execute until number of characters to write is greater or equal to two-thirds of provided width
    // Each iteration increase numbers of characters to print by 2
    for (int chars_amount = 1; chars_amount <= width * 0.75; chars_amount += 2) // First part. Ends when width hits 75% of maximum value
    {
        for (int k = 0; k < ((width - chars_amount) / 2); k++) // Empty characters before
        {
            printf(" ");
        }

        for (int l = 0; l < chars_amount; l++) // Print out provided character 'chars_amount' times
        {
            printf("%c", character);
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