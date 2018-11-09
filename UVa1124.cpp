#include <iostream>
#include <string>
using namespace std;

int main() {
	string t;
	while (getline(cin, t) && !t.empty()) {
		cout << t << endl;
	}
	return 0;
}