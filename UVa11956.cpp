#define LOCAL

#include <vector>
#include <cstdio>
using namespace std;

const int MAX_VALUE = 256;
const int MAX_ADDRESS = 100;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int n, kase = 1;
	int pointer;
	char ch;
	vector<int> value;
	scanf("%d", &n);
	getchar();
	while (n--) {
		pointer = 0;
		value.clear();
		value.resize(MAX_ADDRESS, 0);
		while ('\n' != (ch = getchar())) {
			switch (ch) {
			case '>':
				pointer = (pointer + 1) % MAX_ADDRESS;
				break;
			case '<':
				pointer = (pointer - 1 + MAX_ADDRESS) % MAX_ADDRESS;
				break;
			case '+':
				value[pointer] = (value[pointer] + 1) % MAX_VALUE;
				break;
			case '-':
				value[pointer] = (value[pointer] - 1 + MAX_VALUE) % MAX_VALUE;
				break;
			default:
				break;
			}
		}
		printf("Case %d:", kase++);
		for (int i = 0; i < MAX_ADDRESS; ++i) {
			printf(" %02X", value[i]);
		}
		putchar('\n');
	}
	return 0;
}