#define LOCAL

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

typedef array<int, 2> Prince;
typedef array<int, 3> Princess;
typedef array<int, 53> Card;

bool readInfoSuccess(Prince& prince, Princess& princess, Card& card);
inline void initCard(Card& card) { card.fill(0); }
int computeAns(const Prince& prince, const Princess& princess, const Card& card);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	Prince prince;
	Princess princess;
	Card card;
	while (readInfoSuccess(prince, princess, card)) {
		cout << computeAns(prince, princess, card) << endl;
	}
	return 0;
}

bool readInfoSuccess(Prince& prince, Princess& princess, Card& card) {
	cin >> princess[0];
	if (0 == princess[0]) {
		return false;
	}
	else {
		initCard(card);
		card[princess[0]] = 1;
		for (int i = 1; i < 3; ++i) {
			cin >> princess[i];
			card[princess[i]] = 1;
		}
		for (int i = 0; i < 2; ++i) {
			cin >> prince[i];
			card[prince[i]] = 1;
		}
		sort(princess.begin(), princess.end());
		sort(prince.begin(), prince.end());
		return true;
	}
}

int computeAns(const Prince& prince, const Princess& princess, const Card& card) {
	//侍者发的牌为王子手中最小的
	if (prince[0] > princess[2]) {
		for (int i = 1; i < prince[0]; ++i) {
			if (0 == card[i]) {
				return i;
			}
		}
	}
	else {
		for (int i = princess[1] + 1; i < prince[0]; ++i) {
			if (0 == card[i]) {
				return i;
			}
		}
	}
	//侍者发的牌为王子手中中等的
	if (prince[0] > princess[1]) {
		for (int i = prince[0] + 1; i < prince[1]; ++i) {
			if (0 == card[i]) {
				return i;
			}
		}
	}
	else {
		for (int i = princess[2] + 1; i < prince[1]; ++i) {
			if (0 == card[i]) {
				return i;
			}
		}
	}
	//侍者发的牌为王子手中最大的
	if ((prince[1] > princess[2]) || (prince[0] > princess[1])) {
		for (int i = prince[1] + 1; i < card.size(); ++i) {
			if (0 == card[i]) {
				return i;
			}
		}
	}
	return -1;
}