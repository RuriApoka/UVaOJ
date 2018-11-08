#define LOCAL

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef vector<int> Ans;
typedef vector<string> Name;
typedef map<string, int> Index;

bool readPersonNames(Name& name, Index& index);
void computeAns(Ans& ans, Index& index);
void printAns(const Ans& ans, const Name& name, int kase);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	Ans ans;
	Name name;
	Index index;
	int kase = 0;
	while (readPersonNames(name, index)) {
		computeAns(ans, index);
		printAns(ans, name, kase++);
	}
	return 0;
}

bool readPersonNames(Name& name, Index& index) {
	int n;
	if (cin >> n) {
		name.clear();
		index.clear();
		string str;
		for (int i = 0; i < n; ++i) {
			cin >> str;
			index.insert({ str, i });
			name.emplace_back(str);
		}
		return true;
	}
	else {
		return false;
	}
}

void computeAns(Ans& ans, Index& index) {
	int n = index.size();
	ans.clear();
	ans.resize(n, 0);
	string str;
	int value, nums;
	for (int i = 0; i < n; ++i) {
		cin >> str >> value >> nums;
		if (0 != nums) {
			value /= nums;
		}
		ans[index[str]] -= value * nums;
		for (int j = 0; j < nums; ++j) {
			cin >> str;
			ans[index[str]] += value;
		}
	}
}

void printAns(const Ans& ans, const Name& name, int kase) {
	if (kase > 0) {
		cout << endl;
	}
	int n = ans.size();
	for (int i = 0; i < n; ++i) {
		cout << name[i] << ' ' << ans[i] << endl;
	}
}