#define LOCAL

#include <iostream>
#include <array>
using namespace std;

typedef array<int, 13> Suit;		//分别对应2~A
typedef array<Suit, 4> Player;		//分别对应C、D、S、H
typedef array<Player, 4> Players;	//分别对应S、W、N、E

const array<char, 4> SUIT = { 'C', 'D', 'S', 'H' };
const array<char, 4> PLAYERS = { 'S', 'W', 'N', 'E' };
const array<char, 13> CARD = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };

bool readInfoSuccess(Players& players);
inline void initArray(Players& players);
inline int getPlayerIndex(char ch);
inline int getSuitIndex(char ch);
inline int getValueIndex(char ch);
inline void myClear() { while ('\n' != cin.get()); }
void printAns(const Players& players);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	Players players;
	while (readInfoSuccess(players)) {
		printAns(players);
	}
	return 0;
}

bool readInfoSuccess(Players& players) {
	char player;
	player = cin.get();
	if ('#' != player) {
		myClear();
		initArray(players);
		int index = getPlayerIndex(player);
		++index;
		char suit, value;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 26; ++index, ++j) {
				cin.get(suit).get(value);
				players[index % 4][getSuitIndex(suit)][getValueIndex(value)] = 1;
			}
			myClear();
		}
		return true;
	}
	else {
		return false;
	}
}

void initArray(Players& players) {
	for (size_t i = 0; i < players.size(); ++i) {
		for (size_t j = 0; j < players[i].size(); ++j) {
			players[i][j].fill(0);
		}
	}
}

int getPlayerIndex(char ch) {
	switch (ch) {
	case 'S':
		return 0;
	case 'W':
		return 1;
	case 'N':
		return 2;
	default:
		return 3;
	}
}

int getSuitIndex(char ch) {
	switch (ch) {
	case 'C':
		return 0;
	case 'D':
		return 1;
	case 'S':
		return 2;
	default:
		return 3;
	}
}

int getValueIndex(char ch) {
	switch (ch) {
	case 'T':
		return 8;
	case 'J':
		return 9;
	case 'Q':
		return 10;
	case 'K':
		return 11;
	case 'A':
		return 12;
	default:
		return (ch - '0' - 2);
	}
}

void printAns(const Players& players) {
	for (size_t i = 0; i < players.size(); ++i) {
		cout << PLAYERS[i] << ':';
		for (size_t j = 0; j < players[i].size(); ++j) {
			for (size_t k = 0; k < players[i][j].size(); ++k) {
				if (1 == players[i][j][k]) {
					cout << ' ' << SUIT[j] << CARD[k];
				}
			}
		}
		cout << endl;
	}
}