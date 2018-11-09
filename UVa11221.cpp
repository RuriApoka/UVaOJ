#define LOCAL

#include <cstdio>
#include <cmath>
#include <cctype>
using namespace std;

char str[10000];
char square[100][100];

int readInfo();
bool haveMagic(int len, int& k);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int len, k, kase = 1;
	int t;
	scanf("%d%*c", &t);
	while (t--) {
		if (haveMagic(readInfo(), k)) {
			printf("Case #%d:\n%d\n", kase++, k);
		}
		else {
			printf("Case #%d:\nNo magic :(\n", kase++);
		}
	}
	return 0;
}

int readInfo() {
	int len = 0;
	while ('\n' != (str[len] = getchar())) {
		if (isalpha(str[len])) {
			len++;
		}
	}
	return len;
}

bool haveMagic(int len, int& k) {
	k = int(sqrt(len));
	if ((k * k) == len) {
		char *left = str, *right = str + len - 1;
		while (left < right) {
			if (*left++ != *right--) {
				return false;
			}
		}
		left = str;
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < k; ++j) {
				square[i][j] = *left++;
			}
		}
		for (int i = 0; i < k; ++i) {
			for (int j = i + i; j < k; ++j) {
				if (square[i][j] != square[j][i]) {
					return false;
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
}