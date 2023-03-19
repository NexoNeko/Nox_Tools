#include "nox.h"

char *Nox_Random(void);
/**
 * main - entry point for the program
 *
 * Return: always 0;
 */
int main()
{
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
	char *rarities[] = {
		"Ornamental",
        "Ornamental",
        "Semiprecious",
        "Fancy",
        "Precious",
        "Gem"
    };
	/** These values vary depending on the rarity
		They are directly linked to it */
	int price_rarity[] = {10, 10, 50, 100, 500, 1000};
	int quantity_rarity[] = {10, 10, 8, 6, 4, 2};

	/** Actual vars that will be printed */
    int price, quantity, rarity, luck, item_material;

	while(1)
	{
		/** Rarity */
		rarity = Nox_RTD(5);
		printf("You got: ");
		
		/** roll lucky list */
		luck = Nox_RTD(12);
		
		/** If luck equals 12, rarity gets an extra*/
		if (luck <= 2 && rarity > 1)
			rarity--;
		if (luck == 12 && rarity < 5)
			rarity++;
		
		/** rarity holds the rarity of the gem, as such
			we can send the rarity to quantity rarity
			to figure out how many we need.
			So since quantity rarity gives us the max
			we send that to RTD to figure out how many
			we get*/
		quantity = Nox_RTD(quantity_rarity[rarity]);

		/** Calculate price based on rarity * quantity*/
		price = price_rarity[rarity] * quantity;

		/** Apply luck modifiers to price*/
		switch (luck)
		{
			case 3:
				price /= 2;
				break;
			case 4:
				price /= 1.5;
				break;
			case 10:
				price *= 1.5;
				break;
			case 11:
				price *= 2;
				break;
			default:
				break;
		}
		item_material = Nox_RTD(15);
		
		printf("%d ", quantity);

		if (rarity < 5)
			printf("%s ", rarities[rarity]);

		printf("%s ", material[item_material]);

		if (rarity >= 5)
			printf("%s", rarities[rarity]);
		putchar('\n');
		
		printf("Price: %d", price);
		putchar('\n');
		
		printf("Press ENTER to generate a new item");
		getchar();
	}

    return (0);
}
