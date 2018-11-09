#include <stdio.h>
#include <string.h>

#define LEN 22
#define M mirror[i]

typedef enum {false, true} bool;

int main(void)
{
	int i, j;
	bool palindrome, mirrored;
	char read_in[LEN], mirror[LEN];
	
	while(NULL != fgets(read_in, LEN, stdin))
	{
		palindrome = mirrored = true;
		read_in[strlen(read_in) - 1] = '\0';
		for(i = 0, j = strlen(read_in) - 1; (i <= (strlen(read_in) - 1) / 2) && palindrome; i++, j--)
		{
			palindrome = (read_in[i] != read_in[j]) ? false : true;
		}

		for(i = 0; (i < strlen(read_in)) && mirrored; i++)
		{
			switch(read_in[i])
			{
				case'A':
				case'H':
				case'I':
				case'M':
				case'O':
				case'T':
				case'U':
				case'V':
				case'W':
				case'X':
				case'Y':
				case'1':
				case'8': M = read_in[i]; break;
				case'B':
				case'C':
				case'D':
				case'F':
				case'G':
				case'K':
				case'N':
				case'P':
				case'Q':
				case'R':
				case'4':
				case'6':
				case'7':
				case'9': mirrored = false; break;
				case'E': M = '3'; break;
				case'J': M = 'L'; break;
				case'L': M = 'J'; break;
				case'S': M = '2'; break;
				case'Z': M = '5'; break;
				case'2': M = 'S'; break;
				case'3': M = 'E'; break;
				case'5': M = 'Z'; break;
				default: break;
			}
		}
		if(true == mirrored)
		{
			mirror[i] = '\0';
			for(i = 0, j = strlen(mirror) - 1; (i < strlen(read_in)) && mirrored; i++, j--)
			{
				mirrored = (read_in[i] != mirror[j]) ? false : true;
			}
		}
		/*output*/
		printf("%s -- ", read_in);
		if(true == palindrome)
		{
			(true == mirrored) ? puts("is a mirrored palindrome.\n") : puts("is a regular palindrome.\n");	
		}
		else
		{
			(true == mirrored) ? puts("is a mirrored string.\n") : puts("is not a palindrome.\n");
		}
	}

	return 0;
}
