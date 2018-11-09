#define LOCAL

#include <iostream>
using namespace std;

struct Info {
	int height;
	int day;
	int night;
	int fatigue;
};

inline bool readInfoSuccessful(Info& info);
bool reachTheExit(const Info& info, int& days);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int days;
	Info info;
	while (readInfoSuccessful(info)) {
		if (reachTheExit(info, days)) {
			cout << "success on day " << days << endl;
		}
		else {
			cout << "failure on day " << days << endl;
		}
	}
	return 0;
}

bool readInfoSuccessful(Info& info) {
	cin >> info.height >> info.day >> info.night >> info.fatigue;
	return (0 < info.height);
}

bool reachTheExit(const Info& info, int& days) {
	double today = info.day;
	double climb = 0.0;
	double loss = info.day * info.fatigue / 100.0;
	days = 1;
	while (1) {
		climb += today;
		if (climb > info.height) {
			break;
		}
		else {
			climb -= info.night;
			if (climb < 0.0) {
				break;
			}
			if (today < loss) {			//蜗牛不会爬出负数
				today = 0;
			}
			else {
				today -= loss;
			}
			++days;
		}
	}
	return (climb > info.height);
}