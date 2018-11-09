#define LOCAL

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Info {
	string name;
	double price;
	int match;
};

bool cmp(const Info& a, const Info& b) {
	if (a.match == b.match) {
		return (a.price < b.price);
	}
	else {
		return a.match > b.match;
	}
}

typedef vector<Info> MyType;

bool readInfoSuccessful(MyType& info);
string computeAns(MyType& info);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int kase = 0;
	MyType info;
	while (readInfoSuccessful(info)) {
		if (kase) {
			cout << endl;
		}
		cout << "RFP #" << ++kase << endl << computeAns(info) << endl;
	}
	return 0;
}

bool readInfoSuccessful(MyType& info) {
	int n, p;
	cin >> n >> p;
	cin.get();
	if (0 == n) {
		return false;
	}
	else {
		string t;
		for (int i = 0; i < n; ++i) {
			getline(cin, t);
		}
		info.resize(p);
		for (int i = 0; i < p; ++i) {
			getline(cin, info[i].name);
			cin >> info[i].price >> info[i].match;
			cin.get();
			for (int j = 0; j < info[i].match; ++j) {
				getline(cin, t);
			}
		}
		return true;
	}
}

string computeAns(MyType& info) {
	stable_sort(info.begin(), info.end(), cmp);
	return info.front().name;
}