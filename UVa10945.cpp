#define LOCAL

#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

const int MAX_LEN = 10000;
char str[MAX_LEN];

bool readInfoSuccess(int& len);
bool isPalindrome(int len);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int len;
	while (readInfoSuccess(len)) {
		if (isPalindrome(len)) {
			puts("You won't be eaten!");
		}
		else {
			puts("Uh oh..");
		}
	}
	return 0;
}

bool readInfoSuccess(int& len) {
	len = 0;
	for (int i = 0; i < 4; ++i) {
		str[i] = getchar();
	}
	str[4] = '\0';
	if (0 != strcmp("DONE", str)) {
		for (int i = 3; i > -1; --i) {
			ungetc(str[i], stdin);
		}
		for (str[len] = getchar(); '\n' != str[len]; str[len] = getchar()) {
			if (isalpha(str[len])) {
				str[len] = tolower(str[len]);
				len++;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

bool isPalindrome(int len) {
	char *left = str, *right = str + len - 1;
	while (left < right) {
		if (*left++ != *right--) {
			return false;
		}
	}
	return true;
}