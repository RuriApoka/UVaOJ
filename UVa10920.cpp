#define LOCAL

#include <cstdio>
#include <cmath>
#include <utility>
using namespace std;

struct Info {
	pair<int, int> position;
	int top;
	int bottom;
	int left_steps;
};

bool readInfoSuccess(Info& info);
void initStruct(Info& info, const int size, const long long target);
void computeAns(Info& info);
inline void printAns(const Info& info) { printf("Line = %d, column = %d.\n", info.position.first, info.position.second); }

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	Info info;
	while (readInfoSuccess(info)) {
		computeAns(info);
		printAns(info);
	}
	return 0;
}

bool readInfoSuccess(Info& info) {
	int size;
	long long target;
	scanf("%d%lld", &size, &target);
	if ((0 != size) && (0 != target)) {
		initStruct(info, size, target);
		return true;
	}
	else {
		return false;
	}
}

void initStruct(Info& info, const int size, const long long target) {
	int pos_of_one = (size >> 1) + 1;
	long long t = static_cast<long long>(sqrt(target));
	t -= (1 == (t % 2)) ? 0 : 1;
	if (target == (t * t)) {
		t >>= 1;
		info.position.first = info.position.second = static_cast<int>(pos_of_one + t);
		info.left_steps = 0;
		info.top = static_cast<int>(pos_of_one + t);
		info.bottom = static_cast<int>(pos_of_one - t);
	}
	else {
		info.left_steps = static_cast<int>(target - (t * t) - 1);
		t >>= 1;
		info.position.second = static_cast<int>(pos_of_one + t);
		info.position.first = info.position.second + 1;
		info.top = static_cast<int>(pos_of_one + t + 1);
		info.bottom = static_cast<int>(pos_of_one - t - 1);
	}
}

void computeAns(Info& info) {
	if (info.left_steps > (info.position.second - info.bottom)) {
		info.left_steps -= info.position.second - info.bottom;
		info.position.second = info.bottom;
	}
	else {
		info.position.second -= info.left_steps;
		return;
	}
	if (info.left_steps > (info.position.first - info.bottom)) {
		info.left_steps -= info.position.first - info.bottom;
		info.position.first = info.bottom;
	}
	else {
		info.position.first -= info.left_steps;
		return;
	}
	if (info.left_steps > (info.top - info.position.second)) {
		info.left_steps -= info.top - info.position.second;
		info.position.second = info.top;
	}
	else {
		info.position.second += info.left_steps;
		return;
	}
	info.position.first += info.left_steps;
}