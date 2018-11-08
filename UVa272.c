#include <stdio.h>

enum bool{false, true};

int main(void)
{
	int c;
	enum bool left = true;

	while(EOF != (c = getchar()))
	{
		if('"' == c)
		{
			if(false == left)
			{
				printf("''");
				left = true;
			}
			else
			{
				printf("``");
				left = false;
			}
		}
		else
		{
			putchar(c);
		}
	}

	return 0;
}
