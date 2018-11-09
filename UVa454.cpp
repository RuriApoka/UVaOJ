#define LOCAL

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

typedef multimap<string, string> Phrases;
typedef Phrases::const_iterator MyIt;
typedef vector<pair<string, string> > Ans;

void readInfo(Phrases& phrases);
void computeAns(const Phrases& phrases, Ans& ans);
void printAns(const Ans& ans, int kase);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	Phrases phrases;
	Ans ans;
	ans.reserve(100);
	int kases;
	cin >> kases;
	cin.get();
	string t;
	getline(cin, t);
	for (int i = 0; i < kases; ++i) {
		readInfo(phrases);
		computeAns(phrases, ans);
		printAns(ans, i);
	}
	return 0;
}

void readInfo(Phrases& phrases) {
	phrases.clear();
	pair<string, string> t;
	pair<string::iterator, string::iterator> range;
	while (getline(cin, t.second) && !t.second.empty()) {
		t.first.assign(t.second);
		sort(t.first.begin(), t.first.end());
		range = equal_range(t.first.begin(), t.first.end(), ' ');
		t.first.erase(range.first, range.second);
		phrases.emplace(t);
	}
}

void computeAns(const Phrases& phrases, Ans& ans) {
	ans.clear();
	MyIt begin = phrases.cbegin();
	MyIt end = phrases.cend();
	pair<MyIt, MyIt> range;
	while (begin != end) {
		range = phrases.equal_range(begin->first);
		if ((range.first != range.second) &&
			(++range.first != range.second)) {
			for (MyIt i = --range.first; i != range.second; ++i) {
				MyIt j = i;
				for (++j; j != range.second; ++j) {
					if (i->second < j->second) {
						ans.push_back({ i->second, j->second });
					}
					else {
						ans.push_back({ j->second, i->second });
					}
				}
			}
		}
		begin = range.second;
	}
	sort(ans.begin(), ans.end());
}

void printAns(const Ans& ans, int kase) {
	if (kase > 0) {
		cout.put('\n');
	}
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i].first << " = " << ans[i].second << endl;
	}
}