#define LOCAL

#include <cstdio>
#include <array>
using namespace std;

typedef array<int, 5> Line;
typedef array<Line, 5> Card;
typedef array<int, 12> Bingo;

void readInfo(Card& card);
int simulate(const Card& card);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	Card card;
	card[2][2] = 0;
	int t;
	scanf("%d", &t);
	while (t--) {
		readInfo(card);
		printf("BINGO after %d numbers announced\n", simulate(card));
	}
	return 0;
}

void readInfo(Card& card) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 5; ++j) {
			scanf("%d", &card[j][i]);
		}
	}
	scanf("%d%d%d%d", &card[0][2], &card[1][2], &card[3][2], &card[4][2]);
	for (int i = 3; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			scanf("%d", &card[j][i]);
		}
	}
}

int simulate(const Card& card) {
	Bingo bingo;
	bingo.fill(0);
	bool free_space_filled = false;
	bool not_bingo = true;
	int num, row, ans;
	int i, j;
	for (i = 0; not_bingo && (i < 75); ++i) {
		scanf("%d", &num);
		row = (num - 1) / 15;
		for (j = 0; j < 5; ++j) {
			if (num == card[row][j]) {
				if ((5 == ++bingo[row]) || (5 == ++bingo[5 + j])) {
					ans = i + 1;
					not_bingo = false;
					break;
				}
				if (row == j) {
					if (5 == ++bingo[10]) {
						ans = i + 1;
						not_bingo = false;
						break;
					}
				}
				if (4 == (row + j)) {
					if (5 == ++bingo[11]) {
						ans = i + 1;
						not_bingo = false;
						break;
					}
				}
			}
		}
		if ((2 == row) && (5 == j) && !free_space_filled) {
			free_space_filled = true;
			if ((5 == ++bingo[2]) || (5 == ++bingo[7]) ||
				(5 == ++bingo[10]) || (5 == ++bingo[11])) {
				ans = i + 1;
				not_bingo = false;
			}
		}
	}
	for (; i < 75; ++i) {
		scanf("%*d");
	}
	return ans;
}