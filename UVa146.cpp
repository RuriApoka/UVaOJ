#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	while (getline(cin, str) && ('#' != str[0])) {
		if (next_permutation(str.begin(), str.end())) {
			cout << str << endl;
		}
		else {
			cout << "No Successor" << endl;
		}
	}
	return 0;
}