#include <stdio.h>

char *Nox_Strstr(char *haystack, char *needle, int siz);

/**
 * main - Example main, string of 1050 characters
 *
 * Return: always 0
 * Description: Btw this wont compile under ISO C90 because strings over 509
 * characters arent allowed.
 */
int main() {
    int word_size;
    char search_term[4];
    char *result = NULL;
    char *longstream =
    "NBKTeEAGzZAtfzVMLYvNJBIIiKCpdirDbhKsJzkDYaslVbRrIBpueuwHcoJgFHSIvsywFwbWmetNlNPKcoolqKssuBGzGsonMLjwOPfqdKarnKBPzlrohIFTzoBloDtItQdZsyztWPIOKBMeQIbcmgFHGqptaEwwvwhCtXIwTjQdLMRISaYrFwgJQJwLiOmySUclJeRaxVBXCEvzidIydsaZXKBpSpDeLKJfoSINWNYbieSnajLQBkUSGFhLjEbKfIRxRIWZNFPjruWzLQcoogSHXPbLttReyWKlqyLyinxfHKjPyMoVWmpLyCNhDITabVFqBgzJpArNufQDpKSsWdmCPuESelqiOMynuZfmGihPxkwtsDuyBtiqNlJLuSiFyWhZOryyiiQeFMCoULUTWeenedtgVRPDfbnTBfeWWrqvrdGfIfHbuzLvmXnGHsrzSbKlKFUJsfZgdYjtUrxJcoapUyIQHCnLcMiqnskpkVZiQttCuNWnDFBjGhuXuHAjWAZmDxiOwgWfArELfFPGzqfDGYYJOKrGoeFIhXKHIEgsEubauxyHHLSFcaSVJFthVaNiLCpkkaPXAOpjUZqLKIsyqgArkktucFOAugOrkNZuAgkJNeYnVZjsbyYXgqBTaeOCviytOFjuOHNxOzendtNIxkCnxwGqoStdmXxoIolQAeJuJLiFdAMKBgsqVIGrPssRvOOhtbDOBcIjhvmAoruXztjOcOYVlppevfClraGmqVAvnGyheemTFcfEEjAUuGttnpmAsYbCPmuWCHsBAQiYXxjBbzFgzbLpuZTObtZCkpsRyysUXuBhomRcfkmoGnOzvAxihpjlufgTsucAmilkNRPTrCGQJRUjHdUWaDEcPWjetXgfRUwVgjkRcfdEUWwFCiLsuqHPcOGMXqTUdwvbVijEcPkiZLYuMtYokjKTTUJfVjkyguRBgtJakOjweUEmPvshKjbopnMvAYnIfazVBNfEzTUTOEwOdWTuZGWauhWRkFUqxMwLOyvCqFlrfkBaXTmDevHhuisSZvXivAICwzNHFweRsVB";

    search_term[0] = 'c';
    search_term[1] = 'o';
    word_size = 2;
    while(1)
    {
        result = Nox_Strstr(longstream, search_term, word_size);
        word_size++;
        switch(word_size)
        {
        case 3:
            printf("%s-", result);
            search_term[2] = 'o';
        break;
        case 4:
            printf("%s-", result);
            search_term[3] = 'l';
        break;
        default:
            printf("%s\n", result);
            return (0);
        break;
        }
    }

    return (1);
}
