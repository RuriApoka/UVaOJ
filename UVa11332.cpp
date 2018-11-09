#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	int sum;
	char t[11];
	string str;
	while (cin >> str) {
		if (1 == str.size()) {
			if ('0' == str[0]) {
				break;
			}
			else {
				cout << str[0] << endl;
			}
		}
		else {
			while (1 != str.size()) {
				sum = 0;
				for (size_t i = 0; i < str.size(); ++i) {
					sum += str[i] - '0';
				}
				sprintf(t, "%d", sum);
				str = t;
			}
			cout << str[0] << endl;
		}
	}
	return 0;
}