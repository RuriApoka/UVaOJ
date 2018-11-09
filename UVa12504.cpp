#define LOCAL

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
using namespace std;

typedef map<string, string> Dictionary;
typedef Dictionary::const_iterator DicIt;
typedef set<string> Change;
typedef Change::const_iterator ChgIt;
typedef vector<Change> Answer;

void readDictionary(Dictionary& dictionary);
void computeAnswer(const Dictionary& old_dictionary, const Dictionary& new_dictionary, Answer& answer);
void printAnswer(const Answer& answer);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	int n;
	cin >> n;
	while (n--) {
		Dictionary old_dictionary, new_dictionary;
		readDictionary(old_dictionary);
		readDictionary(new_dictionary);
		Answer answer;
		answer.resize(3);
		computeAnswer(old_dictionary, new_dictionary, answer);
		printAnswer(answer);
	}
	return 0;
}

void readDictionary(Dictionary& dictionary) {
	string t;
	cin >> t;
	t.erase(t.begin());
	t.erase(t.end() - 1);
	stringstream ss(t);
	string key, value;
	while (getline(ss, key, ':') && ("" != key)) {
		getline(ss, value, ',');
		dictionary.insert({ key, value });
	}
}

void computeAnswer(const Dictionary& old_dictionary, const Dictionary& new_dictionary, Answer& answer) {
	DicIt old_it = old_dictionary.cbegin();
	DicIt new_it = new_dictionary.cbegin();
	while ((old_it != old_dictionary.cend()) && (new_it != new_dictionary.cend())) {
		if (old_it->first != new_it->first) {
			if (old_it->first > new_it->first) {
				answer[0].insert(new_it->first);
				++new_it;
			}
			else {
				answer[1].insert(old_it->first);
				++old_it;
			}
		}
		else {
			if (old_it->second != new_it->second) {
				answer[2].insert(old_it->first);
			}
			++old_it;
			++new_it;
		}
	}
	for (; old_it != old_dictionary.cend(); ++old_it) {
		answer[1].insert(old_it->first);
	}
	for (; new_it != new_dictionary.cend(); ++new_it) {
		answer[0].insert(new_it->first);
	}
}

void printAnswer(const Answer& answer) {
	bool changed = false;
	map<int, char> sign = { {0, '+'}, {1, '-'}, {2, '*'} };
	for (size_t i = 0; i < answer.size(); ++i) {
		if (0 != answer[i].size()) {
			changed = true;
			ChgIt it = answer[i].cbegin();
			cout << sign[i] << *it;
			for (++it; it != answer[i].cend(); ++it) {
				cout << ',' << *it;
			}
			cout << endl;
		}
	}
	if (!changed) {
		cout << "No changes" << endl;
	}
	cout << endl;
}