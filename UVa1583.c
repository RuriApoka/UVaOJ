#include <stdio.h>

#define N 100001

int gen[N];

int main(void)
{
	int i, j, k;
	int kase, num;
	
	freopen("input.txt", "r", stdin);
	
	for(i = 1; i < N; i++)
	{
		gen[i] = 0;
	}
	scanf("%d", &kase);
	i = 1;
	while(kase--)
	{
		scanf("%d", &num);
		if(0 == gen[num])
		{
			for( ; (0 == gen[num]) && (i < num); i++)
			{
				for(k = j = i; k; k /= 10)
				{
					j += k % 10;
				}
				if(0 == gen[j])
				{
					gen[j] = i;
				}
				else
				{
					gen[j] = gen[j] < i ? gen[j] : i;
				}
			}
		}
		printf("%d\n", gen[num]);
	}
	
	return 0;
}
