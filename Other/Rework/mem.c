/**
 * _memset - fill memory with a constant byte
 *
 * @s: pointer to memory to be filled
 * @b: constant byte/character to fill memory with
 * @n: N of bytes of memory to fill with b
 *
 * Return: char
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;
	char *c = s;

	while (i < n)
	{
		*s++ = b;
		i++;
	}
	return (c);
}

/**
 * _memcpy - copy n bytes from memory address 1 to memory address 2
 *
 * @dest: The destiny memory address for the new bytes
 * @src: Source address, where to get the bytes from
 * @n: The num of bytes to copy.
 *
 * Return: char
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;
	char *c = dest;

	while (i < n)
	{
		*dest++ = *src++;
		i++;
	}
	return (c);
}

