#define LOCAL

#include <iostream>
#include <algorithm>
using namespace std;

inline void myClear() { while ('\n' != cin.get()); }
inline int computeAns(char ch, int row, int col);
inline int numsOfRock(int row, int col) { return min(row, col); }
inline int numsOfKnight(int row, int col) { return (row * col + 1) / 2; }
inline int numsOfQueen(int row, int col) { return min(row, col); }
inline int numsOfKing(int row, int col) { return ((row + 1) / 2) * ((col + 1) / 2); }

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	char piece;
	int row, col, t;
	cin >> t;
	myClear();
	while (t--) {
		cin.get(piece);
		cin >> row >> col;
		myClear();
		cout << computeAns(piece, row, col) << endl;
	}
	return 0;
}

int computeAns(char ch, int row, int col) {
	switch (ch) {
	case 'r':
		return numsOfRock(row, col);
	case 'k':
		return numsOfKnight(row, col);
	case 'Q':
		return numsOfQueen(row, col);
	default:
		return numsOfKing(row, col);
	}
}