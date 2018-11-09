#include <iostream>
#include <string>
using namespace std;

const string DONATE = "donate";

int main() {
	ios::sync_with_stdio(false);
	int n, k = 0, t;
	cin >> n;
	string str;
	while (n--) {
		cin >> str;
		if (DONATE == str) {
			cin >> t;
			k += t;
		}
		else {
			cout << k << endl;
		}
	}
	return 0;
}