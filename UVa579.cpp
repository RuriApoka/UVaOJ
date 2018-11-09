#define LOCAL

#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int, int> Clock;
typedef pair<double, double> Degree;

static const int degrees = 360;
static const int deg_per_min = 6;
static const int deg_per_hour = 30;
static const double deg_per_min_for_hour = 0.5;

inline bool readCaseSuccessful(Clock& clock);
inline double computeDegrees(const Clock& clock);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	Clock clock;
	while (readCaseSuccessful(clock)) {
		printf("%.3f\n", computeDegrees(clock));
	}
	return 0;
}

bool readCaseSuccessful(Clock& clock) {
	if ((2 == scanf("%d%*c%d", &clock.first, &clock.second)) &&
		((0 != clock.first) || (0 != clock.second))) {
		return true;
	}
	else {
		return false;
	}
}

double computeDegrees(const Clock& clock) {
	static Degree degree;
	degree.first = clock.first * deg_per_hour + clock.second * deg_per_min_for_hour;
	degree.second = clock.second * deg_per_min;
	double ans = degree.first - degree.second;
	if (ans < 0.0) {
		ans += degrees;
	}
	return ((ans > 180.0) ? (degrees - ans) : ans);
}