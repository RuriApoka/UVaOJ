#define LOCAL

#include <iostream>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int a, b, c, d;
	int ans;
	for (cin >> a >> b >> c >> d; a | b | c | d; cin >> a >> b >> c >> d) {
		ans = 0;
		ans += (a < b) ? (a - b + 40) : (a - b);		//四十进制，负数加上四十得对立数值，也即指针转过的距离
		ans += (c < b) ? (c - b + 40) : (c - b);		//还要考虑相等的情况，取到等号的地方不能加四十
		ans += (c < d) ? (c - d + 40) : (c - d);
		ans *= 9;
		ans += 1080;
		cout << ans << endl;
	}
	return 0;
}