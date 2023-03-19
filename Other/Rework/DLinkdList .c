/** make these generic */

/**
 * print_dlistint - Prints all the values inside a linked list
 *
 * @h: Head of list to print
 *
 * Return: num of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int i = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		i++;
		h = h->next;
	}
	return (i);
}

/**
 * delete_dnodeint_at_index - deletes the node at the specific index
 *
 * @head: List to go through
 * @index: Nth of index in which to add the new node
 *
 * Return: Address of new node, -1 it fails.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;

	if (!head)
		return (-1);
	if (head)
	{
		while (index && temp)
		{
			temp = temp->next;
			index--;
		}
		if (index)
			return (-1);
		if (!index && temp)
		{
			if (temp->next)
				temp->next->prev = temp->prev;
			if (temp->prev)
				temp->prev->next = temp->next;
			else
				*head = temp->next;
			free(temp);
			return (1);
		}
	}
	return (-1);
}

/**
 * insert_dnodeint_at_index - insterts a new node at the given index
 *
 * @h: List to go through
 * @idx: Nth of index in which to add the new node
 * @n: Information to store
 *
 * Return: Address of new node, NULL if it fails.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *nuNode, *temp;

	if (h == NULL)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;
	while (idx > 1 && temp && temp->next)
	{
		temp = temp->next;
		idx--;
	}

	nuNode = malloc(sizeof(dlistint_t));
	if (nuNode == NULL)
		return (NULL);
	if (idx > 1 || temp == NULL)
		return (NULL);

	nuNode->n = n;

	if (temp->next != NULL)
		temp->next->prev = nuNode;
	nuNode->prev = temp;
	nuNode->next = temp->next;
	temp->next = nuNode;

	return (nuNode);
}


/**
 *  sum_dlistint - sums all the values contained wtihin each node in a list
 *
 * @head: - The linked list to go through
 *
 * Return: Sumof all nums
 */
int sum_dlistint(dlistint_t *head)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		i += head->n;
		head = head->next;
	}
	return (i);
}


/**
 * get_dnodeint_at_index -  returns the nth node of a listint_t linked list.
 *
 * @head: - The linked list to go through
 * @index: - the index num desired
 *
 * Return: pointer to node if found, else,NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}
	return (NULL);
}


/**
 * free_dlistint - frees a dlist
 *
 * @head: list to free
 */
void free_dlistint(dlistint_t *head)
{
	if (head)
		free_dlistint(head->next);
	free(head);
}


/**
 * add_dnodeint_end - adds a node to the end of the list
 *
 * @head: Pointer to the list
 * @n: Information to be contained
 *
 * Return: pointer to last node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *nuNode = malloc(sizeof(dlistint_t));
	dlistint_t *temp;

	temp = *head;
	if (*head)
		while (temp->next != NULL)
			temp = temp->next;
	if (!nuNode)
	{
		free(nuNode);
		return (nuNode);
	}
	else
	{
		nuNode->n = n;
		nuNode->next = NULL;
	}
	if (!temp)
		*head = nuNode;
	else
	{
		temp->next = nuNode;
		nuNode->prev = temp;
	}
	return (nuNode);
}


/**
 * dlistint_len - Prints all the values inside a linked list
 *
 * @h: Head of list to print
 *
 * Return: num of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int i = 0;

	while (h != NULL)
	{
		i++;
		h = h->next;
	}
	return (i);
}

