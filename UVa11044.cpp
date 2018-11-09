#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int n, m, x, y;
	while (t--) {
		cin >> n >> m;
		n -= 2;
		x = n / 3;
		if (0 != (n % 3)) {
			x++;
		}
		m -= 2;
		y = m / 3;
		if (0 != (m % 3)) {
			y++;
		}
		cout << x * y << endl;
	}
	return 0;
}