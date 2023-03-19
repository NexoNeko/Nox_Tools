/**
 * struct dog - stores a dog
 * @name: name of dog
 * @owner: owner of dog
 * @age: age of dog
 *
 */
typedef struct dog
{
	char *name;
	char *owner;
	float age;
} dog_t;


/**
 * init_dog - initializes a var of type dog
 *
 * @d: pointer to dog variable
 * @name: name of the dog
 * @age: age of the dog
 * @owner: whom owns the dog
 *
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (name == NULL || d == NULL || owner == NULL)
	{
		printf("Ok\n");
		exit(1);
	}
	d->name = name;
	d->owner = owner;
	d->age = age;
}


/**
 * print_dog - prints the values stored within a var of type dog
 *
 * @d: pointer to dog variable
 *
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		exit(1);

	if (d->name != NULL)
		printf("Name: %s\n", d->name);
	else
		printf("Name: (nil)\n");

	printf("Age: %f\n", d->age);

	if (d->owner != NULL)
		printf("Owner: %s\n", d->owner);
	else
		printf("Owner: (nil)\n");
}


/** rplce - allocates some memory and copies a string to said memory */
char *rplce(char *src);
/**
 * new_dog - creates a new dog record, allocated in heap.
 *
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: new dog record;
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dogz;

	dogz = malloc(sizeof(dog_t));
	if (dogz == NULL)
		return (NULL);


	dogz->name = rplce(name);
	if (dogz->name == NULL)
	{
		free(dogz);
		return (NULL);
	}
	dogz->owner = rplce(owner);
	if (dogz->owner == NULL)
	{
		free(dogz->name);
		free(dogz);
		return (NULL);
	}

	dogz->age = age;

	return (dogz);
}
/**
 * rplce - allocates some memory and copies a string to said memory
 *
 * @src: source string
 *
 * Return: Pointer to allocated memory
 */
char *rplce(char *src)
{
	int i;
	char *f;

	f = malloc(sizeof(src));

	if (f == NULL)
		return (NULL);

	for (i = 0; src[i]; i++)
		f[i] = src[i];
	f[i] = '\0';

	return (f);
}

/**
 * free_dog - frees heap memory from dog vars
 *
 * @d: dog record to free
 *
 * Return: new dog record;
 */
void free_dog(dog_t *d)
{
	if (d)
	{
	free(d->owner);
	free(d->name);
	free(d);
	}
}

