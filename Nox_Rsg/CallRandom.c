#include "main.h"

/**
 * nox_random - This is the function caller, also sets deck initial state
 *
 * Return: String of 51 characters
 */
char *Nox_Random(void)
{
    char *randptr = malloc(53 * sizeof(char));
    int j, n = 4, i = 0, dt = 51, db = 0;
    char deck[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                    'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
                    'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                    'y', 'z'};
    char temp[52];

    if (!randptr)
    {
        perror("Can't alloc memory to heap, error ");
        printf("Press any key to exit");
        getchar();
        exit(0);
    }

    for (i = 0; i < 4; i++)
    {
        populate_shelves(deck);
    }
    init_array(randptr, 53);
    temp[dt] = '\0';
    dt--;

    for (n = 0; n < 4; n++)
    {
	    dt = 51;
	    db = 0;
	    for (j = 0; j < 4; j++)
	    {
		    i = get_i_value();
		    if (i % 2)
			    for (i = 0; i < 13; i++)
			    {
				    temp[db] = deck[db];
				    db++;
			    }
		    else
			    for (i = 0; i < 13; i++)
			    {
				    temp[dt] = deck[dt];
				    dt--;
			    }
	    }
	    for(i = 0; i < 51 && n < 4; i++)
		    deck[i] = temp[i];
    }

    for(i = 0; i < 51; i++)
        randptr[i] = temp[i];


    return(randptr);
}
