#define LOCAL

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

typedef vector<int> Numbers;
typedef set<long long> Sequence;

void readInNumbers(Numbers& numbers);
bool isLoop(Numbers& numbers);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int kases;
	cin >> kases;
	while (kases--) {
		Numbers numbers;
		readInNumbers(numbers);
		if (isLoop(numbers)) {
			cout << "LOOP" << endl;
		}
		else {
			cout << "ZERO" << endl;
		}
	}
	return 0;
}

void readInNumbers(Numbers& numbers) {
	int n;
	cin >> n;
	numbers.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}
}

bool isLoop(Numbers& numbers) {
	Sequence sequence;
	size_t upper = numbers.size() - 1;
	long long value = -1;
	int t;
	while ((0 != value) && (sequence.end() == sequence.find(value))) {
		sequence.insert(value);
		value = 0;
		t = numbers[0];
		for (size_t i = 0; i < upper; ++i) {
			numbers[i] = abs(numbers[i] - numbers[i + 1]);
			value += numbers[i] * (long long)(pow(10, upper - i));
		}
		numbers[upper] = abs(t - numbers[upper]);
		value += numbers[upper];
	}
	return (0 != value);
}