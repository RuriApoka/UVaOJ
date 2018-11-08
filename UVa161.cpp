#define LOCAL

#include <cstdio>
#include <array>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> Signal;
typedef array<Signal, 100> Signals;

const int YELLOW = 5;
const int FIVE_HOURS = 18000;

bool readInfoSuccess(Signals& signals, int& n);
int computeAns(const Signals& signals, const int n);
void printAns(int seconds);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	Signals signals;
	int n, seconds;
	while (readInfoSuccess(signals, n)) {
		seconds = computeAns(signals, n);
		printAns(seconds);
	}
	return 0;
}

bool readInfoSuccess(Signals& signals, int& n) {
	n = 0;
	int t;
	scanf("%d", &t);
	if (0 != t) {
		signals[n].first = (t << 1);
		signals[n++].second = t - YELLOW;
		while (scanf("%d", &t) && (0 != t)) {
			signals[n].first = (t << 1);
			signals[n++].second = t - YELLOW;
		}
		sort(signals.begin(), signals.begin() + n);
		return true;
	}
	else {
		return false;
	}
}

int computeAns(const Signals& signals, const int n) {
	int seconds = signals[0].first;
	for (int i = n - 1; (i > -1) && (seconds <= FIVE_HOURS); --i) {
		if ((seconds % signals[i].first) >= signals[i].second) {
			seconds += signals[i].first - (seconds % signals[i].first);
			i = n;
		}
	}
	return seconds;
}

void printAns(int seconds) {
	if (seconds > FIVE_HOURS) {
		puts("Signals fail to synchronise in 5 hours");
	}
	else {
		int hours = seconds / 3600;
		seconds %= 3600;
		int minutes = seconds / 60;
		seconds %= 60;
		printf("%02d:%02d:%02d\n", hours, minutes, seconds);
	}
}