#define LOCAL

#include <cstdio>
#include <cstdlib>
#include <array>
using namespace std;

typedef array<int, 12> Year_;
typedef array<Year_, 2> Year;
typedef array<int, 12> Zodiac;
typedef array<const char * const, 12> Name;

struct Info {
	int days;
	int month;
	int day;
	int year;
	int zodiac_index;
};

const Year year = { { { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } } };
const Zodiac zodiac = { 21, 20, 21, 21, 22, 22, 23, 22, 24, 24, 23, 23 };
const Name name = { "aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius", "capricorn" };

void readNewCase(Info& info);
void computeAns(Info& info);
inline void printAns(const Info& info, int kase) { printf("%d %02d/%02d/%04d %s\n", kase, info.month, info.day, info.year, name[info.zodiac_index]); }
inline bool isLeap(int year) { return (((0 == (year % 4)) && (0 != (year % 100))) || (0 == (year % 400))); }
void computeBirthday(Info& info);
inline int computeZodiac(Info& info) { return ((info.day < zodiac[info.month - 1]) ? (info.month - 1 - 1 + zodiac.size()) % zodiac.size() : info.month - 1); }

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int n;
	scanf("%d", &n);
	Info info;
	for (int i = 1; i <= n; ++i) {
		readNewCase(info);
		computeAns(info);
		printAns(info, i);
	}
	return 0;
}

void readNewCase(Info& info) {
	char str[5];
	scanf("%2s", str);
	info.month = atoi(str);
	scanf("%2s", str);
	info.day = atoi(str);
	scanf("%4s", str);
	info.year = atoi(str);
	info.days = 280;
}

void computeAns(Info& info) {
	computeBirthday(info);
	info.zodiac_index = computeZodiac(info);
}

void computeBirthday(Info& info) {
	//reset the date to 1/1/year
	info.days += info.day - 1;
	info.day = 1;
	bool is_leap = isLeap(info.year);
	while (--info.month) {
		info.days += year[is_leap][info.month - 1];
	}
	info.month++;
	//compute the birth year
	if (info.days >= (365 + is_leap)) {
		info.days -= (365 + is_leap);
		is_leap = isLeap(++info.year);
	}
	//compute the birth month
	while (info.days >= year[is_leap][info.month - 1]) {
		info.days -= year[is_leap][info.month - 1];
		info.month++;
	}
	//compute the birth day
	info.day += info.days;
}