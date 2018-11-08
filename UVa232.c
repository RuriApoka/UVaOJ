#include <stdio.h>
#include <stdlib.h>

#define P (p[i][j] != '*')
#define Q (q[i][j] = ++k)

int main(void)
{
	int a, b, i, j, k, n = 1;

	scanf("%d", &a);
	while(a != 0)
	{
		scanf("%d", &b);
		getchar();

		char p[10][12]; 
		int q[10][10];
		
		for(i = 0; i < a; i++)
		{
			fgets(p[i], 12, stdin);
		}
		for(i = 0, k = 0; i < a; i++)
		{
			for(j = 0; j < b; j++)
			{
				if((0 == i) && P)
				{
					Q;
				}
				else if((0 == j) && P)
				{
					Q;
				}
				else if((('*' == p[i-1][j]) || ('*' == p[i][j-1])) && P)
				{
					Q;
				}
				else
				{
					q[i][j] = 0;
				}
			}
		}

		(1 == n) ?  : putchar('\n');
		printf("puzzle #%d:\n", n++);
		puts("Across");
		for(i = 0; i < a; i++)
		{
			for(j = 0; j < b; j++)
			{
				if(q[i][j] != 0)
				{
					printf("%3d.", q[i][j]);
					for( ; (j < b) && P; j++)
					{
						putchar(p[i][j]);
					}
					putchar('\n');
				}
			}
		}
		puts("Down");
		for(i = 0; i < a; i++)
		{
			for(j = 0; j < b; j++)
			{
				if(0 == i)
				{
					if(q[i][j] != 0)
					{
						printf("%3d.", q[i][j]);
						for(k = i; (k < a) && (p[k][j] != '*'); k++)
						{
							putchar(p[k][j]);
						}
						putchar('\n');
					}
				}
				else
				{
					if((q[i][j] != 0) && ('*' == p[i-1][j]))
					{
						printf("%3d.", q[i][j]);
						for(k = i; (k < a) && (p[k][j] != '*'); k++)
						{
							putchar(p[k][j]);
						}
						putchar('\n');
					}		
				}
			}
		}
		
		scanf("%d", &a);
	}

	return 0;
}
