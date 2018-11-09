#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
	int n, m, limit, max, cur;
	int t, kases = 1;
	bool blown;
	vector<pair<int, bool> > machines;
	machines.reserve(20);
	while ((cin >> n >> m >> limit) && (n | m | limit)) {
		machines.clear();
		for (int i = 0; i < n; ++i) {
			cin >> t;
			machines.push_back({t, false});
		}
		max = cur = 0;
		blown = false;
		for (int i = 0; i < m; ++i) {
			cin >> t;
			if (machines[t - 1].second) {
				cur -= machines[t - 1].first;
				machines[t - 1].second = !machines[t - 1].second;
			}
			else {
				if ((cur + machines[t - 1].first) > limit) {
					blown = true;
					for (++i; i < m; ++i) {
						cin >> t;
					}
					break;
				}
				else {
					cur += machines[t - 1].first;
					max = (max > cur) ? max : cur;
					machines[t - 1].second = !machines[t - 1].second;
				}
			}
		}
		cout << "Sequence " << kases++ << endl;
		if (blown) {
			cout << "Fuse was blown." << endl;
		}
		else {
			cout << "Fuse was not blown." << endl
				<< "Maximal power consumption was " << max << " amperes." << endl;
		}
		cout.put('\n');
	}
	return 0;
}