#define LOCAL

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool readTarget(vector<int>& target);
bool canReach(const vector<int>& target);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int kases = 0;
	while (0 != n) {
		vector<int> target(n);
		while (readTarget(target)) {
			cout << (canReach(target) ? "Yes" : "No") << endl;
		}
		cout << endl;
		cin >> n;
	}
	return 0;
}

bool readTarget(vector<int>& target) {
	cin >> target[0];
	if (0 == target[0]) {
		return false;
	}
	else {
		for (size_t i = 1; i < target.size(); ++i) {
			cin >> target[i];
		}
		return true;
	}
}

bool canReach(const vector<int>& target) {
	stack<int> my_stack;
	int n = target.size();
	int j = 0;
	for (int i = 1; (i <= n) && (j < n); ++i) {
		my_stack.push(i);
		while (!my_stack.empty() && (my_stack.top() == target[j])) {
			++j;
			my_stack.pop();
		}
	}
	return my_stack.empty();
}