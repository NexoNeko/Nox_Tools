
/**
 * _strdup - copies a string to heap and returns a pointer to it.
 *
 * @str: string to be copied
 *
 * Return: Pointer to new *str
 */
char *_strdup(char *str)
{
	int i = 0;
	char *a = NULL;

	if (str == NULL)
		return (a);

	while (str[i])
		i++;

	a = malloc((i * sizeof(char)) + 1);

	if (a == NULL)
		return (a);

	i = 0;

	do {
		a[i] = str[i];
	} while (str[i++]);

	a[++i] = '\0';
	return (a);
}

/**
 * str_concat - Concatenates two strings, returns pointer to it, malloc
 *
 * @s1: string to the very left on the concatenation
 * @s2: string to the very right on the concatenation
 *
 * Return: Pointer to new *str
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0, ia = 0, c = 0;
	char *a = NULL;

	if (s1 == NULL && s2 == NULL)
	{
		a = malloc(2 * sizeof(char));
		return (a);
	}
	if (s1 != NULL)
		while (s1[i])
			i++;
	if (s2 != NULL)
		while (s2[ia])
			ia++;
	c = (i + ia) + 1;
	a = malloc(c * sizeof(char));
	if (!a)
		return (a);

	if (i != 0)
	{
		i = 0;
		do {
			a[i] = s1[i];
		} while (s1[i++]);
		i--;
	}
	if (ia != 0)
	{
		ia = 0;
		do {
			a[i] = s2[ia];
			i++;
		} while (s2[ia++]);
	}
	return (a);
}

/**
 * alloc_grid - Returns a pointer to a 2d array initialized with zeros
 *
 * @width: Width of the array
 * @height: Height of the array
 *
 * Return: Pointer to new *str
 */
int **alloc_grid(int width, int height)
{
	int w, h;
	int **a = NULL;

	if (width < 1 || height < 1)
		return (NULL);

	a = malloc(height * sizeof(int *));
	if (!a)
		return (NULL);

	for (w = 0; w < height; w++)
	{
		a[w] = malloc(width * sizeof(int));
		if (!a[w])
		{
			while (w > 0)
				free(a[--w]);
			free(a);
			a = NULL;
			return (a);
		}
	}
	for (h = 0; h < height; h++)
		for (w = w; w < width; w++)
			a[h][w] = 0;
	return (a);
}

/**
 * free_grid - frees memory previously allocated by alloc_grid
 *
 * @grid: The array to be freed
 * @height: Height of the array
 *
 * Return: Void.
 */
void free_grid(int **grid, int height)
{
	while (height > 0)
		free(grid[--height]);
	free(grid);
}


/**
 * string_nconcat - concatenates n bytes of s2 at the end of s1, null termntd
 *
 * @s1: Base string
 * @s2: String to concatenate at the end
 * @n: Num of bytes to concatenate at end of s1
 *
 * Return: pointer to newly concatenated string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0, ia = 0, c = 0;
	char *a = NULL;

	if (s1 == NULL && s2 == NULL)
	{
		a = calloc(2, sizeof(char));
		return (a);
	}
	if (s1 != NULL)
		while (s1[i])
			i++;
	if (s2 != NULL)
		while (s2[ia] && ia < n)
			ia++;
	c = (i + ia) + 1;
	a = calloc(c, sizeof(char));
	if (!a)
		return (NULL);
	if (i != 0)
	{
		i = 0;
		do {
			a[i] = s1[i];
		} while (s1[i++]);
		i--;
	}
	if (ia != 0)
	{
		ia = 0;
		do {
			a[i] = s2[ia];
			i++;
		} while (s2[ia++] && ia < n);
	}
	return (a);
}

/**
 * _strcat - concatenates two strings
 *
 * @dest: String to be expanded
 * @src: text to be pasted into previous string
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int i, c;
	char *a;

	c = -1;
	for (i = 0; dest[i] != '\0'; i++)
		;
	while (src[++c])
	{
		dest[i] = src[c];
		i++;
	}
	a = dest;
	return (a);
}

/**
 * _strncat - concatenates two strings, n size
 *
 * @dest: String to be expanded
 * @src: text to be pasted into previous string
 * @n: number of bytes to be copied
 *
 * Return: void
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, c, b;
	char *a;

	c = b = 0;
	for (i = 0; dest[i] != '\0'; i++)
		;
	for (c = 0; src[c] != '\0'; c++)
		;
	if (n > c)
		n = c;
	c = 0;
	while (b < n)
	{
		dest[i] = src[c];
		c++;
		i++;
		b++;
	}
	a = dest;
	return (a);
}

/**
 * _strchr - finds a character in a string
 *
 * @s: String where we look for the character
 * @c: character to look for
 *
 * Return: pointer to character or NULL
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i++])
	{
		if (s[i] == c)
		{
			return (s + i);
		}
	}
	return (NULL);
}

/**
 * _strlen - Returns lenght of a string
 *
 * @s: String to be evaluated
 *
 * Return: i
 */
