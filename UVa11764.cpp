#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, kase = 1;
	int high, low;
	vector<int> wall;
	cin >> n;
	while (n--) {
		cin >> m;
		wall.resize(m);
		for (int i = 0; i < m; ++i) {
			cin >> wall[i];
		}
		high = low = 0;
		for (int i = 1; i < m; ++i) {
			if (wall[i] > wall[i - 1]) {
				high++;
			}
			else if (wall[i] < wall[i - 1]) {
				low++;
			}
		}
		cout << "Case " << kase++ << ": " << high << ' ' << low << endl;
	}
	return 0;
}