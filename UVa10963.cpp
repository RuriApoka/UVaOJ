#include <iostream>
using namespace std;

int main() {
	int n, m, a, b, distance;
	int kase = 0;
	bool can;
	cin >> n;
	while (n--) {
		can = true;
		cin >> m;
		cin >> a >> b;
		distance = a - b;
		while (--m) {
			cin >> a >> b;
			if (distance != (a - b)) {
				can = false;
				while (--m) {
					cin >> a >> b;
				}
				break;
			}
		}
		if (kase++) {
			cout.put('\n');
		}
		if (can) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}