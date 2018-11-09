#define LOCAL

#include <iostream>
#include <utility>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int n;
	pair<int, int> division, query;
	while ((cin >> n) && (0 != n)) {
		cin >> division.first >> division.second;
		while (n--) {
			cin >> query.first >> query.second;
			if ((query.first == division.first) || (query.second == division.second)) {
				cout << "divisa" << endl;
			}
			else if (query.first > division.first) {
				cout << ((query.second > division.second) ? "NE" : "SE") << endl;
			}
			else {
				cout << ((query.second > division.second) ? "NO" : "SO") << endl;
			}
		}
	}
	return 0;
}