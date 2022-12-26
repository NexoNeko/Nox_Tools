#ifndef NOX_H_INCLUDED
#define NOX_H_INCLUDED

/**==================================*/
/**========= header files ===========*/
/**==================================*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

/** this is the function call for the NOX function */
char *Nox_Random();

/** Randomizes shelves and saves it to the deck */
void Nox_Populate_shelves(char *deck);

/** --- --- NOX_functions --- --- --- */

#endif 
