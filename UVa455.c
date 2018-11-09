#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 

int main(void)
{
	int n, i, j, k, t, l;
	char s[81], c;
	bool mismatch;
	
	scanf("%d", &n);
	for(k = 0; k < n; k++)
	{
		while(('\n' == (c = getchar())) || (' ' == c))
			;
		ungetc(c, stdin);
		scanf("%s", s);
		
		l = strlen(s);		//字符串的长度，同时也是最大循环长度可能 
		t = 1;				//首先假设循环长度为1
		for( ; t <= l; t++)
		{
			if(0 == (l % t))	//能被整除，说明可能存在循环子串 
			{
				mismatch = false;	//首先假设他们可以成功匹配
				for(i = 0; ((i < t) && !mismatch); i++)		//假设长度是为t的循环，开始判断是否所有位上字符相同
				{
					for(j = i + t; j < l; j += t)
					{
						if(s[i] != s[j])	//说明对应位置上的字符不相同 
						{
							break;			//不用再继续判断了 
						}
					}
					mismatch = (j < l) ? true : false;		//(q > l)成立说明确实这一个位全部匹配，可以进行下一个位的匹配比较 
				}
				if(!mismatch)	//若表达式成立，说明出现了全部符合的解，可以脱出循环了 
				{
					break;
				}
			}
		}
		(0 == k) ? : putchar('\n');
		(t > l) ? printf("%d\n", t - 1) : printf("%d\n", t); 
	}
	
	return 0;
}
