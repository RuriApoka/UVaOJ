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
		ungetc(test, stdin);		//读入的不是终止字符，将该字符放回输入流 
		
		/*处理输入*/
		for(i = 0; i < 5; i++)
		{
			fgets(puzzle[i], 7, stdin);		//将迷宫读入 
		}
		for(i = 0; i < 5; i++)
		{
			for(j = 0; j < 5; j++)
			{
				if(' ' == puzzle[i][j])		//找到了那个可移动的空格
				{
					x = i;
					y = j;
					i = j = 5;		//暴力脱出两层循环 
				}
			}
		}
		
		/*移动拼图*/
		while(1)
		{
			fgets(command, LEN, stdin);		//首先读入移动指令
			bad_command = zero_appeared = false;
			for(i = 0; command[i]; i++)		//开始对每个字符开始处理
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
			if(NULL != strstr(command, ZERO))		//虽然因为有非法指令终止了循环，但是确实读入了'0' 
				;
			else
			{
				while(!zero_appeared)				//还没有读入'0' 
				{
					fgets(command, LEN, stdin);
					zero_appeared = (NULL == strstr(command, ZERO)) ? false : true;
				}
			}
			if(NULL == strstr(command, N))			//现在已经确定遇到了'0'，关键是看有没有读入'\n'，先假设没有读入 
			{
				fgets(command, LEN, stdin);
			}
			
		/*处理输出*/
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
