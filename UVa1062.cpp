#define LOCAL

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef vector<char> Stacks;
typedef Stacks::iterator MyIt;

bool readNewCase(string& str);
size_t computeAns(const string& str);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	string str;
	int kase = 1;
	size_t ans;
	while (readNewCase(str)) {
		ans = computeAns(str);
		cout << "Case " << kase++ << ": " << ans << '\n';
	}
	return 0;
}

bool readNewCase(string& str) {
	cin >> str;
	return ("end" != str);
}

size_t computeAns(const string& str) {
	Stacks stacks;
	stacks.push_back(str.front());
	for (size_t i = 1; i < str.size(); ++i) {
		MyIt it = stacks.begin();
		for (; stacks.end() != it; ++it) {
			if (*it >= str[i]) {
				*it = str[i];
				break;
			}
		}
		if (stacks.end() == it) {
			stacks.push_back(str[i]);
			sort(stacks.begin(), stacks.end());
		}
	}
	return stacks.size();
}
