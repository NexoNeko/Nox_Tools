#include <string.h>
#include <stddef.h>
/**
 * Nox_Strstr - finds a specific char sequence within a string, of size >= siz. Delimits the found word with a null char.
 *
 * @haystack: string
 * @needle: char sequence to look for in string
 * @siz: Minimum size for a match
 *
 * Return: Null if error, needle if found
 *
 * Description: This is an useful filter to catch words of X size
 * within a string. Originally this function was used to filter out
 * words from Nox_Speak, but I believe it might come-in handy for
 * other things.
 * WARNING: needle MUST be an array, last char of needle will get
 * turned into '\0'
 */
char *Nox_Strstr(char *haystack, char *needle, int siz)
{
		int i = 0, n = 0;

		if (needle[0] == '\0')
				return (NULL);
		for (i = 0; i < (int)strlen(haystack); i++)
		{
				while (haystack[i] == needle[n])
				{
						n++;
						i++;
						if (n >= siz && (needle[n] == '\n' || needle[n] == '\0'))
						{
								needle[n] = '\0';
								return(needle);
						}
				}
				if (n > 0)
						n = 0;
		}
		return (NULL);
}
