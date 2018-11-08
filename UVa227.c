#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN 128

int main(void)
{
	char command[LEN];
	char puzzle[5][7];
	char test;
	char N[2] = "\n";
	char ZERO[2] = "0";
	int n = 0, i, j, x, y;
	bool bad_command;
	bool zero_appeared;
	
	test = getchar();
	while(test != 'Z')
	{
		ungetc(test, stdin);		//����Ĳ�����ֹ�ַ��������ַ��Ż������� 
		
		/*��������*/
		for(i = 0; i < 5; i++)
		{
			fgets(puzzle[i], 7, stdin);		//���Թ����� 
		}
		for(i = 0; i < 5; i++)
		{
			for(j = 0; j < 5; j++)
			{
				if(' ' == puzzle[i][j])		//�ҵ����Ǹ����ƶ��Ŀո�
				{
					x = i;
					y = j;
					i = j = 5;		//�����ѳ�����ѭ�� 
				}
			}
		}
		
		/*�ƶ�ƴͼ*/
		while(1)
		{
			fgets(command, LEN, stdin);		//���ȶ����ƶ�ָ��
			bad_command = zero_appeared = false;
			for(i = 0; command[i]; i++)		//��ʼ��ÿ���ַ���ʼ����
			{
				switch(command[i])
				{
					case'A':
						if(x > 0) {puzzle[x][y] = puzzle[x-1][y]; x--; puzzle[x][y] = ' ';}
						else {bad_command = true; goto command_finished;}
						break;
					case'B':
						if(x < 4) {puzzle[x][y] = puzzle[x+1][y]; x++; puzzle[x][y] = ' ';}
						else {bad_command = true; goto command_finished;}
						break;
					case'L':
						if(y > 0) {puzzle[x][y] = puzzle[x][y-1]; y--; puzzle[x][y] = ' ';}
						else {bad_command = true; goto command_finished;}
						break;
					case'R':
						if(y < 4) {puzzle[x][y] = puzzle[x][y+1]; y++; puzzle[x][y] = ' ';}
						else {bad_command = true; goto command_finished;}
						break;
					case'0': zero_appeared = true; goto command_finished;
					case'\n': break;
					default: bad_command = true; goto command_finished;
				}
			}
		}
		command_finished:
			if(NULL != strstr(command, ZERO))		//��Ȼ��Ϊ�зǷ�ָ����ֹ��ѭ��������ȷʵ������'0' 
				;
			else
			{
				while(!zero_appeared)				//��û�ж���'0' 
				{
					fgets(command, LEN, stdin);
					zero_appeared = (NULL == strstr(command, ZERO)) ? false : true;
				}
			}
			if(NULL == strstr(command, N))			//�����Ѿ�ȷ��������'0'���ؼ��ǿ���û�ж���'\n'���ȼ���û�ж��� 
			{
				fgets(command, LEN, stdin);
			}
			
		/*�������*/
		(0 == n) ? : putchar('\n');
		printf("Puzzle #%d:\n", ++n);
		if(bad_command)
		{
			puts("This puzzle has no final configuration.");
		}
		else
		{
			for(i = 0; i < 5; i++)
			{
				for(j = 0; j < 4; j++)
				{
					putchar(puzzle[i][j]);
					putchar(' ');
				}
				putchar(puzzle[i][4]);
				putchar('\n');
			}
		}
		
		test = getchar();
	}
	
	return 0;
}
