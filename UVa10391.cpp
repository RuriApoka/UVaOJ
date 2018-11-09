#define LOCAL

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

typedef set<string> MyType;
typedef MyType::iterator MyIt;

void init(vector<MyType>& dictionary);
void solve(vector<MyType>& dictionary);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	vector<MyType> dictionary(26);
	init(dictionary);
	solve(dictionary);
	return 0;
}

void init(vector<MyType>& dictionary) {
	string t;
	while (cin >> t) {
		dictionary[t[0] - 'a'].insert(t);
	}
}

void solve(vector<MyType>& dictionary) {
	for (size_t i = 0; i < dictionary.size(); ++i) {
		MyIt end = dictionary[i].end();
		for (MyIt it = dictionary[i].begin(); it != end; ++it) {
			for (size_t j = 1; j < it->size(); ++j) {
				int alpha = *(it->begin() + j) - 'a';
				if ((dictionary[i].find(string(it->begin(), it->begin() + j)) != end)
					&& (dictionary[alpha].find(string(it->begin() + j, it->end())) != dictionary[alpha].end())) {
					cout << *it << endl;
					break;
				}
			}
		}
	}
}