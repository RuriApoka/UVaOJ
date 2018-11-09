#define LOCAL

#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef map<string, string> MyType;
typedef MyType::iterator MyIt;

const string UNKNOW = "UNKNOWN";
const string END = "#";

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	string str;
	MyType my = { {"HELLO", "ENGLISH"}, {"HOLA", "SPANISH"}, {"HALLO", "GERMAN"}, {"BONJOUR", "FRENCH"}, {"CIAO", "ITALIAN"}, {"ZDRAVSTVUJTE", "RUSSIAN"} };
	MyIt it, end = my.end();
	for (int i = 1; getline(cin, str) && (str != END); ++i) {
		cout << "Case " << i << ": ";
		if (end != (it = my.find(str))) {
			cout << it->second << endl;
		}
		else {
			cout << UNKNOW << endl;
		}
	}
	return 0;
}