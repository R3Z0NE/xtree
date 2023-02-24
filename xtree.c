#include <stdio.h>
#include <errno.h>  // for errno
#include <limits.h> // for INT_MAX, INT_MIN
#include <stdlib.h> // for strtol

int main(int argc, char *argv[])
{

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

    else
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

            for (int k = 0; k < ((i - chars_amount) / 2); k++) // Empty characters after
            {
                printf(" ");
            }
            printf("\n"); // End of the line
        }
    }
}
