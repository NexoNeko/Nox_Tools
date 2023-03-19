#include "main.h"

/**
 * hash_djb2 - implementation of the djb2 algorithm
 * @str: string used to generate hash value
 *
 * Return: hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}

/**
 * key_index - gives you the index of a key
 *
 * @key: value to hash
 * @size: size of the array to store
 * Return: index of key
 */
unsigned long int player_index_new(const unsigned char *key, unsigned long int size)
{
	unsigned long int nuKy = hash_djb2(key);

	return (nuKy % size);
}
