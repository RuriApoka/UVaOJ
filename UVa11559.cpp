#define LOCAL

#include <iostream>
using namespace std;

const int MAX = 0xffffff;

struct Info {
	int participants;
	int budget;
	int hotels;
	int weeks;
};

bool readInfoSuccessful(Info& info);
int computeAns(const Info& info);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int ans;
	Info info;
	while (readInfoSuccessful(info)) {
		ans = computeAns(info);
		if (MAX == ans) {
			cout << "stay home" << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return 0;
}

bool readInfoSuccessful(Info& info) {
	if (cin >> info.participants) {
		cin >> info.budget >> info.hotels >> info.weeks;
		return true;
	}
	else {
		return false;
	}
}

int computeAns(const Info& info) {
	int ans = MAX;
	int price, beds, cost;
	for (int i = 0; i < info.hotels; ++i) {
		cin >> price;
		for (int j = 0; j < info.weeks; ++j) {
			cin >> beds;
			if (beds >= info.participants) {
				if ((cost = price * info.participants) <= info.budget) {
					ans = (cost > ans) ? ans : cost;
				}
				for (++j; j < info.weeks; ++j) {
					cin >> beds;
				}
			}
		}
	}
	return ans;
}