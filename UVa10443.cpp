#define LOCAL

#include <cstdio>
#include <array>
using namespace std;

typedef array<char, 102> Line;
typedef array<Line, 102> Board;
typedef array<Board, 2> Boards;

void initBoards(Boards& board);
void readInfo(Boards& board, int& r, int& c, int& n);
int simulate(Boards& board, int r, int c, int n);
void printAns(const Boards& board, int r, int c, int ans, int kase);
void simulateOneDay(Boards& board, int r, int c, int sour, int dest);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	Boards board;
	initBoards(board);
	int r, c, n;
	int t, ans, kase = 0;
	scanf("%d", &t);
	while (t--) {
		readInfo(board, r, c, n);
		ans = simulate(board, r, c, n);
		printAns(board, r, c, ans, kase++);
	}
	return 0;
}

void initBoards(Boards& board) {
	for (size_t i = 0; i < board.size(); ++i) {
		for (size_t j = 0; j < board[i].size(); ++j) {
			board[i][j].fill('0');
		}
	}
}

void readInfo(Boards& board, int& r, int& c, int& n) {
	scanf("%d%d%d%*c", &r, &c, &n);
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			board[0][i][j] = getchar();
		}
		getchar();
	}
}

int simulate(Boards& board, int r, int c, int n) {
	for (int i = 0; i < n; ++i) {
		simulateOneDay(board, r, c, i % 2, (i + 1) % 2);
	}
	return n % 2;
}

void printAns(const Boards& board, int r, int c, int ans, int kase) {
	if (kase > 0) {
		putchar('\n');
	}
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			putchar(board[ans][i][j]);
		}
		putchar('\n');
	}
}

void simulateOneDay(Boards& board, int r, int c, int sour, int dest) {
	int row[4] = { 0, -1, 0, 1 };
	int col[4] = { -1, 0, 1, 0 };
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			board[dest][i][j] = board[sour][i][j];
			switch (board[sour][i][j]) {
			case 'R':
				for (int k = 0; k < 4; ++k) {
					if ('P' == board[sour][i + row[k]][j + col[k]]) {
						board[dest][i][j] = 'P';
						break;
					}
				}
				break;
			case 'S':
				for (int k = 0; k < 4; ++k) {
					if ('R' == board[sour][i + row[k]][j + col[k]]) {
						board[dest][i][j] = 'R';
						break;
					}
				}
				break;
			case 'P':
				for (int k = 0; k < 4; ++k) {
					if ('S' == board[sour][i + row[k]][j + col[k]]) {
						board[dest][i][j] = 'S';
						break;
					}
				}
				break;
			default:
				break;
			}
		}
	}
}