/**
 * binary_to_uint - converts a binary value to unsigned int
 *
 * @b: The binary value to convert
 *
 * Return: Decimal value if succesful, 0 if not
 */
unsigned int binary_to_uint(const char *b)
{
	int i = 0, base = 1;
	unsigned int dec = 0;

	if (!b)
		return (0);
	while (b[i + 1])
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		i++;
	}
	while (i >= 0)
	{
		dec += (b[i] - 48) * base;
		base *= 2;
		i--;
	}
	return (dec);
}

/**
 * print_binary - prints the binary equivalent of a decimal
 *
 * @n: decimal to convert
 *
 */
void print_binary(unsigned long int n)
{
	int c = 0, k = 0;
	unsigned long int temp = n;

	if (n == 0)
		putchar('0');
	while (temp != 0)
	{
		temp = temp >> 1;
		c++;
	}
	for (c--; c >= 0; c--)
	{
		k = n >> c;
		if (k & 1)
			putchar('1');
		else
			putchar('0');
	}
}

/**
 * get_bit - prints the bit at the given possition
 *
 * @n: Decimal value
 * @index: index of the bit to get
 *
 * Return: bit value if success, -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int temp, c = 0;

	if (n == 0)
		return (0);
	while (temp != 0)
	{
		temp = temp >> 1;
		c++;
	}
	if (index <= c)
	{
		temp = (n >> index) & 1;
		if ((temp == 1) || (temp == 0))
			return (temp);
		else
			return (-1);
	}
	else
		return (-1);
}

/**
 * set_bit - sets the bit at index to 1
 *
 * @n: decimal to convert
 * @index: index of bit to flip
 *
 * Return: 1 on success, -1 on failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int temp, c = 0;

	if (n == NULL)
		return (-1);

	temp = *n;
	while (temp != 0)
	{
		temp = temp >> 1;
		c++;
	}
	if (index > 64)
		return (-1);

	temp = 1 << index;
	*n |= temp;
	return (1);
}

/**
 * clear_bit - sets the bit to 0 at given index
 *
 * @n: decimal to convert
 * @index: index of bit to clear
 *
 * Return: 1 on success, -1 on failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int temp, c = 0;

	if (n == NULL)
		return (-1);

	temp = *n;
	if (index > 64)
		return (-1);

	temp = 1 << index;
	if ((temp | *n) == *n)
		*n = *n ^ temp;
	return (1);
}

/**
 * flip_bits - counts the num of bits youd need to flip to get from n to i
 *
 * @n: num that will be flipped
 * @m: Desired number
 *
 * Return: num of flips
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;

	while (n != 0 || m != 0)
	{
		if ((n & 1) != (m & 1))
			count++;
		m = m >> 1;
		n = n >> 1;
	}
	return (count);
}