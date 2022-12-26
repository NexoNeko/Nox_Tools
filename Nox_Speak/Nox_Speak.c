#include "nox.h"
#include <string.h>

/**+++ randomizer defins +++ */
#define MAX_LINE_LENGTH 64
#define WORDS_TO_GENERATE 1
#define WORD_SIZE_INIT 2
#define WORD_SIZE_ADD 0

char *Nox_Strstr(char *haystack, char *needle, int siz);

/**
 * Nox_Speak - Prints a random word to stdout
 *
 * @wrds: amount of words to generate
 * @siz: Size of each word
 *
 * Return always 0
 */
int Nox_Speak(int wrds, int siz) 
{
		int j;
		char *word;
	char *truth;
		char line[MAX_LINE_LENGTH];
		FILE* file = fopen("words", "r");
	char deck[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
					'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
					'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd',
					'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
					'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
					'y', 'z'};

	if (wrds == 0)
		return(0);
	if (siz < 2)
		siz = WORD_SIZE_INIT;
	for (j = 1; j; )
	{
		word = Nox_Speak_Glibberish(deck);
		init_array(line, MAX_LINE_LENGTH);
		rewind(file);
		while (fgets(line, MAX_LINE_LENGTH, file) != NULL) 
		{
			truth = Nox_Strstr(word, line, siz);
			if (truth) 
			{
				printf("%s", truth);
				siz += WORD_SIZE_ADD;
				if (wrds == WORDS_TO_GENERATE)
				{
					free(word);
					fclose(file);
					return(0);
				}
				else
					wrds++;
			}
		}
	free(word);
	}
return 0;
}


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