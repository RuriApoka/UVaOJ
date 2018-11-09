#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *p1, const void *p2);

int main(void)
{
	int n, i, j, k;
	
	scanf("%d", &n);
	
	int *p = (int *)malloc(sizeof(int) * n);
	int *q = (int *)malloc(sizeof(int) * n);
	int (*t)[10] = (int (*)[10])malloc(sizeof(int) * 10 * n);
	memset(t, 0, sizeof(int) * 10);
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", p + i);
	}
	memmove(q, p, sizeof(int) * n);
	qsort(q, (size_t)n, sizeof(int), compare);

	for(i = 0; i < n; i++)
	{
		if(i)
		{
			memmove(t[i], t[i - 1], sizeof(int) * 10);
		}
		else
		{
			j = 1;
		}
		
		for( ; j <= q[i]; j++)
		{
			k = j;
			
			while(k)
			{
				t[i][k % 10]++;
				k /= 10;
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(q[j] == p[i])
			{
				for(k = 0; k < 9; k++)
				{
					printf("%d ", t[j][k]);
				}
				printf("%d\n", t[j][9]);
				
				break;
			}
		}
	}
	
	return 0;
}

int compare(const void *p1, const void *p2)
{
	const int *p = (const int *)p1;
	const int *q = (const int *)p2;
	
	return (*p - *q);
}
