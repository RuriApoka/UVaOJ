#define LOCAL

#include <iostream>
#include <vector>
using namespace std;

bool init(vector<int>& nums);
bool isJolly(vector<int>& nums, vector<bool>& visited);

int main(void) {
#ifdef LOCAL
	FILE *a;
	freopen_s(&a, "input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	vector<int> nums;
	vector<bool> visited;
	while (init(nums)) {
		if (isJolly(nums, visited)) {
			cout << "Jolly" << endl;
		}
		else {
			cout << "Not jolly" << endl;
		}
	}
	return 0;
}

bool init(vector<int>& nums) {
	int n;
	if (cin >> n) {
		nums.resize(n);
		int t;
		for (int i = 0; i < n; ++i) {
			cin >> t;
			nums[i] = t;
		}
		return true;
	}
	else {
		return false;
	}
}

bool isJolly(vector<int>& nums, vector<bool>& visited) {
	visited.clear();
	visited.resize(nums.size(), false);
	int t;
	int max = nums.size() - 1;
	bool is_jolly = true;
	for (size_t i = 1; i < nums.size(); i++) {
		if (nums[i] == nums[i - 1]) {
			is_jolly = false;
			break;
		}
		else {
			t = abs(nums[i] - nums[i - 1]);
			if ((t > max) || visited[t]) {
				is_jolly = false;
				break;
			}
			else {
				visited[t] = true;
			}
		}
	}
	return is_jolly;
}