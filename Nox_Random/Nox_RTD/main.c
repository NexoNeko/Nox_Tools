#include "nox.h"
#include <time.h>
char *Nox_Random(void);
/**
 * main - entry point for the program
 *
 * Return: always 0;
 */
int main()
{
    int ptr;
    int i;

    while(1)
    {
        ptr = Nox_RTD(100);

        printf("ptr: %d", ptr);

        printf("\nPress ENTER to Roll The Dice (1d100)");
        getchar();
    }

    return (0);
}
