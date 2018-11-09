#define LOCAL

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
using namespace std;

typedef vector<vector<int> > Table;
typedef pair<int, int> Log;

bool initSuccessful(Table& table);
bool isPNF(Table& table, vector<Log>& ans);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	Table table;
	while (initSuccessful(table)) {
		vector<Log> ans(2);
		if (isPNF(table, ans)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
			for (size_t i = 0; i < ans.size(); ++i) {
				cout << ans[i].first << ' ' << ans[i].second << endl;
			}
		}
	}
	return 0;
}

bool initSuccessful(Table& table) {
	int m, n;
	if (cin >> n >> m) {
		cin.get();
		table.clear();
		table.resize(n);
		for (int i = 0; i < n; ++i) {
			table[i].resize(m);
		}
		string t;
		int index = 0;
		char delim;
		map<string, int> ref;
		map<string, int>::iterator it;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				delim = (j == (m - 1)) ? '\n' : ',';
				getline(cin, t, delim);
				it = ref.find(t);
				if (ref.end() == it) {
					ref.insert({ t, ++index });
					table[i][j] = index;
				}
				else {
					table[i][j] = it->second;
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
}

bool isPNF(Table& table, vector<Log>& ans) {
	map<Log, int> log;
	map<Log, int>::iterator it;
	for (size_t c1 = 0; c1 < table[0].size(); ++c1) {
		for (size_t c2 = c1 + 1; c2 < table[0].size(); ++c2) {
			log.clear();
			for (size_t r = 0; r < table.size(); ++r) {
				it = log.find({ table[r][c1], table[r][c2] });
				if (log.end() == it) {
					log.insert({ { table[r][c1], table[r][c2] }, int(r + 1) });
				}
				else {
					ans[0] = { it->second, r + 1};
					ans[1] = { c1 + 1, c2 + 1 };
					return false;
				}
			}
		}
	}
	return true;
}