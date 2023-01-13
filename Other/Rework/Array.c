/**
 * print_array - Prints N elements of an array of integers
 *
 * @a: The array to be printed
 * @n: The number of integers to be printed
 *
 * Return: void
 */
void print_array(int *array, int size)
{
	int i, size_max;

	size_max = size;
	size -= 1;
	if (size < 0)
		putchar('\n');
	else
	for (i = 0; size > -1; size--)
	{
		Nox_Putint(array[i]);
		i++;
		if (i < size_max)
			printf(", ");
		else
			putchar('\n');
	}
}

/**
 * array_iterator - executes a function as a parameter on evry x elmnt on array
 *
 * @array: pointer to an array
 * @size: size of the array
 * @action: pointer to a function
 *
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i = 0;

	if (size > 0 && action != NULL && array != NULL)
	{
		do {
			action(array[i]);
		} while (++i < size);
	}
}

/**
 * create_array - creates an array of char, size 'size' and initializes it
 *
 * @size: desired size for the array
 * @c: the char to initialize the array with
 *
 * Return: Pointer
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i = 0;
	char *ar;

	ar = malloc(size * sizeof(char));
	if (size < 1)
		return (NULL);
	if (ar == NULL)
		return (ar);
	while (i < size)
	{
		ar[i] = c;
		i++;
	}
	return (ar);
}

/**
 * array_range - creates an array of MAX size, containing min..max values.
 *
 * @min: the starting value
 * @max: the max value
 * Return: pointer to newly assigned array
 */
int *array_range(int min, int max)
{
	int i = 0, c;
	int *ar = NULL;

	if (min > max)
		return (NULL);

	c = (max - min) + 1;
	ar = calloc(c, sizeof(int));
	if (!ar)
		return (NULL);

	while (i < c)
	{
		ar[i] = min;
		i++;
		min++;
	}
	return (ar);
}

/**
 * reverse_array - reverses an array of integers
 *
 * @a: array to be reversed
 * @n: size of the array
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i, temp;

	i = 0;
	for (i = 0; i < (n / 2); i++)
	{
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}


/**
 * print_array - Prints N elements of an array of integers
 *
 * @a: The array to be printed
 * @n: The number of integers to be printed
 *
 * Return: void
 */
void print_array(int *a, int n)
{
	int i, m;

	m = n;
	n -= 1;
	if (n < 1)
		printf("\n");
	else
	for (i = 0; n > -1; n--)
	{
		printf("%d", a[i]);
		i++;
		if (i < m)
			printf(", ");
		else
			putchar('\n');
	}
}