int _strlen(char *s)
{
	int i = 0;

	for (; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strncpy - copies n chars from src to dest
 *
 * @dest: String to be expanded
 * @src: text to be pasted into previous string
 * @n: number of bytes to be copied
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, c;
	char *a;

	i = c = 0;
	while (src[c++])
		;
	while (i < n)
	{
		if (i < c)
			dest[i] = src[i];
		else
			dest[i] = '\0';
		i++;
	}
	a = dest;
	return (a);
}

/**
 * _puts - Prints a whole string, w/o \0
 *
 * @c: character to be printed
 *
 * Return: void
 */
int _putchar(char c);
void _puts(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}

/**
 * _strcmp - compares two strings
 *
 * @s1: String1
 * @s2: String2
 *
 * Return: i
 */
int _strcmp(char *s1, char *s2)
{
	int i, s1Max, s2Max, n;

	i = s1Max = s2Max = n = 0;
	while (s1[i++])
		;
	while (s2[n++])
		;
	i -= 1;
	n -= 1;

	if (i < n)
		n = i;
	i = 0;

	while (i  < n)
	{
		s1Max += s1[i];
		s2Max += s2[i];
		i++;
	}
	if (s1Max > s2Max)
		return (13);
	else if (s1Max < s2Max)
		return (-13);
	else
		return (0);
}

/**
 * print_rev - reverses a string and prints it
 *
 * @c: character to be printed
 *
 * Return: void
 */
void print_rev(char *s)
{
	int i, c;

	c = i = 0;
	for (; s[i] != '\0'; i++)
		c++;
	c -= 1;
	for (; c > -1; c--)
		putchar(s[c]);
	putchar('\n');
}

/**
 * rev_string - Reverses a string
 *
 * @s: String to be reversed
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i, c;
	char temp;

	c = i = 0;
	while (s[i++])
		c++;
	for (i = 0; i < (c / 2); i++)
	{
		temp = s[i];
		s[i] = s[c - i - 1];
		s[c - i - 1] = temp;
	}
}

/**
 * string_toupper - lowercase to uppercase
 *
 * @p: String to be converted
 *
 * Return: p
 */
char *string_toupper(char *p)
{
	int i;

	for (i = 0; p[i] != '\0'; i++)
	{
		if (p[i] > 96 && p[i] < 123)
		{
			p[i] -= 32;
		}
	}
	return (p);
}

/**
 * cap_string - Capitalizes words on a given string
 *
 * @p: String to capitalize
 *
 * Return: p
 */
char *cap_string(char *p)
{
	char c[14] = {9, 10, 32, 33, 34, 40, 41, 44, 59, 46, 63, 123, 125};
	int i, n;

	i = n = 0;
	if (p[n] > 96 && p[n] < 123)
		p[n] -= 32;
	for (n = 0; p[n] != '\0'; n++)
	{
		i = 0;
		for (; c[i] != '\0'; )
		{
			if (p[n] == c[i])
			{
				n++;
				if (p[n] < 96)
				{
					n++;
					if (p[n] > 96 && p[n] < 123)
						p[n] -= 32;
				}
				else if (p[n] > 96 && p[n] < 123)
					p[n] -= 32;
			}
			i++;
		}
	}
	return (p);
}

/**
 * puts2 - 12345678 >> 1357
 *
 * @c: char printed
 *
 * Return: void
 */
void puts2(char *str)
{
	int i, c;

	c = i = 0;
	for (; str[i] != '\0'; i++)
		c++;
	if (c < 100)
	c -= 1;
	for (i = 0; c > -1; c--)
	{
		if ((c % 2) == 1)
			putchar(str[i]);
		i++;
	}
	putchar('\n');
}

/**
 * puts_half - splits a string in half
 *
 * @c: char to be printed
 *
 * Return: void
 */
int _putchar(char c);
void puts_half(char *str)
{
	int i, c;

	c = i = 0;
	for (; str[i] != '\0'; i++)
		c++;
	c -= 1;
	if ((c % 2))
		c = (c - 1) / 2;
	else
		c = c / 2;
	for (i = (c + 1); c > -1; c--)
	{
		if (str[i] != '\0')
			_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

/**
 * _strcpy - Copies the contents of a string to another string
 *
 * @src: Characters will be copied FROM this string
 * @dest: Characters will be copied TO this string.
 *
 * Return: void
 */
char *_strcpy(char *dest, char *src)
{
	int i, c;
	char *a;

	c = i = 0;
	for (; src[i] != '\0'; i++)
		c++;
	for (i = 0; c > -1; c--)
	{
		dest[i] = src[i];
		i++;
	}
	a = dest;
	return (a);
}

