#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const float C = 12.01;
const float H = 1.008;
const float O = 16.00;
const float N = 14.01;
	
void add(float *f, char c, int a);

int main(void)
{
	int n, i, j, k;
	
	scanf("%d", &n);
	getchar();
	
	float *t = (float *)malloc(sizeof(float) * n);
	char (*p)[81] = (char (*)[81])malloc(sizeof(char) * 81 * n);
	
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
			if(isalpha(p[i][j]))
			{
				add(t + i, p[i][j], 1);
				k = 0;
			}
			else
			{
				if(!k)
				{
					add(t + i, p[i][j - 1], p[i][j] - '0' - 1);
					k = 1;
				}
				else
				{
					add(t + i, p[i][j - 2], (p[i][j - 1] - '0') * 9 + (p[i][j] - '0'));
				}
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		printf("%.3f\n", t[i]);
	}
	
	return 0;
}

void add(float *f, char c, int a)
{
	switch(c)
	{
		case'C': (*f) += C * a; break;
		case'H': (*f) += H * a; break;
		case'O': (*f) += O * a; break;
		case'N': (*f) += N * a; break;
	}
}
