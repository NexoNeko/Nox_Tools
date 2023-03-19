/**
 * hash_table_create - creates the hash table
 *
 * @size: size of the hash table
 *
 * Return: pointer to the newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;

	table = malloc(sizeof(hash_table_t));
	if (!table)
		return (NULL);

	table->array = calloc(size, sizeof(hash_node_t *));
	if (table->array)
	{
		table->size = size;
		return (table);
	}
	return (NULL);
}

/**
 * key_index - gives you the index of a key
 *
 * @key: value to hash
 * @size: size of the array to store
 * Return: index of key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int nuKy = hash_djb2(key);

	return (nuKy % size);
}

/**
 * hash_table_set - inserts a value on a hash table
 *
 * @key: key for index
 * @value: value to store
 * @ht: node of a hash table to operate on
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx = 0;
	hash_node_t *nuNode, *olNode;
	const unsigned char *newKey = (unsigned char *)key;

	if (!ht || !key)
		return (0);

	idx = key_index(newKey, ht->size);

	olNode = ht->array[idx];

	if (olNode && strcmp(olNode->key, key) == 0)
		olNode->value = strdup(value);
	else
	{
		nuNode = malloc(sizeof(hash_node_t));
		if (!nuNode)
			return (0);

		nuNode->key = strdup(key);
		nuNode->value = strdup(value);

		if (!ht->array[idx])
		{
			ht->array[idx] = nuNode;
			nuNode->next = NULL;
			return (1);
		}
		nuNode->next = olNode;
		ht->array[idx] = nuNode;
	}
	return (1);
}

/**
 * hash_table_get - get a value of a key
 *
 * @ht: hash table to operate on
 * @key: key for index
 * Return: value or NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned int index = 0;
	const unsigned char *newKey = (unsigned char *)key;
	hash_node_t *crrNde = NULL;

	if (!ht || !key)
		return (NULL);

	index = key_index(newKey, ht->size);
	crrNde = ht->array[index];

	while (crrNde)
	{
		if (strcmp(crrNde->key, key) == 0)
		{
			return (crrNde->value);
		}
		crrNde = crrNde->next;
	}

	return (NULL);
}

/**
 * hash_table_print - print out the hash table.
 * @ht: hash table to read from.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx, i;
	hash_node_t *node;

	idx = i = 0;
	if (!ht)
		exit(-1);

	printf("{");

	while (idx < ht->size)
	{
		node = ht->array[idx];
		while (node)
		{
			printf("\'%s\': \'%s\'", node->key, node->value);

			if (node->next)
				printf(", ");
			node = node->next;
		}

		while (!(ht->array[idx + 1]))
			idx++;

		if (i && idx < ht->size)
			printf(", ");
		else
			i = 1;
		idx++;
	}
	printf("}\n");
}

/**
 * hash_table_delete - delete table
 * @ht: pointer to hash table
 *
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned int i = 0;
	hash_node_t *node = NULL, *nexNode = NULL;

	while (i < ht->size)
	{
		node = ht->array[i];
		while (node)
		{
			nexNode = node->next;
			free(node->value);
			free(node->key);
			free(node);
			node = nexNode;
		}
		i++;
	}
	free(ht->array);
	free(ht);
}

