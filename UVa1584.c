#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[200];
	int n, i, j, k, len, min;
	int times;
	
	scanf("%d", &n);
	getchar();
	for(i = 0; i < n; i++){
		gets(str);
		for(j = 0, len = strlen(str); j < len; j++){
			str[len + j] = str[j];
		}
		for(j = 0, min = 0; j < len; j++){
			for(k = j + 1, times = 0; k < j + len; k++, times++){
				if(str[min + times] > str[k]){
					min = j + 1;
					break;
				}
				else if(str[min + times] < str[k]){
					break;
				}
			}
		}
		for(k = min; k < min + len; k++){
			putchar(str[k]);
		}
		putchar('\n');
	}
	
	return 0;
}
