#define LOCAL

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

const string SONG = "Happy birthday to you Happy birthday to you Happy birthday to Rujia Happy birthday to you";

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int n;
	string str;
	vector<string> people;
	cin >> n;
	people.reserve(n);
	for (int i = 0; i < n; ++i) {
		cin >> str;
		people.emplace_back(str);
	}
	stringstream ss(SONG);
	if (n > 16) {
		for (int i = 0; i < n; ++i) {
			if (ss.eof()) {
				ss = stringstream(SONG);
			}
			ss >> str;
			cout << people[i] << ": " << str << endl;
		}
	}
	for (int i = 0; ss >> str; ++i, i %= n) {
		cout << people[i] << ": " << str << endl;
	}
	return 0;
}