#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	int num[3];
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> num[j];
		}
		sort(num, num + 3);
		cout << "Case " << i << ": " << num[1] << endl;
	}
	return 0;
}