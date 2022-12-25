#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

/**==================================*/
/**========= header files ===========*/
/**==================================*/
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**==================================*/
/**========= macro defins ===========*/
/**==================================*/
#define MINUS(a) ((a) > 96 && (a) < 123 ? 1 : 0 )
#define MAXUS(a) ((a) > 64 && (a) < 91 ? 1 : 0 )

/**+++ randomizer defins +++ */
#define MAX_LINE_LENGTH 64
#define WORDS_TO_GENERATE 1
#define WORD_SIZE_INIT 2
#define WORD_SIZE_ADD 0

/**==================================*/
/**===== function signatures=========*/
/**==================================*/

/** +++ +++ Aux_functions ++ +++ +++ */

/** mil - returns a value in milliseconds */
int mil();

/** wait_mill - waits rand milliseconds */
void wait_mill(int min_milliseconds, int max_milliseconds);

/** get_i_value - returns a random value between 1 and 4 */
int get_i_value();

/** Inits an array with null chars */
void init_array(char *arr, int lenght);

/** --- --- Aux_functions --- --- --- */

/** +++ +++ Main_functions ++ +++ +++ */

/** this will print @wrds words of @siz size to stdout */
int Nox_Speak(int wrds, int siz);

/** this is the function call for the main function */
char *nox_random(char *);

/** Randomizes shelves and saves it to the deck */
void populate_shelves(char *deck);

/** Searches for a string, like strstr but different */
char *_strstr(char *haystack, char *needle, int siz);

/** --- --- Main_functions --- --- --- */

#endif
