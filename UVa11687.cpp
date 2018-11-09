#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string str;
	const string END = "END";
	const string ONE = "1";
	char t[8];
	for (cin >> str; str != END; cin >> str) {
		int i, len;
		for (i = 0; str != ONE; ++i) {
			len = str.size();
			sprintf(t, "%d", len);
			str = t;
		}
		cout << i + 1 << endl;
	}
	return 0;
}