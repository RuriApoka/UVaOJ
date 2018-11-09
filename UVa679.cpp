#define LOCAL

#include <iostream>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int n, d, i;
	cin >> n;
	while (n--) {
		cin >> d >> i;
		int ans = 1;
		while (--d) {
			if (1 == i % 2) {
				i = i / 2 + 1;
				ans *= 2;
			}
			else {
				i /= 2;
				ans = ans * 2 + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}