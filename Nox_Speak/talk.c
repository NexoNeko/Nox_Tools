#include "main.h"

int talk(int wrds, int siz) {
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

        for (j = 1; j; ) {
		word = nox_random(deck);
		init_array(line, MAX_LINE_LENGTH);
		rewind(file);

                while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
			truth = _strstr(word, line, siz);
                        if (truth) {
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
 * _strstr - finds a specific char sequence within a string
 *
 * @haystack: string containing desired character sequence
 * @needle: desired character sequence to look for
 *
 * Return: haystack + i || needle
 */
char *_strstr(char *haystack, char *needle, int siz)
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
