#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	while ((cin >> a >> b) && (a + b >= 0)) {
		if (a < b) {
			swap(a, b);
		}
		cout << min((a - b), (100 - (a - b))) << endl;
	}
	return 0;
}