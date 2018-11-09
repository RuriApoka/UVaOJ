#define LOCAL

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int number;
	int mid = 0;
	vector<int> nums;
	nums.reserve(10000);
	while (1) {
		if (EOF != scanf("%d", &number)) {
			nums.push_back(number);
			nth_element(nums.begin(), nums.begin() + mid, nums.end());
			printf("%d\n", nums[mid]);
		}
		else {
			break;
		}
		if (EOF != scanf("%d", &number)) {
			++mid;
			nums.push_back(number);
			partial_sort(nums.begin(), nums.begin() + mid + 1, nums.end());
			printf("%d\n", (nums[mid - 1] + nums[mid]) / 2);
		}
		else {
			break;
		}
	}
	return 0;
}