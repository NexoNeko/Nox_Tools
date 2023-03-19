#include "main.h"
#include "nox.h"
/**
 * main - entry point for the program
 *
 * Return: always 0;
 */
int main()
{
    int i;
	int party_size;
	p_hash_table *p_index;

	welcome();
	i = Nox_RTD(6);
	party_size = get_party_size();

	/** set up the hash table for the players */
	p_index = player_table_create(party_size);

	/** Bring the player naming screen */
	party_set(p_index, party_size);

	return (0);
}

void party_set(p_hash_table *p_index, int party_size)
{
	int i = 0;
	int hp, dex;
	char pc_name[64], choice[1];

	printf("Time to name your player characters!\n\n");
	printf("Type AUTONAME and ill name them for you if you get tired!\n");
	printf("(I havent actually finish that feature yet)\n");
	while (i < party_size)
	{
		i++;
		for (; 1;)
		{
			printf("What's party member's %d name?\n", i);
			fflush(stdin);
			scanf("%s", pc_name);
			printf("party member's %d name: \"%s\"!\n\n", i, pc_name);
			printf("What's %s's dexterity?\n", pc_name);
			fflush(stdin);
			scanf("%d", &dex);
			printf("%s's dexterity: %d\n", pc_name, dex);
			printf("Please wait...\n");
			hp = Nox_RTD(6);
			printf("%s's hit points: %d\n\n", pc_name, hp);
			printf("\n\n-------------------\n\n");
			printf("party member's %d name: \"%s\" ", i, pc_name);
			printf("dexterity: %d\n", dex);
			printf("\nIs this correct? Y/N\n\n");
			fflush(stdin);
			scanf("%s", choice);
			if (choice[0] == 'y' || choice[0] == 'Y')
			{
				if (player_table_push(p_index, (char *)pc_name, hp, dex) == 4)
				{
					printf("error");
				}
				else
					break;
			}
		}
	}
}

int player_table_push(p_hash_table *p_index, char *name, int hp, int dex)
{
	unsigned long int p_id = 0;
	p_character *new_player, *existing_player;
	const unsigned char *new_name = (unsigned char *)name;

	/** Generate a new player id */
	p_id = player_index_new(new_name, p_index->size);

	/** Check if player already exists */
	existing_player = p_index->player[p_id];
	if (existing_player && strcmp(existing_player->name, name) == 0)
	{
		printf("\nError! player %s already exists!\n\n", name);
		return(4);
	}
	else
	{
		/** Create new PlayerCharacter */
		new_player = malloc(sizeof(p_character));
		if (!new_player)
		{
			fprintf(stderr, "Error 03: Failed to allocat memory to heap");
			return(-1);
		}
		new_player->name = strdup(name);
		new_player->hp = hp;
		new_player->dex = dex;

		/** If there's no player at given index,index new player here*/
		if (!p_index->player[p_id])
		{
			p_index->player[p_id] = new_player;
			new_player->next = NULL;
			printf("\nPlayer %s created!\n\n", new_player->name);
			getchar();
			return(0);
		}
		/** Otherwise, if there IS a player at this index, add the new player before him */
		new_player->next = existing_player;
		p_index->player[p_id] = new_player;
	}
	return (0);
}

