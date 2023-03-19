#include "main.h"

/**==================================*/
/**=== Aux_Functions_Rpg_Startup ====*/
/**==================================*/

/*
 * welcome - Prints the welcome screen
 */
void welcome(void)
{
	printf("        ,     \\    /      ,        \n");
	printf("       / \\    )\\__/(     / \\       \n");
	printf("      /   \\  (_\\  /_)   /   \\      \n");
	printf(" ____/_____\\__\\@  @/___/_____\\____ \n");
	printf("|             |\\../|              |\n");
	printf("|              \\VV/               |\n");
	printf("|        -----Nox_Rpg----         |\n");
	printf("|_________________________________|\n");
	printf(" |    /\\ /      \\\\       \\ /\\    | \n");
	printf(" |  /   V        ))       V   \\  | \n");
	printf(" |/     `       //        '     \\| \n");
	printf(" '              V                '\n");

	printf("              Welcome!\n\n");
}

/*
 * get_party_size - Gets size of party,
 *
 * Return: int size of party
 */
int get_party_size(void)
{
	int party_size;

	printf("Please input party size: ");
	scanf("%d", &party_size);
	if (party_size == 0)
		party_size = 1;
	printf("Party size set to %d!\n\n", party_size);

	return(party_size);
}

/**
 * hash_table_create - creates the hash table
 *
 * @size: size of the hash table
 *
 * Return: pointer to the newly created hash table
 */
p_hash_table *player_table_create(unsigned long int size)
{
	p_hash_table *p_index;

	p_index = malloc(sizeof(p_hash_table));
	if (!p_index)
	{
		fprintf(stderr, "Error 02, failed to allocate memory to heap");
		getchar();
		exit (1);
	}

	p_index->player = calloc(size, sizeof(p_character *));
	if (p_index->player)
	{
		p_index->size = size;
		return (p_index);
	}
	return (p_index);
}
