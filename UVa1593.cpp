#define LOCAL

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

typedef vector<size_t> Len;
typedef vector<string> Line;
typedef vector<Line> Lines;

int readLines(Lines& lines, Len& len);
void printCodes(const Lines& lines, const Len& len, int nums);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	Len len;
	Lines lines;
	lines.resize(1000);
	printCodes(lines, len, readLines(lines, len));
	return 0;
}

int readLines(Lines& lines, Len& len) {
	string str;
	int i = 0;
	while (getline(cin, str)) {
		stringstream ss(str);
		while (ss >> str) {
			lines[i].push_back(str);
			if (lines[i].size() > len.size()) {
				len.push_back(lines[i].back().size());
			}
			else {
				len[lines[i].size() - 1] = max(len[lines[i].size() - 1], lines[i].back().size());
			}
		}
		++i;
	}
	return i;
}

void printCodes(const Lines& lines, const Len& len, int nums) {
	for (int i = 0; i < nums; ++i) {
		int upper = lines[i].size() - 1;
		for (int j = 0; j < upper; ++j) {
			cout << lines[i][j];
			if (lines[i][j].size() < len[j]) {
				for (int k = len[j] - lines[i][j].size(); k > 0; --k) {
					cout << ' ';
				}
			}
			cout << ' ';
		}
		cout << lines[i].back() << endl;
	}
}