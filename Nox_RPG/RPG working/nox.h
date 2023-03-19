#ifndef NOX_H_INCLUDED
#define NOX_H_INCLUDED

/**==================================*/
/**========= header files ===========*/
/**==================================*/
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#if defined(_WIN32) || defined(_WIN64)
	#include <windows.h>
#endif

/**==================================*/
/**========= macro defins ===========*/
/**==================================*/
#define MINUS(a) ((a) > 96 && (a) < 123 ? 1 : 0 )
#define MAXUS(a) ((a) > 64 && (a) < 91 ? 1 : 0 )

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

/** +++ +++ NOX_functions ++ +++ +++ */

/** this will print @wrds words of @siz size to stdout */
int Nox_Speak(int wrds, int siz);

/** this is the function call for the NOX function */
char *Nox_Speak_Glibberish(char *);

/** Randomizes shelves and saves it to the deck */
void Nox_Populate_shelves(char *deck);

/** Searches for a string, like strstr but different */
char *Nox_Strstr(char *haystack, char *needle, int siz);

/** --- --- NOX_functions --- --- --- */

#endif
