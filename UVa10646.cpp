#define LOCAL

#include <iostream>
#include <array>
#include <utility>
using namespace std;

typedef pair<char, char> Card;
typedef array<Card, 27> Pile;
typedef array<Card, 25> Hand;

void readCards(Pile& pile, Hand& hand);
inline void myClear() { while ('\n' != cin.get()); }
int simulate(Pile& pile, Hand& hand, int& pile_size);
inline int getCardValue(char ch);
inline void printAns(const Pile& pile, const Hand& hand, int pile_size, int y, int kase);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	Pile pile;
	Hand hand;
	int pile_size, y, t;
	cin >> t;
	myClear();
	for (int i = 0; i < t; ++i) {
		readCards(pile, hand);
		y = simulate(pile, hand, pile_size);
		printAns(pile, hand, pile_size, y, i + 1);
	}
	return 0;
}

void readCards(Pile& pile, Hand& hand) {
	for (int i = 0; i < 27; ++i) {
		cin >> pile[i].first >> pile[i].second;
		cin.get();
	}
	for (int i = 0; i < 25; ++i) {
		cin >> hand[i].first >> hand[i].second;
		cin.get();
	}
}

int simulate(Pile& pile, Hand& hand, int& pile_size) {
	int y = 0;
	int x;
	pile_size = pile.size();
	for (int i = 0; i < 3; ++i) {
		x = getCardValue(pile[pile_size - 1].first);
		y += x;
		pile_size -= 1;
		pile_size -= (10 - x);
	}
	return y;
}

int getCardValue(char ch) {
	switch (ch) {
	case 'T':
	case 'J':
	case 'Q':
	case 'K':
	case 'A':
		return 10;
	default:
		return (ch - '0');
	}
}

void printAns(const Pile& pile, const Hand& hand, int pile_size, int y, int kase) {
	cout << "Case " << kase << ": ";
	if (y > pile_size) {
		cout << hand[y - pile_size - 1].first << hand[y - pile_size - 1].second << endl;
	}
	else {
		cout << pile[pile_size - 1].first << pile[pile_size - 1].second << endl;
	}
}