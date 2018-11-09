#define LOCAL

#include <iostream>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;

bool ReadInfo(int weight[], int& dimension);
void ComputePotency(const int weight[], int potency[], const int dimension);
int ComputeAnswer(const int potency[], const int dimension);
inline void Clear(int a[], int len) { memset(a, 0, len * sizeof(int)); };

const int MAX_DIMENSION = 14;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	int weight[1 << MAX_DIMENSION] = { 0 };
	int potency[1 << MAX_DIMENSION] = { 0 };
	int dimension;
	while (ReadInfo(weight, dimension)) {
		ComputePotency(weight, potency, dimension);
		int ans = ComputeAnswer(potency, dimension);
		Clear(weight, (1 << dimension));
		Clear(potency, (1 << dimension));
		cout << ans << endl;
	}
	return 0;
}

bool ReadInfo(int weight[], int& dimension) {
	cin >> dimension;
	if (cin.eof()) {
		return false;
	}
	else {
		const int conners = (1 << dimension);
		for (int i = 0; i < conners; ++i) {
			cin >> weight[i];
		}
		return true;
	}
}

void ComputePotency(const int weight[], int potency[], const int dimension) {
	bitset<MAX_DIMENSION> coordinate;
	const int conners = (1 << dimension);
	for (int i = 0; i < conners; ++i) {
		coordinate = i;
		for (int j = 0; j < dimension; ++j) {
			coordinate.flip(j);
			potency[i] += weight[coordinate.to_ulong()];
			coordinate.flip(j);
		}
	}
}

int ComputeAnswer(const int potency[], const int dimension) {
	bitset<MAX_DIMENSION> coordinate;
	const int conners = (1 << dimension);
	int ans = 0;
	for (int i = 0; i < conners; ++i) {
		coordinate = i;
		for (int j = 0; j < dimension; ++j) {
			coordinate.flip(j);
			ans = max(ans, potency[i] + potency[coordinate.to_ulong()]);
			coordinate.flip(j);
		}
	}
	return ans;
}