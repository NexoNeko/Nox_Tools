#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

/**==================================*/
/**============ structs =============*/
/**==================================*/

typedef struct Player_Character
{
	char *name;
	int hp;
	int dex;
	struct Player_Character *next;
} p_character;

typedef struct p_hash_table_s
{
	unsigned long int size;
	p_character **player;
} p_hash_table;


/**==================================*/
/**========= header files ===========*/
/**==================================*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#if defined(_WIN32) || defined(_WIN64)
	#include <windows.h>
#endif

/**==================================*/
/**===== function signatures=========*/
/**==================================*/

/** +++ +++ Aux_Functions_Rpg_Startup ++ +++ */

/** Prints the welcome screen */
void welcome(void);

/** Gets size of party */
int get_party_size(void);

/** Allocate memory for every player character */
p_hash_table *player_table_create(unsigned long int size);

/** Get info on player characters before storing them */
void party_set(p_hash_table *p_index, int party_size);

/** Index a new player in the player table */
int player_table_push(p_hash_table *p_index, char *name, int hp, int dex);

/** --- --- Aux_Functions_Rpg_Startup -- --- */


/** +++ +++ Aux_Party_functions ++ +++ +++ */

/** djb2 hash function */
unsigned long int hash_djb2(const unsigned char *str);

/** gives you the index of a player */
unsigned long int player_index_new(const unsigned char *key, unsigned long int size);

/** --- --- Aux_Party_functions --- --- --- */


/** +++ +++ Rand_functions ++ +++ +++ */

/** Rolls a dice from 1 to 51 or 100 with less accuracy */
int Nox_RTD(int size);

/** this is the function call for the main function */
char *nox_random();

/** Randomizes shelves and saves it to the deck */
void populate_shelves(char *deck);

/** --- --- Rand_functions --- --- --- */

/** +++ +++ NOX_functions ++ +++ +++ */

/** Returns a random value from a string */
char Nox_Str_Get_Random(char *string);

/** Searches for a string, like strstr but different */
char *Nox_Strstr(char *haystack, char *needle, int siz);

/** this will print @wrds words of @siz size to stdout */
int Nox_Speak(int wrds, int siz);

/** this is the function call for the NOX function */
char *Nox_Speak_Glibberish(char *);

/** Randomizes shelves and saves it to the deck */
void Nox_Populate_shelves(char *deck);

/** --- --- NOX_functions --- --- --- */
#endif



