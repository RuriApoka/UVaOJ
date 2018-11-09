#define LOCAL

#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef map<string, int> Input;
typedef map<int, string> Result;

void initMyMap(Input& input, Result& result);
inline bool readNewCase(int& n) { cin >> n; return (0 != n); }
int computeAns(Input& input, int n);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	Input input;
	Result result;
	initMyMap(input, result);
	int n;
	while (readNewCase(n)) {
		cout << result[computeAns(input, n)] << endl;
	}
	return 0;
}

void initMyMap(Input& input, Result& result) {
	input.insert({ "No", 0 });
	input.insert({ "+x", 1 });
	result.insert({ 1, "+x" });
	input.insert({ "+y", 2 });
	result.insert({ 2, "+y" });
	input.insert({ "+z", 3 });
	result.insert({ 3, "+z" });
	input.insert({ "-x", -1 });
	result.insert({ -1, "-x" });
	input.insert({ "-y", -2 });
	result.insert({ -2, "-y" });
	input.insert({ "-z", -3 });
	result.insert({ -3, "-z" });
}

int computeAns(Input& input, int n) {
	int coefficient = 1, ans = 0;
	int x;
	string t;
	for (int i = 1; i < n; ++i) {
		cin >> t;
		if (0 != (x = input[t])) {
			if (0 == ans) {
				ans = x;
			}
			else if (x == ans) {
				ans = 0;
				coefficient *= -1;
			}
			else if (-x == ans) {
				ans = 0;
			}
		}
	}
	return ((0 == ans) ? coefficient : coefficient * ans);
}