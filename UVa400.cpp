#define LOCAL

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

const int CharactersPerLine = 60;

bool initSuccessful(vector<string>& list, int& max_len);
void computeArguments(const vector<string>& list, const int max_len, int& r, int& c);
void printAnswer(vector<string>& list, const string& dash, const int max_len, const int r, const int c);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	vector<string> list;
	list.reserve(100);
	string dash(CharactersPerLine, '-');
	int max_len;
	while (initSuccessful(list, max_len)) {
		int r, c;
		computeArguments(list, max_len, r, c);
		printAnswer(list, dash, max_len, r, c);
	}
	return 0;
}

bool initSuccessful(vector<string>& list, int& max_len) {
	int total;
	if (cin >> total) {
		list.clear();
		max_len = 0;
		string t;
		for (int i = 0; i < total; ++i) {
			cin >> t;
			list.push_back(t);
			max_len = (max_len > t.size()) ? max_len : t.size();
		}
		sort(list.begin(), list.end());
		return true;
	}
	else {
		return false;
	}
}

void computeArguments(const vector<string>& list, const int max_len, int& r, int& c) {
	c = (CharactersPerLine + 2) / (max_len + 2);
	r = list.size() / c;
	r += (0 == (list.size() % c)) ? 0 : 1;
}

void printAnswer(vector<string>& list, const string& dash, const int max_len, const int r, const int c) {
	cout << dash << endl;
	int space = r * c - list.size();
	for (int i = 0; i < space; ++i) {
		list.push_back(string());
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < (c - 1); ++j) {
			cout << setiosflags(ios::left) << setfill(' ') << setw(max_len + 2) << list[i + r * j];
		}
		cout.width(max_len);
		cout << setiosflags(ios::left) << setfill(' ') << setw(max_len) << list[i + r * (c - 1)] << endl;
	}
}