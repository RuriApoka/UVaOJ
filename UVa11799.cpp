#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, size;
	vector<int> students;
	students.reserve(100);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> size;
		students.resize(size);
		for (int j = 0; j < size; ++j) {
			cin >> students[j];
		}
		sort(students.begin(), students.end());
		cout << "Case " << i << ": " << students.back() << endl;
	}
	return 0;
}