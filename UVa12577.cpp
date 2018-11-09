#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string str;
	const string END = "*";
	map<string, string> result = { {"Hajj", "Hajj-e-Akbar"}, {"Umrah", "Hajj-e-Asghar"} };
	int i = 1;
	while ((cin >> str) && (END != str)) {
		cout << "Case " << i++ << ": " << result[str] << endl;
	}
	return 0;
}