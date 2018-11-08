#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

string normalize(string& word);

int main(void) {
	FILE *a, *b;
	freopen_s(&a, "input.txt", "r", stdin);
	//freopen_s(&b, "output.txt", "w", stdout);
	string word;
	vector<string> words;
	map<string, bool> unique;

	while ((cin >> word) && (word != "#")) {
		words.push_back(word);
		string t = normalize(word);
		//根据规范化后的单词是否存在设定值
		unique[t] = (unique.find(t) == unique.end()) ? true : false;
	}

	vector<string> ans;
	for (auto it = words.begin(); it != words.end(); ++it) {
		if (unique[normalize(*it)]) {
			ans.push_back(*it);
		}
	}
	sort(ans.begin(), ans.end());
	for (auto it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}

string normalize(string & word)
{
	string t(word);

	for (size_t i = 0; i < t.length(); i++) {
		t[i] = tolower(t[i]);
	}
	sort(t.begin(), t.end());

	return string(t);
}
