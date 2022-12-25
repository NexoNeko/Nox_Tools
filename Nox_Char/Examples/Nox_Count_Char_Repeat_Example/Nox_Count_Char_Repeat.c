#include <string.h>
#include <stdlib.h>
/**
 * Nox_Count_Char_Repeat - Counts the repeating characters in a string
 *
 * @a: String of ascii characters (0 to 127)
 *
 * Return: int array containing values from 1 to 127
 *
 * Description: This function uses malloc, to use it
 * assign a pointer to the return of this function.
 * Make sure to free the pointer after use.
 */
int *Nox_Count_Char_Repeat(char *a) {
    int *cnt = malloc(128 * sizeof(int));
    int i, size = strlen(a);
    char *arr = malloc(size * sizeof(int));

    for (i = 0; i < 128; i++)
        cnt[i] = 0;

    strcpy(arr, a);
    while(*a++)
        for (i = 0; i < size; i++)
            if (*a == arr[i])
                cnt[(int)arr[i]]++;
    free(arr);
    return (cnt);
}
