#include <stdio.h>
#include <stdlib.h>
#include "nox.h"
int get_i_value(void);

/**
 * Nox_Str_Get_Random - Returns a random char from a string
 *
 * @string: String to get value from
 *
 * Description: Warning, do NOT send NULL strings.
 */
char Nox_Str_Get_Random(char *string)
{
  int string_length = 0, random_index = 0, i = 0;
  char random_char = 'A';

  srand((unsigned) time(NULL));
  string_length = strlen(string) / sizeof(char);
  random_index = rand() % string_length;
  random_index += get_i_value();
  if (random_index > string_length)
    random_index--;
  random_char = string[random_index];
  /** */
  printf("%c\n", random_char);

  i = (int)random_char;
  if (i = 0)
    random_char = Nox_Str_Get_Random(string);

  return (random_char);
}
