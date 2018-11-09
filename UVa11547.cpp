#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	int n, t;
	char r[8];
	string str;
	cin >> t;
	while (t--) {
		cin >> n;
		sprintf(r, "%d", 315 * n + 36962);
		str = r;
		cout << *(str.end() - 2) << endl;
	}
	return 0;
}