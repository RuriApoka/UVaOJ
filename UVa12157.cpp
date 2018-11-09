#define LOCAL

#include <iostream>
using namespace std;

const int MILE_SECOND = 30;
const int MILE_COST = 10;
const int JUICE_SECOND = 60;
const int JUICE_COST = 15;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int n, m;
	int kase = 1;
	int total_time, mile_price, juice_price;
	cin >> n;
	while (n--) {
		mile_price = juice_price = 0;
		cin >> m;
		for (int i = 0; i < m; ++i) {
			cin >> total_time;
			mile_price += (total_time / MILE_SECOND + 1) * MILE_COST;
			juice_price += (total_time / JUICE_SECOND + 1) * JUICE_COST;
		}
		cout << "Case " << kase++ << ": ";
		if (mile_price == juice_price) {
			cout << "Mile Juice " << mile_price << endl;
		}
		else if (mile_price < juice_price) {
			cout << "Mile " << mile_price << endl;
		}
		else {
			cout << "Juice " << juice_price << endl;
		}
	}
	return 0;
}