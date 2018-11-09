#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int n, i;
	int j, k;;
	
	scanf("%d", &n);
	getchar();
	
	char (*p)[81] = (char (*)[81])malloc(sizeof(char) * 81 * n);
	int *t = (int *)malloc(sizeof(int) * n);
	
	for(i = 0; i < n; i++)
	{
		scanf("%s", p[i]);
	}
	
	for(i = 0; i < n; i++)
	{
		t[i] = 0;
		k = 0;
		
		for(j = 0; j < strlen(p[i]); j++)
		{
			if('O' == p[i][j])
			{
				t[i] += ++k;
			}
			else
			{
				k = 0;
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		printf("%d\n", t[i]);
	}
	
	return 0;
}
