#include <iostream>
#include <string>
#include <regex>
using namespace std;

const regex one[3] = { regex("[a-z]ne", regex::basic), regex("o[a-z]e", regex::basic), regex("on[a-z]", regex::basic) };

int main() {
	int n;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		if (str.size() == 5) {
			cout << 3 << endl;
		}
		else {
			int i;
			for (i = 0; i < 3; ++i) {
				if (regex_match(str, one[i])) {
					cout << 1 << endl;
					break;
				}
			}
			if (3 == i) {
				cout << 2 << endl;
			}
		}
	}
	return 0;
}