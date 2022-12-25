#include <stdio.h>
#include <stdlib.h>

int *Nox_Count_Char_Repeat(char *string);

/**
 * main - Example main, string of 1050 characters
 *
 * Return: always 0
 * Description: Btw this wont compile under ISO C90 because strings over 509
 * characters arent allowed.
 */
int main()
{
    int *a, i;
    char *longstream =
    "NBKTeEAGzZAtfzVMLYvNJBIIiKCpdirDbhKsJzkDYaslVbRrIBpueuwHcoJgFHSIvsywFwbWmetNlNPKqKssuBGzGsonMLjwOPfqdKarnKBPzlrohIFTzoBloDtItQdZsyztWPIOKBMeQIbcmgFHGqptaEwwvwhCtXIwTjQdLMRISaYrFwgJQJwLiOmySUclJeRaxVBXCEvzidIydsaZXKBpSpDeLKJfoSINWNYbieSnajLQBkUSGFhLjEbKfIRxRIWZNFPjruWzLQgSHXPbLttReyWKlqyLyinxfHKjPyMoVWmpLyCNhDITabVFqBgzJpArNufQDpKSsWdmCPuESelqiOMynuZfmGihPxkwtsDuyBtiqNlJLuSiFyWhZOryyiiQeFMCoULUTWeenedtgVRPDfbnTBfeWWrqvrdGfIfHbuzLvmXnGHsrzSbKlKFUJsfZgdYjtUrxJapUyIQHCnLcMiqnskpkVZiQttCuNWnDFBjGhuXuHAjWAZmDxiOwgWfArELfFPGzqfDGYYJOKrGoeFIhXKHIEgsEubauxyHHLSFcaSVJFthVaNiLCpkkaPXAOpjUZqLKIsyqgArkktucFOAugOrkNZuAgkJNeYnVZjsbyYXgqBTaeOCviytOFjuOHNxOzendtNIxkCnxwGqoStdmXxoIolQAeJuJLiFdAMKBgsqVIGrPssRvOOhtbDOBcIjhvmAoruXztjOcOYVlppevfClraGmqVAvnGyheemTFcfEEjAUuGttnpmAsYbCPmuWCHsBAQiYXxjBbzFgzbLpuZTObtZCkpsRyysUXuBhomRcfkmoGnOzvAxihpjlufgTsucAmilkNRPTrCGQJRUjHdUWaDEcPWjetXgfRUwVgjkRcfdEUWwFCiLsuqHPcOGMXqTUdwvbVijEcPkiZLYuMtYokjKTTUJfVjkyguRBgtJakOjweUEmPvshKjbopnMvAYnIfazVBNfEzTUTOEwOdWTuZGWauhWRkFUqxMwLOyvCqFlrfkBaXTmDevHhuisSZvXivAICwzNHFweRsVB";

    a = Nox_Count_Char_Repeat(longstream);

    for(i = 0; i < 128; i++)
        if (a[i] != 0)
            printf("a[%d]: %d, Char: %c \n", i, a[i], i);

    free(a);
    return (0);
}
