#include <stdio.h>
#include <stdlib.h>

#define LEN 102
#define NUM 26

typedef enum{false, true} bool;

int compare(const void *, const void *);

int main(void)
{
	char str1[LEN], str2[LEN];
	int sort1[NUM], sort2[NUM];
	int i;
	bool yes;
	
	while(NULL != fgets(str1, LEN, stdin))
	{
		fgets(str2, LEN, stdin);
		
		for(i = 0; i < NUM; i++)
		{
			sort1[i] = sort2[i] = 0;
		}
		
		i = 0;
		while(str1[i] != '\n')
		{
			sort1[str1[i] - 'A']++;
			sort2[str2[i] - 'A']++;
			i++;
		}
		qsort(sort1, (size_t)NUM, sizeof(int), compare);
		qsort(sort2, (size_t)NUM, sizeof(int), compare);
		
		for(yes = true, i = 0; (i < NUM) && yes; i++)
		{
			yes = (sort1[i] != sort2[i]) ? false : true;
		}
		
		(false != yes) ? puts("YES") : puts("NO");
	}
	
	return 0;
}

int compare(const void *a, const void *b)
{
	const int *c = (const int *)a;
	const int *d = (const int *)b;
	
	return (*d - *c);
}
