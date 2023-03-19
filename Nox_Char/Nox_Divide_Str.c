#include <string.h>
#include <stdlib.h>
#define TIMES 2

void init_array(char *arr, int lenght);

/**
* Nox_DivideStr - Divides a str in smaller sections of TIMES size
*
* Return: Alloc'd char*
*/
char *Nox_Divide_Str(char *a)
{
    int i, n, f, size = strlen(a);
    int arr_size = size * 2;
    char *arr = malloc(arr_size * sizeof(char) + 1);

    init_array(arr, arr_size);

    f = 0;
    for (i = 0; a[i]; )
    {
        for (n = 0; n < TIMES; n++)
        {
            arr[f] = a[i];
            i++;
            f++;
        }
        arr[f] = '*';
        f++;
    }

    printf("arr %s\n\n", arr);
    return (arr);
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
