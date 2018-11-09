#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int b, n;
	int debtor, creditor, value;
	vector<int> bank;
	while ((cin >> b >> n) && (b | n)) {
		bank.resize(b);
		for (int i = 0; i < b; ++i) {
			cin >> bank[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> debtor >> creditor >> value;
			bank[debtor - 1] -= value;
			bank[creditor - 1] += value;
		}
		sort(bank.begin(), bank.end());
		cout.put((bank[0] < 0) ? 'N' : 'S');
		cout.put('\n');
	}
	return 0;
}