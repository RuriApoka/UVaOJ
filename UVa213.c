#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 4096
#define LEN 50000

#define CHECK(X) (((X) == '1') || ((X) == '0') || ((X) == '\0') || ((X) == '\r') || ((X) == '\n')) ? 1 : 0

/*�������ͷ�Լ�������Ϣ*/
char header[MAX] = "";
char message[LEN] = "";

/*���ﶨ���˲�ͬ�ı���γ�����Ҫ�����Ĳ�ֵ��added[0]ֻ��Ϊ�˺ñ�ʾ*/
int add[8] = {0, 0, 1, 4, 11, 26, 57, 120};

void decoder(int size);

int main(void)
{
	/*ѭ��ֱ���޷��ٶ�ȡ������ͷ*/
	while(gets(header)){
		/*����ַ����������Ϣ��������ж�ȡ*/
		int i = 0;
		for(message[i] = getchar(); CHECK(message[i]); ){
			/*������Ϣ����ʱ������i*/
			if((message[i] == '0') || (message[i] == '1')){
				i++;
			}
			
			/*����������ļ�ĩβ��������ȡ*/
			if(EOF == (message[i] = getchar())){
				break;
			} 
		}
		
		/*���ڱ�����Ϣ��000��β�����԰ѿ�����������ַ��Ż�������*/
		while(!((message[i] == '0') && (message[i-1] == '0') && (message[i-2] == '0'))){
			ungetc(message[i], stdin);
			i--;
		}
		
		/*��������Ϣ�����ַ���*/ 
		message[i+1] = '\0';
		
		/*��Ϣ�ı��ĳ���*/
		size_t size = strlen(message);
		
		/*���벢���*/
		decoder(size);
		
		/*��������Ϣ�������*/
		strcpy(message, "");
	}
	
	return 0;
}

void decoder(int size)
{
	/*����������Ϣ��ֹ��000*/
	size -= 3;
	
	/*��ǰ���ڱ�����ַ���λ�ã�����εĳ��ȣ��Լ���ǰ����ζ�Ӧ��ʮ����ֵ*/
	int now = 0;
	int length = 0;
	int num = 0;
	 
	/*����������ͬ���ȵĽ��룬ֱ��������������Ϣ��*/
	while(now < size){
		/*��������εĳ���*/
		int i = 1;
		for(length = 0; i < 4; i++){
			length += (int)pow(2, 3 - i) * (message[now++] - '0');
		}
		
		/*��ʼΪͬһ���ȵı���ν���*/
		for( ; now < size; ){
			/*�����������������������֣����������жϸ����ʲô�ַ�*/
			for(num = 0, i = 1; i <= length; i++){
				num += (int)pow(2, length - i) * (message[now++] - '0');
			}
			
			/*�ô����ȫ��1�������ó��ȵĴ���ν���*/
			if(num == ((int)pow(2, length) - 1)){
				break;
			}
			
			/*����У����õ��Ķ�Ӧ���ַ�*/
			putchar(header[add[length]+num]);
		}
	}
	
	/*������Ļ���*/
	putchar('\n');
}
