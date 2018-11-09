#define LOCAL

#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

typedef vector<char> Cards;
typedef vector<Cards> Suits;
typedef bitset<4> Stopped;

const int CARDS = 13;
const int ALLSTOPPED = 0xf;
enum STATE { NO_TRUMP = 4, PASS };
map<char, int> INDEX = { {'S', 0}, {'H', 1}, {'D', 2}, {'C', 3} };
const vector<string> ANS = { "BID S", "BID H", "BID D", "BID C", "BID NO-TRUMP", "PASS" };

bool readInfoSuccess(Suits& suits, int& points, Stopped& stopped);
int computeAns(const Suits& suits, int points, const Stopped& stopped);
bool stoppedCards(const Cards& cards);
inline int cardValue(char ch);
inline void subtractPoints(const Cards& cards, int& points);
inline void addPoints(const Cards& cards, int& points);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int ans, points;
	Suits suits;
	Stopped stopped;
	while (readInfoSuccess(suits, points, stopped)) {
		ans = computeAns(suits, points, stopped);
		cout << ANS[ans] << endl;
	}
	return 0;
}

bool readInfoSuccess(Suits& suits, int& points, Stopped& stopped) {
	suits.clear();
	suits.resize(4);
	points = 0;
	stopped = 0;
	string str;
	if (cin >> str) {
		suits[INDEX[str.back()]].push_back(str.front());
		points += cardValue(str.front());
		for (int i = 1; i < CARDS; ++i) {
			cin >> str;
			suits[INDEX[str.back()]].push_back(str.front());
			points += cardValue(str.front());
		}
		for (size_t i = 0; i < suits.size(); ++i) {
			sort(suits[i].begin(), suits[i].end());
			stopped[i] = stoppedCards(suits[i]);
		}
		return true;
	}
	else {
		return false;
	}
}

int computeAns(const Suits& suits, int points, const Stopped& stopped) {
	for (size_t i = 0; i < suits.size(); ++i) {
		subtractPoints(suits[i], points);
	}
	if ((points >= 16) && (ALLSTOPPED == stopped.to_ulong())) {
		return STATE::NO_TRUMP;
	}
	else {
		for (size_t i = 0; i < suits.size(); ++i) {
			addPoints(suits[i], points);
		}
	}
	if (points < 14) {
		return STATE::PASS;
	}
	else {
		int ans = 0;
		for (size_t i = 1; i < suits.size(); ++i) {
			if (suits[i].size() > suits[ans].size()) {
				ans = i;
			}
		}
		return ans;
	}
}

bool stoppedCards(const Cards& cards) {
	if (binary_search(cards.begin(), cards.end(), 'A') ||
		(binary_search(cards.begin(), cards.end(), 'K') && (cards.size() > 1)) ||
		(binary_search(cards.begin(), cards.end(), 'Q') && (cards.size() > 2))) {
		return true;
	}
	else {
		return false;
	}
}

int cardValue(char ch) {
	switch (ch) {
	case 'A' :
		return 4;
	case 'K':
		return 3;
	case 'Q':
		return 2;
	case 'J':
		return 1;
	default:
		return 0;
	}
}

void subtractPoints(const Cards& cards, int& points) {
	if (binary_search(cards.begin(), cards.end(), 'K') && (cards.size() == 1)) {
		points -= 1;
	}
	if (binary_search(cards.begin(), cards.end(), 'Q') && (cards.size() <= 2)) {
		points -= 1;
	}
	if (binary_search(cards.begin(), cards.end(), 'J') && (cards.size() <= 3)) {
		points -= 1;
	}
}

void addPoints(const Cards& cards, int& points) {
	if (cards.size() == 2) {
		points += 1;
	}
	else if (cards.size() < 2) {
		points += 2;
	}
}