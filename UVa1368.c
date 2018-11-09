#include <stdio.h>

#define M 50
#define N 1002
#define NUM 4

int main(void)
{
	int t, m, n, i, j, k, o, p;
	int w[NUM];
	char DNA[M][N];
	char str[N];
	int mismatch;

	scanf("%d", &t);
	for(k = 0; k < t; k++)
	{
		/*input*/
		scanf("%d %d", &m, &n);
		getchar();
		for(i = 0; i < m; i++)
		{
			fgets(DNA[i], N, stdin);
		}

		/*compute the string*/
		mismatch = 0;
		for(j = 0; j < n; j++)
		{
			for(i = 0; i < NUM; i++)
			{
				w[i] = 0;
			}
			for(i = 0; i < m; i++)
			{
				switch(DNA[i][j])
				{
					case'A': w[0]++; break;
					case'C': w[1]++; break;
				       	case'G': w[2]++; break;
					case'T': w[3]++; break;
					default: break;
				}
			}
			for(o = 0, p = 1; p < NUM; p++)
			{
				o = (w[o] < w[p]) ? p : o;
			}
			for(p = 0; p < NUM; p++)
		       	{
				mismatch += (o == p) ? 0 : w[p];
			}
			switch(o)
			{
				case 0: str[j] = 'A'; break;
				case 1: str[j] = 'C'; break;
				case 2: str[j] = 'G'; break;
				case 3: str[j] = 'T'; break;
				default: break;
			}
		}
		str[j] = '\0';

		/*output*/
		puts(str);
		printf("%d\n", mismatch);
	}

	return 0;
}
