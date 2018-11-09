#include <cstdio>
#include <cctype>
using namespace std;

int main() {
	char ch;
	char t[4];
	int value[2];
	double ans;
	while (EOF != (ch = getchar())) {
		ungetc(ch, stdin);
		value[0] = value[1] = 0;
		for (int i = 0; i < 2; ++i) {
			while ('\n' != (ch = getchar())) {
				if (isalpha(ch)) {
					ch = tolower(ch);
					value[i] += ch - 'a' + 1;
				}
			}
			while (value[i] > 9) {
				sprintf(t, "%d", value[i]);
				value[i] = 0;
				for (int j = 0; '\0' != t[j]; ++j) {
					value[i] += t[j] - '0';
				}
			}
		}
		ans = (value[0] > value[1]) ? ((double)value[1] / value[0]) : ((double)value[0] / value[1]);
		ans *= 100;
		printf("%.2f %%\n", ans);
	}
	return 0;
}