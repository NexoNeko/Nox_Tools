#include "nox.h"

char *Nox_Random(void);
/**
 * main - entry point for the program
 *
 * Return: always 0;
 */
int main()
{
	char *modifiers[] = {
		"Ornamental",
        "Ornamental",
        "Semiprecious",
        "Fancy",
        "Precious",
        "Gem"
    };
    char *material[] = {
	"Chlorastrolite",
    "Chlorastrolite",
    "Malachite",
    "Aventurine",
    "Rhodonite",
    "Amethyst",
    "Fluorospar",
    "Garnet",
    "Alexandrite",
    "Topaz",
    "Heliotrope",
    "Sapphire",
    "Diamond",
    "Fire Opal",
    "Ruby",
    "Emerald"
    };

    int price, D5, D5A, D12, Gem;

    
    printf("You got: ");
	
	/** Quantity */
	D12 = Nox_RTD(12);
	printf("%d ", D12);
	
	/** Quality n Material */
	D5 = Nox_RTD(5);
	D5A = Nox_RTD(5);
	if (D5 < 5)
	{
		printf("%s %s", modifiers[D5], material[D5A]);
	}
	else
	{
		printf("%s %s", material[D5A], modifiers[D5]);
	}

    getchar();

    return (0);
}
