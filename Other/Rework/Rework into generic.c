typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

/**
 * get_op_func - it's basically a fancy switch
 *
 * @s: the char passed to the function
 *
 * Return: (X)(int, int) function
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
		};
	int i = 0;

	while (i < 5)
	{
		if (*(ops[i].op) == *s)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}





