#define LOCAL

#include <iostream>
#include <list>
#include <cctype>
using namespace std;

typedef list<char> myType;
typedef myType::iterator myIt;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	char ch;
	int kases = 0;
	while (1) {
		if (kases++) {
			cout << endl;
		}
		myType text;
		myIt it = text.begin();
		while (('\n' != (ch = cin.get())) && !cin.eof()) {
			if (isalpha(ch) || ('_' == ch)) {
				it = ++text.insert(it, ch);
			}
			else if ('[' == ch) {
				it = text.begin();
			}
			else {
				it = text.end();
			}
		}
		myIt end = text.end();
		for (it = text.begin(); it != end; ++it) {
			cout.put(*it);
		}
		if (cin.eof()) {
			break;
		}
	}
	return 0;
}