#define LOCAL

#include <iostream>
using namespace std;

bool readNewCase(int& h, int& w);
int computeAns(int h, int w);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int h, w;
	while (readNewCase(h, w)) {
		cout << computeAns(h, w) << endl;
	}
	return 0;
}

bool readNewCase(int& h, int& w) {
	cin >> h;
	if (0 == h) {
		return false;
	}
	else {
		cin >> w;
		return true;
	}
}

int computeAns(int h, int w) {
	int prev, cur;
	cin >> prev;
	int ans = h - prev;
	for (int i = 1; i < w; ++i) {
		cin >> cur;
		if (cur < prev) {
			ans += prev - cur;
		}
		prev = cur;
	}
	return ans;
}