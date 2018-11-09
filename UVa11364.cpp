#define LOCAL

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int n;
	vector<int> park;
	park.reserve(20);
	while (t--) {
		cin >> n;
		park.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> park[i];
		}
		sort(park.begin(), park.end());
		cout << 2 * (park.back() - park.front()) << endl;
	}
	return 0;
}