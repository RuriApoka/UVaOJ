#include <stdio.h>
#include <string.h>

#define WORD 128
#define NUM 26

int main(void)
{
	int round, wrong_times, i, j, k;
	char answer[WORD], wrong_guess[NUM], correct_guess[NUM];
	char guess;
	char *a, *end_w, *end_c;
	scanf("%d", &round);
	while(-1 != round)
	{
		getchar();
		fgets(answer, WORD, stdin);
		
		j = strlen(answer) - 1;
		k = wrong_times = 0;
		end_w = wrong_guess;
		end_c = correct_guess;
		memset(wrong_guess, '\0', sizeof(char) * NUM);
		memset(correct_guess, '\0', sizeof(char) * NUM);
		
		while(('\n' != (guess = getchar())) && (wrong_times < 7) && (k != j))
		{
			if(NULL == strchr(wrong_guess, guess))
			{
				if(NULL == strchr(correct_guess, guess))
				{
					if(NULL == (a = strchr(answer, guess)))
					{
						*end_w++ = guess;
						wrong_times++;
					}
					else
					{
						*end_c++ = guess;
						
						while(NULL != a)
						{
							*a = '1';
							k++;
							a = strchr(answer, guess);
						}
					}
				}		
			}
		}
		
		printf("Round %d\n", round);
		(k == j) ? puts("You win.") : ((7 == wrong_times) ? puts("You lose.") : puts("You chickened out."));
		
		if('\n' != guess)
		{
			while('\n' != getchar())
				;
		}
		scanf("%d", &round);
	}
	
	return 0;
}
