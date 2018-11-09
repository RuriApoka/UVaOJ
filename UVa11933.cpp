#define LOCAL

#include <iostream>
#include <bitset>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	bitset<32> num, ans[2];
	int index;
	int n;
	cin >> n;
	while (0 != n) {
		num = n;
		ans[0] = ans[1] = 0;
		index = 0;
		for (int i = 0; i < 32; ++i) {
			if (1 == num[i]) {
				ans[index % 2].set(i);
				++index;
			}
		}
		cout << ans[0].to_ulong() << ' ' << ans[1].to_ulong() << '\n';
		cin >> n;
	}
}