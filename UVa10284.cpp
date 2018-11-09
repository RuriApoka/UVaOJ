#define LOCAL

#include <iostream>
#include <array>
#include <cctype>
using namespace std;

const int SIZE = 8;
enum State { EMPTY, ATTACKED };

typedef array<int, SIZE> Row;
typedef array<Row, SIZE> Board;

bool readInfoSuccess(Board& board);
void simulate(Board& board);
int computeAns(const Board& board);
inline void initBoard(Board& board);
inline void pawnAttack(Board& board, int r, int c, int toward);
void knightAttack(Board& board, int r, int c);
void bishopAttack(Board& board, int r, int c);
void rockAttack(Board& board, int r, int c);
inline void queueAttack(Board& board, int r, int c) { bishopAttack(board, r, c); rockAttack(board, r, c); }
void kingAttack(Board& board, int r, int c);
inline bool canMove(Board& board, int r, int c) { return (-1 < r) && (r < SIZE) && (-1 < c) && (c < SIZE) && 
														((State::ATTACKED == board[r][c]) || (State::EMPTY == board[r][c])); }

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	Board board;
	while (readInfoSuccess(board)) {
		simulate(board);
		cout << computeAns(board) << endl;
	}
	return 0;
}

bool readInfoSuccess(Board& board) {
	initBoard(board);
	char ch = cin.get();
	if (!cin.eof()) {
		cin.unget();
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				ch = cin.get();
				if (isalpha(ch)) {
					board[i][j] = ch;
				}
				else {
					j += ch - '0' - 1;
				}
			}
			cin.get();
		}
		return true;
	}
	else {
		return false;
	}
}

void simulate(Board& board) {
	for (size_t i = 0; i < board.size(); ++i) {
		for (size_t j = 0; j < board[i].size(); ++j) {
			switch (board[i][j]) {
			case 'P':
				pawnAttack(board, i, j, -1);
				break;
			case 'p':
				pawnAttack(board, i, j, 1);
				break;
			case 'N':
			case 'n':
				knightAttack(board, i, j);
				break;
			case 'B':
			case 'b':
				bishopAttack(board, i, j);
				break;
			case 'R':
			case 'r':
				rockAttack(board, i, j);
				break;
			case 'Q':
			case 'q':
				queueAttack(board, i, j);
				break;
			case 'K':
			case 'k':
				kingAttack(board, i, j);
				break;
			default:
				break;
			}
		}
	}
}

int computeAns(const Board& board) {
	int ans = 0;
	for (size_t i = 0; i < board.size(); ++i) {
		for (size_t j = 0; j < board[i].size(); ++j) {
			if (State::EMPTY == board[i][j]) {
				ans++;
			}
		}
	}
	return ans;
}

void initBoard(Board& board) {
	for (size_t i = 0; i < board.size(); ++i) {
		board[i].fill(State::EMPTY);
	}
}

void pawnAttack(Board& board, int r, int c, int toward) {
	int col[] = { -1, 1 };
	for (int i = 0; i < 2; ++i) {
		if (canMove(board, r + toward, c + col[i])) {
			board[r + toward][c + col[i]] = State::ATTACKED;
		}
	}
}

void knightAttack(Board& board, int r, int c) {
	int row[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
	int col[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
	for (int i = 0; i < 8; ++i) {
		if (canMove(board, r + row[i], c + col[i])) {
			board[r + row[i]][c + col[i]] = State::ATTACKED;
		}
	}
}

void bishopAttack(Board& board, int r, int c) {
	int row[] = { -1, -1, 1, 1 };
	int col[] = { -1, 1, 1, -1 };
	for (int i = 0; i < 4; ++i) {
		int x = r + row[i];
		int y = c + col[i];
		while (canMove(board, x, y)) {
			board[x][y] = State::ATTACKED;
			x += row[i];
			y += col[i];
		}
	}
}

void rockAttack(Board& board, int r, int c) {
	int row[] = { 0, -1, 0, 1 };
	int col[] = { -1, 0, 1, 0 };
	for (int i = 0; i < 4; ++i) {
		int x = r + row[i];
		int y = c + col[i];
		while (canMove(board, x, y)) {
			board[x][y] = State::ATTACKED;
			x += row[i];
			y += col[i];
		}
	}
}

void kingAttack(Board& board, int r, int c) {
	int row[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	int col[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
	for (int i = 0; i < 8; ++i) {
		if (canMove(board, r + row[i], c + col[i])) {
			board[r + row[i]][c + col[i]] = State::ATTACKED;
		}
	}
}