#define LOCAL

#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> Line;
typedef vector<Line> Board;

bool readBoardSuccess(Board& board);
int numsOfPockets(Board& board);
void mergePocket(Board& board, int row, int col);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	Board board;
	while (readBoardSuccess(board)) {
		cout << numsOfPockets(board) << endl;
	}
	return 0;
}

bool readBoardSuccess(Board& board) {
	int m, n;
	cin >> m >> n;
	if (0 == m) {
		return false;
	}
	else {
		board.resize(m);
		for (int i = 0; i < m; ++i) {
			cin.get();
			board[i].resize(n);
			for (int j = 0; j < n; ++j) {
				cin.get(board[i][j]);
			}
		}
		return true;
	}
}

int numsOfPockets(Board& board) {
	int ans = 0;
	int m = board.size(), n = board[0].size();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if ('@' == board[i][j]) {
				mergePocket(board, i, j);
				ans++;
			}
		}
	}
	return ans;
}

void mergePocket(Board& board, int row, int col) {
	board[row][col] = '*';
	int r[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
	int c[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int a, b;
	for (int i = 0; i < 8; ++i) {
		a = row + r[i];
		b = col + c[i];
		if ((-1 < a) && (a < board.size())
			&& (-1 < b) && (b < board[0].size())
			&& ('@' == board[a][b])) {
			mergePocket(board, a, b);
		}
	}
}