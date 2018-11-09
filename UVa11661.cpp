#define LOCAL

#include <iostream>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int min, len, l;
	char prev, cur;
	cin >> l;
	while (0 != l) {
		cin.get();
		int i;
		for (i = 0; '.' == (cur = cin.get()); ++i) {
			;
		}
		if ('Z' != cur) {
			prev = cur;
			min = l;
			len = 1;
			for (++i; i < l; ++i) {
				cur = cin.get();
				if ('.' != cur) {
					if ('Z' == cur) {
						min = 0;
						for (++i; i < l; ++i) {
							cin.get();
						}
						break;
					}
					else if (prev != cur) {
						min = (min < len) ? min : len;
						prev = cur;
					}
					len = 1;
				}
				else {
					len++;
				}
			}
		}
		else {
			for (++i; i < l; ++i) {
				cin.get();
			}
			min = 0;
		}
		cout << min << endl;
		cin >> l;
	}
	return 0;
}