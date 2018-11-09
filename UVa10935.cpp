#define LOCAL

#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

const string str1 = "Discarded cards:";
const string str2 = "Remaining card:";

void myInit(list<int>& cards, int n);
void simulate(vector<int>& discard, list<int>& cards);
void printAns(const vector<int>& discard, list<int>& cards);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int n;
	cin >> n;
	while (n != 0) {
		vector<int> discard;
		discard.reserve(n);
		list<int> cards;

		myInit(cards, n);
		simulate(discard, cards);
		printAns(discard, cards);
		cin >> n;
	}
	return 0;
}

void myInit(list<int>& cards, int n) {
	for (int i = 1; i <= n; ++i) {
		cards.push_back(i);
	}
}

void simulate(vector<int>& discard, list<int>& cards) {
	while (cards.size() > 1) {
		discard.push_back(cards.front());
		cards.pop_front();
		cards.push_back(cards.front());
		cards.pop_front();
	}
}

void printAns(const vector<int>& discard, list<int>& cards) {
	cout << str1;
	if (discard.size() > 0) {
		cout << ' ' << discard[0];
	}
	for (size_t i = 1; i < discard.size(); ++i) {
		cout << ',' << ' ' << discard[i];
	}
	cout << endl << str2 << ' ' << cards.front() << endl;
}