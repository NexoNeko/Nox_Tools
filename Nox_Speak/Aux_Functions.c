#include "main.h"

/**==================================*/
/**========= Aux functions ==========*/
/**==================================*/

/**
 * get_i_value - returns a value between 0 and 4
 *
 * Return: 0
 */
int get_i_value(void)
{
    int i;

    i = (mil() % 10);

	while (i > 4)
    {
        i = i >> 1;
        if (i < 0)
        {
            wait_mill(1, 2);
            i = (mil() % 10);
        }
    }
    wait_mill(1, 2);
    return(i);
}

/**
 * mil - returns current time in milliseconds
 *
 * Return: current time in milliseconds
 */
int mil(void)
{
	struct timespec spec;
	clock_gettime(CLOCK_REALTIME, &spec);
	return (spec.tv_sec * 1000 + ((spec.tv_nsec >> 20) + 1));
}

/**
 * wait_mill - waits a random time between min and max milliseconds
 *
 * @min_milliseconds: minimum time to wait
 * @max_milliseconds: maximum time to wait
 */
void wait_mill(int min_milliseconds, int max_milliseconds)
{
	int milliseconds;
	long nanoseconds;
	struct timespec delay_time = {0};

	srand(time(0));

	milliseconds = min_milliseconds + rand() % (max_milliseconds - min_milliseconds + 1);

	nanoseconds = milliseconds * 1000000;

	delay_time.tv_nsec = nanoseconds;

	nanosleep(&delay_time, NULL);
}

/**
 * init_array - Inits an array with null chars
 * @arr: array to init
 * @lenght: exact lenght of array
 *
 * Description: Warning, do NOT send NULL arrays.
 */
void init_array(char *arr, int lenght)
{
    int i = 0;

    while(i < lenght)
        arr[i++] = '\0';
}
