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

    ptr = Nox_RTD(6);

	printf("ptr: %d", ptr);

    printf("\nThere we go, i'm done.\nPress any key to exit.");
    getchar();

    return (0);
}
