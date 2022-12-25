#include "main.h"

/**==================================*/
/**======== populate shelves ========*/
/**==================================*/

/**
 * populate_shelves - This handles randomization
 *
 * @Deck: Pointer to 51 char array
 *
 * Description: Array must be editable. Randomization based on nanoseconds.
 */
void populate_shelves(char *deck)
{
	/**Shelves */
	char s1[25], s2[25], s3[25], s4[25], s5[25];
	char *arrays[5];
	char *s_current = NULL;
	int i, j, decnt = 0; /** decnt - deck count */
	int t[] = { 24, 24, 24, 24, 24 };
	int b[] = { 0, 0, 0, 0, 0 };

	/** assign shelves */
	arrays[0] = s1;
	arrays[1] = s2;
	arrays[2] = s3;
	arrays[3] = s4;
	arrays[4] = s5;

	/** Initialize shelves */
	for (i = 0; i < 5; i++)
		init_array(arrays[i], 25);

	for (decnt = 0; decnt < 51; )
	{
		for (i = get_i_value(); i < 5; i++)
		 {
			 s_current = arrays[i];

			 if (t[i] == 6 && b[i] == 6)
					continue;

			 if (t[i] == 6)
			 {
				s_current[b[i]] = deck[decnt];
				b[i]++;
				decnt++;
			 }
			 else if (b[i] == 6)
			 {
				s_current[t[i]] = deck[decnt];
				t[i]--;
				decnt++;
			 }
			 else
			 {
				 j = (mil() % 10);
				 if (j >> 2)
				 {
					s_current[b[i]] = deck[decnt];
					b[i]++;
					decnt++;
				 }
				 else
				 {
					s_current[t[i]] = deck[decnt];
					t[i]--;
					decnt++;
				 }
			 }
		}
	}

	/** Save shelves into deck */
	decnt = 0;
	 for (i = 0; i < 5; i++) {
		s_current = arrays[i];
		for (j = 0; j < 25; j++) {
			if (MINUS(s_current[j]) || MAXUS(s_current[j])) {
					deck[decnt++] = s_current[j];
			}
		}
	 }
}
