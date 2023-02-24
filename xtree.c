#include <stdio.h>
#include <errno.h>  // for errno
#include <limits.h> // for INT_MAX, INT_MIN
#include <stdlib.h> // for strtol

int main(int argc, char *argv[])
{
    // If none CLI argument are privided, these variables remain untouched
    long width = 20;      // Default width
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

    // Execute until number of characters to write is greater or equal to provided width
    // Each iteration increase numbers of characters to print by 2
    for (int chars_amount = 1; chars_amount <= width; chars_amount += 2)
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
        printf("\n"); // End of the line
    }
    return 0;
}