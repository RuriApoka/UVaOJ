#define LOCAL

#include <iostream>
#include <array>
using namespace std;

typedef array<char, 100> Line;
typedef array<Line, 100> Board;

bool readInfoSuccess(Board& board, int& n, int& m);
void computeAns(Board& board, int n, int m);
void printAns(const Board& board, int n, int m, int kase);
inline bool isMine(const Board& board, int n, int m, int r, int c) { return (-1 < r) && (r < n) && (-1 < c) && (c < m) && ('*' == board[r][c]); }

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int kase = 1, n, m;
	Board board;
	while (readInfoSuccess(board, n, m)) {
		computeAns(board, n, m);
		printAns(board, n, m, kase++);
	}
	return 0;
}

bool readInfoSuccess(Board& board, int& n, int& m) {
	cin >> n >> m;
	if (n | m) {
		cin.get();
		char ch;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				ch = cin.get();
				board[i][j] = ('*' == ch) ? '*' : '0';
			}
			cin.get();
		}
		return true;
	}
	else {
		return false;
	}
}

void computeAns(Board& board, int n, int m) {
	int r[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	int c[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if ('*' != board[i][j]) {
				for (int k = 0; k < 8; ++k) {
					if (isMine(board, n, m, i + r[k], j + c[k])) {
						board[i][j]++;
					}
				}
			}
		}
	}
}

void printAns(const Board& board, int n, int m, int kase) {
	if (kase > 1) {
		cout << endl;
	}
	cout << "Field #" << kase << ':' << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout.put(board[i][j]);
		}
		cout << endl;
	}
}