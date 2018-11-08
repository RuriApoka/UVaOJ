#define LOCAL

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool readNewLine(vector<char>& first, vector<char>& second);
bool isSame(vector<char>& first, vector<char>& second);

int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	vector<char> first(6);
	vector<char> second(6);
	while (readNewLine(first, second)) {
		if (isSame(first, second)) {
			cout << "TRUE" << endl;
		}
		else {
			cout << "FALSE" << endl;
		}
	}
	return 0;
}

bool readNewLine(vector<char>& first, vector<char>& second) {
	char c;
	if (cin >> c) {
		for (size_t i = 0; i < first.size(); ++i) {
			first[i] = c;
			cin >> c;
		}
		for (size_t i = 0; i < second.size(); ++i) {
			second[i] = c;
			cin >> c;
		}
		cin.unget();
		return true;
	}
	else {
		return false;
	}
}

bool isSame(vector<char>& first, vector<char>& second) {
	vector<pair<char, char> > a;
	vector<pair<char, char> > b;
	for (size_t i = 0; i < (first.size() / 2); ++i) {
		if (first[i] > first[first.size() - i - 1]) {
			a.push_back({ first[first.size() - i - 1], first[i] });
		}
		else {
			a.push_back({ first[i], first[first.size() - i - 1] });
		}
		if (second[i] > second[second.size() - i - 1]) {
			b.push_back({ second[second.size() - i - 1], second[i] });
		}
		else {
			b.push_back({ second[i], second[second.size() - i - 1] });
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}