#include <stdio.h>
#include <stdlib.h>

/**
 * Nox_Str_Get_Random - Returns a random char from a string
 *
 * @string: String to get value from
 *
 * Description: Warning, do NOT send NULL strings.
 */
char Nox_Str_Get_Random(char *string)
{
    int string_length, random_index;
    char random_char;

    srand((unsigned) time(NULL));
    string_length = strlen(string) / sizeof(char);
    random_index = rand() % string_length;
    random_char = string[random_index];

    return (random_char);
}
