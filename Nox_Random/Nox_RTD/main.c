#include "nox.h"
#include <time.h>
char *Nox_Random(void);
int Nox_RTD(int);
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

        printf("Roll: %d", ptr);

        getchar();
      }

    return (0);
}
