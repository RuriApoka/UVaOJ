#include <stdio.h>

int n, k, m, left;
int persons[20];

int move(int now, int steps, int length);

int main(void)
{
	while((3 == scanf("%d%d%d", &n, &k, &m)) && (n && k && m)){
		/*ʣ���������*/ 
		left = n;
		
		/*��ʼ������*/ 
		int i = 1;
		for( ; i <= n; i++){
			persons[i] = i;
		}
		
		/*��λ��Ա������һ��ǰ��λ��*/ 
		int a = 0;
		int b = 1;
		 
		/*ѭ��ֱ�������˶���ѡ��*/ 
		while(left){
			/*��λ��Ա�����ƶ�ѡ��*/ 
			a = move(a, k, 1);
			b = move(b, m, -1);
			
			/*������Ավ����ͬһ��λ�ã���ֻ��һ���˱�ѡ��*/ 
			if(a == b){
				printf("%3d", a);
				left -= 1;
				persons[a] = -1;
			}
			/*������Ավ���˲�ͬ��λ�ã����������˱�ѡ��*/ 
			else{
				printf("%3d%3d", a, b);
				left -= 2;
				persons[a] = -1;
				persons[b] = -1;
			}
			
			/*���滹���ˣ����Դ�ӡ����*/ 
			if(left != 0){
				putchar(',');
			}
		}
		
		/*��ӡ���з�*/ 
		putchar('\n'); 
	}
	
	return 0;
}

int move(int now, int steps, int length)
{
	/*ͨ��ѭ������ÿ�ε��ƶ���ͬʱ������λ��*/ 
	int i = 0;
	for( ; i < steps; i++){
		now += length;
		
		/*�ж��Ƿ���Ϊ�ƶ����������Խ�磬�Ӷ���������*/ 
		if(now == 0){
			now = n;
		}
		else if(now == n + 1){
			now = 1;
		}
		
		/*�жϵ�ǰλ���Ƿ�Ϊ�գ��Ӷ���������*/ 
		if(persons[now] == -1){
			i--;
		} 
	}
	
	return now;
}
