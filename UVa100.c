#include <stdio.h>

#define MAX 1000005

int a[MAX];

int main(void)
{
	int i, j, o, p, n, max;
	unsigned int t;
	for(i = 0; i < MAX; i++)    a[i] = 1;
	
	while(EOF != scanf("%d%d", &i, &j))
	{
		o = i > j ? j : i;
		p = i > j ? i : j;
		for(n = o, max = 1; n <= p; n++)
		{
			if(a[n] != 1)	max = a[n] > max ? a[n] : max;
			else
			{
				for(t = n; t != 1; a[n]++)
				{
					if(t % 2 == 1)  t = t * 3 + 1;
					else    t /= 2;
				}
			}
				max = a[n] > max ? a[n] : max;
		}
		printf("%d %d %d\n", i, j, max);
	}
	
	return 0;
}
