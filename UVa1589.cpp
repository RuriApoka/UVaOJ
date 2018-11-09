#define LOCAL

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef vector<int> Line;
typedef vector<Line> Board;
typedef pair<int, int> Position;
typedef pair<char, Position> Piece;
typedef vector<Piece> Pieces;

const int ROW = 10;
const int COL = 9;
enum Situation { empty, red, attacked, occupied, black };		//盘面的情况

bool readNewTest(Board& board, Pieces& red, Piece& black);
bool checkMate(Board& board, const Pieces& red, const Piece& black);
void generalAttack(Board& board, const Position& position);
void chariotAttack(Board& board, const Position& position);
void cannonAttack(Board& board, const Position& position);		//注意，炮不能把将作为炮台，因为下一步将就移动了
void horseAttack(Board& board, const Position& position);
bool isCheckMate(const Board& board, const Position& position);
inline bool inTheBoard(int r, int c) { return ((-1 < r) && (r < ROW) && (-1 < c) && (c < COL)); }
inline bool inThePalace(int r, int c) { return ((-1 < r) && (r < 3) && (2 < c) && (c < 6)); }

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	Board board;
	Pieces red;
	red.reserve(7);
	Piece black;
	while (readNewTest(board, red, black)) {
		cout << (checkMate(board, red, black) ? "YES" : "NO") << endl;
	}
	return 0;
}

bool readNewTest(Board& board, Pieces& red, Piece& black) {
	int n;
	cin >> n;
	if (0 == n) {
		return false;
	}
	else {
		board.clear();
		board.resize(ROW);
		for (int i = 0; i < ROW; ++i) {
			board[i].resize(COL, Situation::empty);
		}
		char ch;
		int x, y;
		cin >> x >> y;
		black.second.first = --x;
		black.second.second = --y;
		board[x][y] = Situation::black;
		red.clear();
		for (int i = 0; i < n; ++i) {
			cin.get();
			cin >> ch >> x >> y;
			red.push_back({ ch, { --x, --y } });
			board[x][y] = Situation::red;
		}
		return true;
	}
}

bool checkMate(Board& board, const Pieces& red, const Piece& black) {
	for (size_t i = 0; i < red.size(); ++i) {
		switch (red[i].first) {
		case 'G' :
			generalAttack(board, red[i].second);
			break;
		case 'R':
			chariotAttack(board, red[i].second);
			break;
		case 'C':
			cannonAttack(board, red[i].second);
			break;
		default:
			horseAttack(board, red[i].second);
			break;
		}
	}
	return isCheckMate(board, black.second);
}

void generalAttack(Board& board, const Position& position) {
	int i;
	for (i = position.first - 1; i > 2; --i) {
		if ((Situation::red == board[i][position.second])
			|| (Situation::occupied == board[i][position.second])) {	//有己方棋子挡着，无法飞将
			return;
		}
	}
	for (; i > -1; --i) {
		if ((Situation::red == board[i][position.second])				//九宫内如果遇到己方棋子，则飞将范围结束
			|| (Situation::occupied == board[i][position.second])) {
			board[i][position.second] = Situation::occupied;
			return;
		}
		else if (Situation::black != board[i][position.second]) {
			board[i][position.second] = Situation::attacked;
		}
	}
}

void chariotAttack(Board& board, const Position& position) {
	int r[4] = { 0,-1, 0, 1 };
	int c[4] = { -1, 0, 1, 0 };
	for (int i = 0; i < 4; ++i) {
		int x, y;
		for (x = position.first + r[i], y = position.second + c[i];
			inTheBoard(x, y) && (Situation::red != board[x][y]) && (Situation::occupied != board[x][y]);
			x += r[i], y += c[i]) {
			if (Situation::black != board[x][y]) {
				board[x][y] = Situation::attacked;
			}
		}
		if (inTheBoard(x, y) && (Situation::red == board[x][y])) {
			board[x][y] = Situation::occupied;
		}
	}
}

void cannonAttack(Board& board, const Position& position) {
	int r[4] = { 0,-1, 0, 1 };
	int c[4] = { -1, 0, 1, 0 };
	for (int i = 0; i < 4; ++i) {
		int x, y;
		for (x = position.first + r[i], y = position.second + c[i];
			inTheBoard(x, y) && ((Situation::empty == board[x][y]) || (Situation::attacked == board[x][y]) || (Situation::black == board[x][y]));
			x += r[i], y += c[i]) {
			;
		}
		for (x += r[i], y += c[i];
			inTheBoard(x, y) && (Situation::red != board[x][y]) && (Situation::occupied != board[x][y]);
			x += r[i], y += c[i]) {
			if (Situation::black != board[x][y]) {
				board[x][y] = Situation::attacked;
			}
		}
		if (inTheBoard(x, y) && (Situation::red == board[x][y])) {
			board[x][y] = Situation::occupied;
		}
	}
}

void horseAttack(Board& board, const Position& position) {
	int r[4] = { 0,-1, 0, 1 };
	int c[4] = { -1, 0, 1, 0 };
	Position jmp[8] = { {1, -1}, {-1, -1}, {-1, -1}, {-1, 1}, {-1, 1}, {1, 1}, {1, 1}, {1, -1} };
	for (int i = 0; i < 4; ++i) {
		int x = position.first + r[i];
		int y = position.second + c[i];
		if (inTheBoard(x, y) && ((Situation::empty == board[x][y]) || (Situation::attacked == board[x][y]))) {
			int j = i * 2;
			for (int k = 0; k < 2; ++j, ++k) {
				if (inTheBoard(x + jmp[j].first, y + jmp[j].second)) {
					if (Situation::empty == board[x + jmp[j].first][y + jmp[j].second]) {
						board[x + jmp[j].first][y + jmp[j].second] = Situation::attacked;
					}
					else if (Situation::red == (board[x + jmp[j].first][y + jmp[j].second])) {
						board[x + jmp[j].first][y + jmp[j].second] = Situation::occupied;
					}
				}
			}
		}
	}
}

bool isCheckMate(const Board& board, const Position& position) {
	int r[4] = { 0,-1, 0, 1 };
	int c[4] = { -1, 0, 1, 0 };
	for (int i = 0; i < 4; ++i) {
		int x = position.first + r[i];
		int y = position.second + c[i];
		if (inThePalace(x, y) && (Situation::attacked != board[x][y]) && (Situation::occupied != board[x][y])) {
			return false;
		}
	}
	return true;
}