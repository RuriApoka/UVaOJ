#define LOCAL

#include <cstdio>
#include <array>
using namespace std;

struct Info {
	int day;
	int month;
	int year;
	long long days;
};

typedef array<int, 12> Year_;
typedef array<Year_, 2> Year;

const Year year { { { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } } };

bool readInfoSuccessful(Info& info);
void computeAns(Info& info);
inline void printAns(const Info& info) { printf("%d %d %d\n", info.day, info.month, info.year); }
inline bool isLeap(const int year) { return (((0 == (year % 4)) && (0 != (year % 100))) || (0 == (year % 400))); }
void resetDate(Info& info, bool is_leap);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	Info info;
	while (readInfoSuccessful(info)) {
		computeAns(info);
		printAns(info);
	}
	return 0;
}

bool readInfoSuccessful(Info& info) {
	if (4 == scanf("%lld%d%d%d", &info.days, &info.day, &info.month, &info.year)) {
		return ((0 != info.days) || (0 != info.day) || (0 != info.month) || (0 != info.year));
	}
	else {
		return false;
	}
}

void computeAns(Info& info) {
	const int Normal = 365;
	const int Leap = 366;
	const int Round = Normal * 3 + Leap;
	//把当前日期调整到最接近的上一个闰年的元旦
	if (isLeap(info.year)) {
		resetDate(info, true);
	}
	else {
		resetDate(info, false);
		while (!isLeap(--info.year)) {
			info.days += Normal;
		}
		info.days += Leap;
	}
	//以四年为一个周期，增加年份
	while (info.days > Round) {
		info.year += 4;
		info.days -= isLeap(info.year) ? Round : (Round - 1);
	}
	//根据剩余天数是否足够进入平年，再次增加年份
	bool is_leap;
	if (info.days < Leap) {
		is_leap = true;
	}
	else {
		info.year++;
		info.days -= Leap;
		info.year += info.days / Normal;
		info.days %= Normal;
		is_leap = false;
	}
	//计算具体日期
	while (info.days >= year[is_leap][info.month - 1]) {
		info.days -= year[is_leap][info.month - 1];
		info.month++;
	}
	info.day += info.days;
}

void resetDate(Info& info, bool is_leap) {
	info.days += info.day - 1;
	info.day = 1;
	for (--info.month; info.month > 0; --info.month) {
		info.days += year[is_leap][info.month - 1];
	}
	info.month = 1;
}