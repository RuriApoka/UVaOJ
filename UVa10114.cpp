#define LOCAL

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct Info {
	int month;
	double down_payment;
	double loan;
	int records;
};

typedef pair<int, double> Record;
typedef vector<Record> Records;

bool readInfoSuccessful(Info& info, Records& records);
int computeAns(const Info& info, const Records& records);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	Info info;
	Records records;
	while (readInfoSuccessful(info, records)) {
		int ans = computeAns(info, records);
		if (1 == ans) {
			cout << ans << " month" << endl;
		}
		else {
			cout << ans << " months" << endl;
		}
	}
	return 0;
}

bool readInfoSuccessful(Info& info, Records& records) {
	cin >> info.month >> info.down_payment >> info.loan >> info.records;
	if (0 > info.month) {
		return false;
	}
	else {
		records.resize(info.records);
		for (int i = 0; i < info.records; ++i) {
			cin >> records[i].first >> records[i].second;
		}
		return true;
	}
}

int computeAns(const Info& info, const Records& records) {
	double car_left = (info.down_payment + info.loan) * (1 - records[0].second);
	double loan = info.loan;
	if (car_left > loan) {			//万一人家是土豪，没有向银行贷款呢？
		return 0;
	}
	double pay_per_month = info.loan / info.month;
	Records::const_iterator it = records.cbegin() + 1;
	for (int i = 1; i < info.month; ++i) {
		loan -= pay_per_month;
		if (i < it->first) {
			car_left *= (1 - (it - 1)->second);
		}
		else {
			car_left *= (1 - it->second);
			if ((it + 1) != records.cend()) {
				++it;
			}
		}
		if (car_left > loan) {
			return i;
		}
	}
	return info.month;
}