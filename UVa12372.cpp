#include <iostream>
using namespace std;

int main() {
	int n, t, max;
	cin >> n;
	for (int i = 0; i < n;) {
		max = -1;
		for (int j = 0; j < 3; ++j) {
			cin >> t;
			max = (t > max) ? t : max;
		}
		cout << "Case " << ++i << ": ";
		if (max > 20) {
			cout << "bad" << endl;
		}
		else {
			cout << "good" << endl;
		}
	}
	return 0;
}