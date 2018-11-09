#define LOCAL

#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return (0 == b) ? a : gcd(b, a % b);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	int n;
	while ((cin >> n) && (0 != n)) {
		int ans = 0;
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				ans += gcd(i, j);
			}
		}
		cout << ans << endl;
	}
	return 0;
}