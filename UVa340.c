#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int kase = 1;
	int len, i, j, k;
	int *key, *test;
	char *chosen;
	
	while(scanf("%d", &len) && len)
	{
		printf("Game %d:\n", kase++);
		key = (int *)malloc(sizeof(int) * len);
		test = (int *)malloc(sizeof(int) * len);
		chosen = (char *)malloc(sizeof(char) * len);
		memset(chosen, 0, (size_t)len);
		
		for(k = 0; k < len; k++)
		{
			scanf("%d", key + k);
		}
		while(1)
		{
			for(k = 0; k < len; k++)
			{
				scanf("%d", test + k);
			}
			if(0 == test[0])
			{
				break;
			}
			for(i = k = 0; k < len; k++)
			{
				if(key[k] == test[k])
				{
					i++;
					test[k] = 0;
					chosen[k] = 1;
				}
			}
			printf("    (%d,", i);
			for(i = j = 0; i < len; i++)
			{
				for(k = 0; k < len; k++)
				{
					if((0 == test[k]))
					{
						continue;
					}
					if((0 == chosen[i]) && (test[k] == key[i]))
					{
						j++;
						chosen[i] = 1;
						test[k] = 0;
					}
				}
			}
			printf("%d)\n", j);
			memset(chosen, 0, (size_t)len);
		}
		free(key);
		free(test);
		free(chosen);
	}
	
	return 0;
}
