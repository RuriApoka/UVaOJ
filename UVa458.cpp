#include <stdio.h>

int main(void)
{
	char c;
	
	while((c = getchar()) != EOF){
		(c == '\n') ? putchar('\n') : putchar(c - 7);
	}
	
	return 0;
}
