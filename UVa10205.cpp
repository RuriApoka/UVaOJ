#define LOCAL

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
using namespace std;

typedef array<int, 52> Cards;
typedef Cards Shuffle;
typedef vector<Shuffle> Shuffles;
typedef vector<int> Excute;

const int N = 100;
const int NUMS = 52;
const int PERSUIT = 13;
const array<string, 5> SUIT = { "Clubs", "Diamonds", "Hearts", "Spades" };
const array<string, 13> CARDS = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

void readNewCase(Shuffles& shuffles, Excute& excute);
inline void myClear() { while ('\n' != cin.get()); }
inline void initCards(Cards& source);
void shuffle(Cards& source, const Shuffles& shuffles, const Excute& excute);
void printAns(const Cards& cards, bool& first_case);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	Cards source;
	Shuffles shuffles;
	shuffles.reserve(N);
	Excute excute;
	excute.reserve(N);
	bool first_case = true;
	int t;
	cin >> t;
	while (t--) {
		readNewCase(shuffles, excute);
		initCards(source);
		shuffle(source, shuffles, excute);
		printAns(source, first_case);
	}
	return 0;
}

void readNewCase(Shuffles& shuffles, Excute& excute) {
	int n;
	cin >> n;
	shuffles.resize(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < NUMS; ++j) {
			cin >> shuffles[i][j];
			shuffles[i][j]--;
		}
	}
	myClear();
	excute.clear();
	string str;
	while (getline(cin, str) && (!str.empty())) {
		excute.push_back(atoi(str.c_str()) - 1);
	}
}

void initCards(Cards& source) {
	for (size_t i = 0; i < source.size(); ++i) {
		source[i] = i;
	}
}

void shuffle(Cards& source, const Shuffles& shuffles, const Excute& excute) {
	Cards t;
	for (size_t i = 0; i < excute.size(); ++i) {
		for (size_t j = 0; j < NUMS; ++j) {
			t[j] = source[shuffles[excute[i]][j]];
		}
		source.swap(t);
	}
}

void printAns(const Cards& cards, bool& first_case) {
	if (first_case) {
		first_case = false;
	}
	else {
		cout << endl;
	}
	for (size_t i = 0; i < cards.size(); ++i) {
		cout << CARDS[cards[i] % 13] << " of " << SUIT[cards[i] / 13] << endl;
	}
}