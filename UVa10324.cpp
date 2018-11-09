#define LOCAL

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef vector<pair<int, int> > MyType;
typedef MyType::iterator MyIt;

void initIntever(MyType& intever);
void computeAns(MyType& intever, int kase);
bool binarySearch(MyIt first, MyIt second, pair<int, int>& p);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int kase = 1;
	MyType intever;
	intever.reserve(100000);
	while (cin.get() && !cin.eof()) {
		cin.unget();
		initIntever(intever);
		computeAns(intever, kase++);
	}
	return 0;
}

void initIntever(MyType& intever) {
	intever.clear();
	char prev, cur;
	int left, right;
	left = right = 0;
	cin.get(cur);
	prev = cur;
	while ('\n' != (cur = cin.get())) {
		if (prev == cur) {
			right++;
		}
		else {
			intever.push_back({ left, right });
			prev = cur;
			right++;
			left = right;
		}
	}
	intever.push_back({ left, right });
}

void computeAns(MyType& intever, int kase) {
	cout << "Case " << kase << ':' << endl;
	int n;
	cin >> n;
	pair<int, int> p;
	MyIt it;
	while (n--) {
		cin >> p.first >> p.second;
		if (p.first > p.second) {
			swap(p.first, p.second);
		}
		if (binarySearch(intever.begin(), intever.end(), p)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	cin.get();
}

bool binarySearch(MyIt first, MyIt second, pair<int, int>& p) {
	MyIt mid;
	while (first < second) {
		mid = first + (second - first) / 2;
		if (mid->first < p.first) {
			first = mid + 1;
		}
		else if (mid->first > p.first) {
			second = mid;
		}
		else {
			return mid->second >= p.second;
		}
	}
	return ((mid->first > p.first) ? (((mid - 1)->second) >= p.second) : (mid->second >= p.second));
}