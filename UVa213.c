#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 4096
#define LEN 50000

#define CHECK(X) (((X) == '1') || ((X) == '0') || ((X) == '\0') || ((X) == '\r') || ((X) == '\n')) ? 1 : 0

/*定义编码头以及编码信息*/
char header[MAX] = "";
char message[LEN] = "";

/*这里定义了不同的编码段长度需要矫正的差值，added[0]只是为了好表示*/
int add[8] = {0, 0, 1, 4, 11, 26, 57, 120};

void decoder(int size);

int main(void)
{
	/*循环直至无法再读取到编码头*/
	while(gets(header)){
		/*逐个字符读入编码信息，方便跨行读取*/
		int i = 0;
		for(message[i] = getchar(); CHECK(message[i]); ){
			/*遇到信息编码时，增加i*/
			if((message[i] == '0') || (message[i] == '1')){
				i++;
			}
			
			/*如果遇到了文件末尾，结束读取*/
			if(EOF == (message[i] = getchar())){
				break;
			} 
		}
		
		/*由于编码信息以000结尾，所以把可能误多读入的字符放回输入流*/
		while(!((message[i] == '0') && (message[i-1] == '0') && (message[i-2] == '0'))){
			ungetc(message[i], stdin);
			i--;
		}
		
		/*将解码信息构成字符串*/ 
		message[i+1] = '\0';
		
		/*信息文本的长度*/
		size_t size = strlen(message);
		
		/*解码并输出*/
		decoder(size);
		
		/*将编码信息数组清空*/
		strcpy(message, "");
	}
	
	return 0;
}

void decoder(int size)
{
	/*舍弃编码信息终止段000*/
	size -= 3;
	
	/*当前正在编码的字符的位置，编码段的长度，以及当前编码段对应的十进制值*/
	int now = 0;
	int length = 0;
	int num = 0;
	 
	/*持续进行相同长度的解码，直至解码完整个信息段*/
	while(now < size){
		/*分析编码段的长度*/
		int i = 1;
		for(length = 0; i < 4; i++){
			length += (int)pow(2, 3 - i) * (message[now++] - '0');
		}
		
		/*开始为同一长度的编码段解码*/
		for( ; now < size; ){
			/*计算这个代码段所表征的数字，用来辅助判断该输出什么字符*/
			for(num = 0, i = 1; i <= length; i++){
				num += (int)pow(2, length - i) * (message[now++] - '0');
			}
			
			/*该代码段全是1，表明该长度的代码段结束*/
			if(num == ((int)pow(2, length) - 1)){
				break;
			}
			
			/*经过校正后得到的对应的字符*/
			putchar(header[add[length]+num]);
		}
	}
	
	/*输出最后的换行*/
	putchar('\n');
}
