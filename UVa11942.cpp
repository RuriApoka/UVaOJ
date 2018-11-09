#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int n;
	vector<int> nums(10);
	cout << "Lumberjacks:" << endl;
	cin >> n;
	while (n--) {
		for (int i = 0; i < 10; ++i) {
			cin >> nums[i];
		}
		if (is_sorted(nums.begin(), nums.end(), less<int>())
			|| is_sorted(nums.begin(), nums.end(), greater<int>())) {
			cout << "Ordered" << endl;
		}
		else {
			cout << "Unordered" << endl;
		}
	}
	return 0;
}