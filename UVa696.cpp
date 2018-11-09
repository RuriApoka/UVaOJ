#define LOCAL

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int r, c;
	int a, b;
	while (cin >> r >> c) {
		if (r | c) {
			a = r;
			b = c;
			if (a > b) {
				swap(a, b);
			}
			if (a < 3) {
				switch (a) {
				case 0:
					cout << 0;
					break;
				case 1:
					cout << b;
					break;
				default:
					switch (b % 4) {
					case 0:
						cout << b;
						break;
					case 1:
						cout << b / 4 * 4 + 2;
						break;
					default:
						cout << (b / 4 + 1) * 4;
						break;
					}
					break;
				}
			}
			else {
				cout << (r * c + 1) / 2;
			}
			cout << " knights may be placed on a "
				<< r << " row " << c << " column board." << endl;
		}
		else {
			break;
		}
	}
	return 0;
}