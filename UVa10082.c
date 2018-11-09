#include <stdio.h>
#include <string.h>

int main(void)
{
	const char key[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char c, *p;
	int len = strlen(key) + 1;
	
	while((c = getchar()) != EOF)
	{
		if(NULL == (p = strchr(key, c)))
		{
			putchar(c);
		}
		else
		{
			putchar(key[(p - key + len - 1) % len]);
		}
	}
	
	return 0;
}
