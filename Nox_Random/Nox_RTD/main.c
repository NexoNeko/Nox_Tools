#include "nox.h"

int Nox_RTD(int size);

int main()
{
	int i, n;

	printf("hello world");

	for (n = 0; n < 10; n++)
	{
		i = Nox_RTD(6);
		printf("%d\n", i);
	}

	return(0);
}
