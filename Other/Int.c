/** Operate */
#define efe(OP, a, b) ((a) OP (b))

/** Get size of an array data type */
#define num(x) (sizeof (x) / sizeof (*x))





/**
 * swap_int - Swaps int a for int b
 *
 * @a: &array[index] || &pointer (untested)
 * @b: &array[index] || &pointer (untested)
 *
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int c;

	c = *b;
	*b = *a;
	*a = c;
}


void Nox_Putint(int number)
{
	int iterator, digit_count = 1, digit_value, counter, negative_flag;

	/** If number is negative, make it positive and print a '-' sign */
	if (number < 0)
	{
		number /= -1;
		number -= 1;
		negative_flag = 1;
		putchar('-');
	}

	/** Determine the number of digits in number */
	iterator = number;
	for (; iterator > 9;)
	{
		iterator /= 10;
		digit_count += 1;
	}
	/** If just one number, print and exit*/
	if (digit_count == 1)
	{
		putchar(number + 48);
		return;
	}
	/** Print each digit of number, starting with the most significant digit */
	while (digit_count > 0)
	{
		/** digit_value will be used to store the value of the current digit */
		digit_value = 1;

		/** Calculate the value of digit_value as 10^(digit_count-1)*/
		for (counter = 1; counter != digit_count; counter++)
			digit_value *= 10;

		/** If we are printing the last digit and number was originally negative, -
		 we need to increment iterator to compensate for the fact that we made number positive earlier */
		if (digit_count == 1 && negative_flag == 1)
			iterator++;

		putchar(iterator + 48);
		
		/** Remove the current digit from number by subtracting it from the remaining part of number */
		number = number - (iterator * digit_value);

		/** Decrement digit_count to move on to the next digit */
		digit_count -= 1;

		/** Calculate the number of digits in the remaining part of number */
		iterator = number;
		counter = 1;
		for (; iterator > 9;)
		{
			iterator /= 10;
			counter++;
		}

		/** If there are more digits to print than there are digits in the remaining part of number,
		 we need to print a leading 0 */
		if (digit_count > counter)
		{
			putchar('0');
			digit_count--;
		}
	}
}

/**
 * getSize - Gets the lenght of a given integer
 *
 * @num: integer to find lenght of
 *
 * Return: Int
 */
int get_size(long int num)
{
	int i = 0;

	if (num == 0)
		i = 1;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}


/**
 * main - prints the 50 first nums of the fibonacci sequence
 *
 * Return: 0
 */
int main(void)
{
	int i;
	unsigned long n, a = 0, b = 1;

	n = a + b;
	for (i = 0; i < 49; i++)
	{
		printf("%lu, ", n);
		a = b;
		b = n;
		n = a + b;
	}
	printf("%lu\n", n);
	return (0);
}

/**
 * sum_them_all - sums all the parameters sent to the function
 *
 * @n: number of ints to be passed to the function
 *
 * Return: int sum
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i, sum;
	va_list holds;

	if (n == 0)
		return (0);

	va_start(holds, n);
	sum = 0;

	for (i = 0; i < n; i++)
		sum += va_arg(holds, int);

	va_end(holds);
	return (sum);
}

/**
 * main - prints every combination of two digits from 1 to 99 without repeats.
 *
 * Return: 0
 */
int main(void)
{
	int i, ten, dig, a, ntn;

	for (i = 1; i < 100; i++)
	{
		dig = i / 10;
		ten = dig * 10;
		ntn = ten + 10;

		if (i > ten + dig && i < ntn)
		{
			a = i / 10 + 48;
			putchar(a);
			a = i % 10 + 48;
			putchar(a);
			if ((i / 10) == 8)
			{
				putchar('\n');
				return (0);
			}
			putchar(',');
			putchar(' ');
		}
	}
	return (0);
}

/**
 * main - prints 1 to 999 w/o repeats
 *
 * Return: 0
 */
int main(void)
{
	int i, ten, dig, a, ntn, mul, mod = 0, c = 0;

	for (; c <= 7; c++)
	{
		for (i = 12; i < 100; i++)
		{
			dig = i / 10;
			ten = dig * 10;
			ntn = ten + 10;
			if (i > ten + dig && i < ntn)
			{
				if (c > 0 && i < 22)
					i += 11;
				if (c > 1)
				{
					i = i + mod;
					mod = 0;
				}
				putchar(c + 48);
				a = i / 10 + 48;
				putchar(a);
				putchar((i % 10) + 48);
				if (c == 7 && (i / 10) == 8)
				{
					putchar('\n');
					return (0);
				}
				putchar(',');
				putchar(' ');
			}
		}
		mod = mul;
		mul += 11;
	}
	return (0);
}

