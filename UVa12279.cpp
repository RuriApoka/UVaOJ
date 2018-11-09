#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, supposed, actually, t, kases = 1;
	while (cin >> n && n) {
		supposed = actually = 0;
		for (int i = 0; i < n; ++i) {
			cin >> t;
			if (0 == t) {
				actually++;
			}
			else {
				supposed++;
			}
		}
		cout << "Case " << kases++ << ": " << supposed - actually << endl;
	}
	return 0;
}