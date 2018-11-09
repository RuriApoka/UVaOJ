#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, f;
	long long ans, a, b, c;
	cin >> n;
	while (n--) {
		ans = 0;
		cin >> f;
		while (f--) {
			cin >> a >> b >> c;
			ans += a * c;
		}
		cout << ans << endl;
	}
	return 0;
}