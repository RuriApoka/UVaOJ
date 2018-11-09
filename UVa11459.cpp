#define LOCAL

#include <iostream>
#include <vector>
#include <array>
using namespace std;

typedef vector<int> Players;
typedef array<int, 101> Board;

const int EMPTY = 0;
const int MAX = 100001;
const int END = 100;

int readInfo(Players& players, Board& board);
void simulate(Players& players, const Board& board, int dies);
void printAns(const Players& players);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	Players players;
	players.reserve(MAX);
	Board board;
	int n, dies;
	cin >> n;
	while (n--) {
		dies = readInfo(players, board);
		simulate(players, board, dies);
		printAns(players);
	}
	return 0;
}

int readInfo(Players& players, Board& board) {
	int a, b, c;
	cin >> a >> b >> c;
	players.clear();
	players.resize(a + 1, 1);
	board.fill(EMPTY);
	int mouth, tail;
	for (int i = 0; i < b; ++i) {
		cin >> mouth >> tail;
		board[mouth] = tail;
	}
	return c;
}

void simulate(Players& players, const Board& board, int dies) {
	int number;
	int i = 1;
	int size = players.size();
	while (dies--) {
		cin >> number;
		players[i] += number;
		if (players[i] >= END) {
			players[i] = END;
			while (dies--) {
				cin >> number;
			}
			break;
		}
		else if (EMPTY != board[players[i]]) {
			players[i] = board[players[i]];
			if (END == players[i]) {
				while (dies--) {
					cin >> number;
				}
				break;
			}
		}
		if (++i == size) {
			i = 1;
		}
	}
}

void printAns(const Players& players) {
	int size = players.size();
	for (int i = 1; i < size; ++i) {
		cout << "Position of player " << i
			<< " is " << players[i] << '.' << endl;
	}
}