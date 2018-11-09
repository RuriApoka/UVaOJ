#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	string str;
	const regex result[3] = { {regex(".*35")}, {regex("9.*4")}, {regex("190.*")} };
	cin >> n;
	while (n--) {
		cin >> str;
		if (str.size() < 3) {
			cout.put('+');
		}
		else {
			int i;
			for (i = 0; i < 3; ++i) {
				if (regex_match(str, result[i])) {
					break;
				}
			}
			switch (i) {
			case 0:
				cout.put('-');
				break;
			case 1:
				cout.put('*');
				break;
			default:
				cout.put('?');
				break;
			}
		}
		cout.put('\n');
	}
	return 0;
}