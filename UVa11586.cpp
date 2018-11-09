#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int k, f, m;
	char ch;
	cin >> k;
	cin.get();
	for (int i = 0; i < k; ++i) {
		f = m = 0;
		while ('\n' != (ch = cin.get())) {
			if ('F' == ch) {
				f++;
			}
			else if ('M' == ch) {
				m++;
			}
		}
		if ((f == m) && (1 < f)) {
			cout << "LOOP" << endl;
		}
		else {
			cout << "NO LOOP" << endl;
		}
	}
	return 0;
}