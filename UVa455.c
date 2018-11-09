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
		
		l = strlen(s);		//�ַ����ĳ��ȣ�ͬʱҲ�����ѭ�����ȿ��� 
		t = 1;				//���ȼ���ѭ������Ϊ1
		for( ; t <= l; t++)
		{
			if(0 == (l % t))	//�ܱ�������˵�����ܴ���ѭ���Ӵ� 
			{
				mismatch = false;	//���ȼ������ǿ��Գɹ�ƥ��
				for(i = 0; ((i < t) && !mismatch); i++)		//���賤����Ϊt��ѭ������ʼ�ж��Ƿ�����λ���ַ���ͬ
				{
					for(j = i + t; j < l; j += t)
					{
						if(s[i] != s[j])	//˵����Ӧλ���ϵ��ַ�����ͬ 
						{
							break;			//�����ټ����ж��� 
						}
					}
					mismatch = (j < l) ? true : false;		//(q > l)����˵��ȷʵ��һ��λȫ��ƥ�䣬���Խ�����һ��λ��ƥ��Ƚ� 
				}
				if(!mismatch)	//�����ʽ������˵��������ȫ�����ϵĽ⣬�����ѳ�ѭ���� 
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
