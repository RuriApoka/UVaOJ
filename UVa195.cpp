#define LOCAL

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	string str;
	while (t--) {
		cin >> str;
		sort(str.begin(), str.end(),
			[](const char& a, const char& b) -> bool { return ((tolower(a) == tolower(b)) ? (a < b) : (tolower(a) < tolower(b))); });
		do {
			cout << str << endl;
		} while (next_permutation(str.begin(), str.end(),
			[](const char& a, const char& b) -> bool { return ((tolower(a) == tolower(b)) ? (a < b) : (tolower(a) < tolower(b))); }));
	}
	return 0;
}