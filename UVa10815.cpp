#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <cstdio>

using namespace std;

int main(void) {
	FILE *a, *b;
	freopen_s(&a, "input.txt", "r", stdin);
	freopen_s(&b, "output.txt", "w", stdout);
	char c;
	bool new_words = false;
	string words;
	set<string> dictionary;
	while ((c = getchar()) != EOF) {
		if (isalpha(c)) {
			new_words = true;
			words.push_back(tolower(c));
		}
		else if (new_words) {
			new_words = false;
			dictionary.insert(words);
			words.clear();
		}
	}

	for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}