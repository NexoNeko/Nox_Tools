//**
* fun_sort - sorts an array of ints
*
* @array: array to sort
* @size: size of the array to sort
* 
*/
void insert_sort(int *array, int size)
{
	int j, i, key;

	for (j = 1; j < size; j++)
	{
		key = array[j];
		i = (j - 1);
		while (i > -1 && array[i] > key)
		{
			array[i + 1] = array[i];
			i--;
		}
		array[i + 1] = key;
	}
}
