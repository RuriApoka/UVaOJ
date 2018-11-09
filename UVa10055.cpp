#include <iostream>

int main(void)
{
	long long a, b, max, min;
	
	while(std::cin >> a >> b){
		max = a > b ? a : b;
		min = a < b ? a : b;
		std::cout << max - min << std::endl;
	}
	
	return 0;
}
