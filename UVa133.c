#include <stdio.h>

int n, k, m, left;
int persons[20];

int move(int now, int steps, int length);

int main(void)
{
	while((3 == scanf("%d%d%d", &n, &k, &m)) && (n && k && m)){
		/*剩余的总人数*/ 
		left = n;
		
		/*初始化数组*/ 
		int i = 1;
		for( ; i <= n; i++){
			persons[i] = i;
		}
		
		/*两位官员迈出第一步前的位置*/ 
		int a = 0;
		int b = 1;
		 
		/*循环直到所有人都被选中*/ 
		while(left){
			/*两位官员进行移动选人*/ 
			a = move(a, k, 1);
			b = move(b, m, -1);
			
			/*两个官员站在了同一个位置，则只有一个人被选中*/ 
			if(a == b){
				printf("%3d", a);
				left -= 1;
				persons[a] = -1;
			}
			/*两个官员站在了不同的位置，则有两个人被选中*/ 
			else{
				printf("%3d%3d", a, b);
				left -= 2;
				persons[a] = -1;
				persons[b] = -1;
			}
			
			/*后面还有人，可以打印逗号*/ 
			if(left != 0){
				putchar(',');
			}
		}
		
		/*打印换行符*/ 
		putchar('\n'); 
	}
	
	return 0;
}

int move(int now, int steps, int length)
{
	/*通过循环计算每次的移动，同时跳过空位置*/ 
	int i = 0;
	for( ; i < steps; i++){
		now += length;
		
		/*判断是否因为移动造成了数组越界，从而进行修正*/ 
		if(now == 0){
			now = n;
		}
		else if(now == n + 1){
			now = 1;
		}
		
		/*判断当前位置是否为空，从而进行修正*/ 
		if(persons[now] == -1){
			i--;
		} 
	}
	
	return now;
}
