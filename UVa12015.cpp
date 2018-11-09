#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, kases = 1;
	int relevance, max;
	string str;
	vector<pair<int, string> > pair;
	pair.reserve(10);
	cin >> n;
	while (n--) {
		max = 0;
		pair.clear();
		for (int i = 0; i < 10; ++i) {
			cin >> str >> relevance;
			max = (max > relevance) ? max : relevance;
			pair.push_back({ relevance, str });
		}
		cout << "Case #" << kases++ << ':' << endl;
		for (int i = 0; i < 10; ++i) {
			if (pair[i].first == max) {
				cout << pair[i].second << endl;
			}
		}
	}
	return 0;
}