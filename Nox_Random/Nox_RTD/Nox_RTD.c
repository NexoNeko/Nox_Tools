#include "Nox_Random.c"

void Nox_Populate_shelves(char *deck);
char *Nox_Random(void);

/**
 * Nox_RTD - Rolls a dice of set size, it supports from 2 to 51 or 100 faces.
 *
 * Return: Int dice roll 1..51
 * Description: The 100 faced dice can be inaccurate
 */
int Nox_RTD(int size)
{
	char *seed = NULL;
	char size_group = 'A', roll_delimiter;
	int i = 0, arr_index = 0, size_total, Flag_Hundread = 0;
	int *arr = malloc(size * sizeof(int));

	if (!arr)
	{
		fprintf(stderr, "Error 01: Failed to allocate memory to heap");
		return(0);
	}
	if (size <= 1)
		size = 2;
	if (size == 100)
		Flag_Hundread = 1;
	if (size > 51)
		size = 51;

	size_total = 51 / size;

	seed = Nox_Random();

	arr[arr_index++] = (int)size_group;
	while (1)
	{
		for (i = 0; i < size_total; i++)
		{
			size_group++;
			if (size_group > 'Z' && size_group < 'a')
				size_group = 'a';
			if (size_group > 'z')
				break;
		}
		arr[arr_index] = (int)size_group;
		arr_index++;
		if ((arr_index + 1) == (size * 2))
			break;
	}
	roll_delimiter = Nox_Str_Get_Random(seed);

	for (i = 0; i < size; i++)
	{
		if (arr[i] >= roll_delimiter && roll_delimiter < arr[i + 1])
			break;
	}
	free(arr);

	if (Flag_Hundread == 1 && i > 25)
	{
		size_total = Nox_Str_Get_Random(seed);
		if (size_total % 2)
			i *= 2;
	}
	return(i);
}
