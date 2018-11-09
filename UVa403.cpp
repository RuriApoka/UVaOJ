#define LOCAL

#include <cstdio>
#include <vector>
#include <array>
#include <utility>
#include <cctype>
using namespace std;

struct Command {
	char cmd[5];
	char font[3];
	int row;
	int col;
	char str[63];
};

typedef array<char, 28> C1;
typedef pair<int, int> Cell;
typedef array<vector<Cell>, 5> C5_Alpha;
typedef array<C5_Alpha, 26> C5;
typedef array<array<char, 60>, 60> Paper;

void initFont(C1& c1, C5& c5);
bool readInfoSuccessf(Paper& paper);
void drawPaper(Paper& paper);
void printPaper(const Paper& paper);
bool readCommandLine(Command& command);
void drawPaperWithC1(Paper& paper, int row, int col, char *str, bool left_to_right);
void drawPaperWithC5(Paper& paper, int row, int col, char *str, bool left_to_right, bool from_center);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	C1 c1;
	C5 c5;
	initFont(c1, c5);
	Paper paper;
	while (readInfoSuccessf(paper)) {
		drawPaper(paper);
		printPaper(paper);
	}
	return 0;
}

void initFont(C1& c1, C5& c5) {
	char t[29] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.*";
	for (size_t i = 0; i < c1.size(); ++i) {
		c1[i] = t[i];
	}
	/*Alpha A*/
	c5[0][0].assign({ { 0, 1 }, { 0, 2 }, { 0, 3 } });
	c5[0][1].assign({ { 1, 0 }, { 1, 4 } });
	c5[0][2].assign({ { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 2, 4 } });
	c5[0][3].assign({ { 3, 0 }, { 3, 4 } });
	c5[0][4].assign({ { 4, 0 }, { 4, 4 } });
	/*Alpha B*/
	c5[1][0].assign({ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } });
	c5[1][1].assign({ { 1, 0 }, { 1, 4 } });
	c5[1][2].assign({ { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 } });
	c5[1][3].assign({ { 3, 0 }, { 3, 4 } });
	c5[1][4].assign({ { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 } });
	/*Alpha C*/
	c5[2][0].assign({ { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 } });
	c5[2][1].assign({ { 1, 0 }, { 1, 4 } });
	c5[2][2].assign({ { 2, 0 } });
	c5[2][3].assign({ { 3, 0 } });
	c5[2][4].assign({ { 4, 1 }, { 4, 2 }, { 4, 3 }, { 4, 4 } });
	/*Alpha D*/
	c5[3][0].assign({ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } });
	c5[3][1].assign({ { 1, 0 }, { 1, 4 } });
	c5[3][2].assign({ { 2, 0 }, { 2, 4 } });
	c5[3][3].assign({ { 3, 0 }, { 3, 4 } });
	c5[3][4].assign({ { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 } });
	/*Alpha E*/
	c5[4][0].assign({ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, {0, 4} });
	c5[4][1].assign({ { 1, 0 } });
	c5[4][2].assign({ { 2, 0 }, { 2, 1 }, { 2, 2 } });
	c5[4][3].assign({ { 3, 0 } });
	c5[4][4].assign({ { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 }, {4, 4} });
	/*Alpha F*/
	c5[5][0].assign({ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, {0, 4} });
	c5[5][1].assign({ { 1, 0 } });
	c5[5][2].assign({ { 2, 0 }, { 2, 1 }, { 2, 2 } });
	c5[5][3].assign({ { 3, 0 } });
	c5[5][4].assign({ { 4, 0 } });
	/*Alpha G*/
	c5[6][0].assign({ { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 } });
	c5[6][1].assign({ { 1, 0 } });
	c5[6][2].assign({ { 2, 0 }, { 2, 3}, { 2, 4 } });
	c5[6][3].assign({ { 3, 0 }, { 3, 4 } });
	c5[6][4].assign({ { 4, 1 }, { 4, 2 }, { 4, 3 } });
	/*Alpha H*/
	c5[7][0].assign({ { 0, 0 }, { 0, 4 } });
	c5[7][1].assign({ { 1, 0 }, { 1, 4 } });
	c5[7][2].assign({ { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 2, 4 } });
	c5[7][3].assign({ { 3, 0 }, { 3, 4 } });
	c5[7][4].assign({ { 4, 0 }, { 4, 4 } });
	/*Alpha I*/
	c5[8][0].assign({ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, {0, 4} });
	c5[8][1].assign({ { 1, 2 } });
	c5[8][2].assign({ { 2, 2 } });
	c5[8][3].assign({ { 3, 2 } });
	c5[8][4].assign({ { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 }, {4, 4} });
	/*Alpha J*/
	c5[9][0].assign({ { 0, 2 }, { 0, 3 }, {0, 4} });
	c5[9][1].assign({ { 1, 3 } });
	c5[9][2].assign({ { 2, 3 } });
	c5[9][3].assign({ { 3, 0 }, { 3, 3 } });
	c5[9][4].assign({ { 4, 1 }, { 4, 2 } });
	/*Alpha K*/
	c5[10][0].assign({ { 0, 0 }, { 0, 4 } });
	c5[10][1].assign({ { 1, 0 }, { 1, 3 } });
	c5[10][2].assign({ { 2, 0 }, { 2, 1 }, { 2, 2 } });
	c5[10][3].assign({ { 3, 0 }, { 3, 3 } });
	c5[10][4].assign({ { 4, 0 }, { 4, 4 } });
	/*Alpha L*/
	c5[11][0].assign({ { 0, 0 } });
	c5[11][1].assign({ { 1, 0 } });
	c5[11][2].assign({ { 2, 0 } });
	c5[11][3].assign({ { 3, 0 } });
	c5[11][4].assign({ { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 }, {4, 4} });
	/*Alpha M*/
	c5[12][0].assign({ { 0, 0 }, { 0, 4 } });
	c5[12][1].assign({ { 1, 0 }, { 1, 1 }, { 1, 3 }, { 1, 4 } });
	c5[12][2].assign({ { 2, 0 }, { 2, 2 }, { 2, 4 } });
	c5[12][3].assign({ { 3, 0 }, { 3, 4 } });
	c5[12][4].assign({ { 4, 0 }, { 4, 4 } });
	/*Alpha N*/
	c5[13][0].assign({ { 0, 0 }, { 0, 4 } });
	c5[13][1].assign({ { 1, 0 }, { 1, 1 }, { 1, 4 } });
	c5[13][2].assign({ { 2, 0 }, { 2, 2 }, { 2, 4 } });
	c5[13][3].assign({ { 3, 0 }, { 3, 3 }, { 3, 4 } });
	c5[13][4].assign({ { 4, 0 }, { 4, 4 } });
	/*Alpha O*/
	c5[14][0].assign({ { 0, 1 }, { 0, 2 }, { 0, 3 } });
	c5[14][1].assign({ { 1, 0 }, { 1, 4 } });
	c5[14][2].assign({ { 2, 0 }, { 2, 4 } });
	c5[14][3].assign({ { 3, 0 }, { 3, 4 } });
	c5[14][4].assign({ { 4, 1 }, { 4, 2 }, { 4, 3 } });
	/*Alpha P*/
	c5[15][0].assign({ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } });
	c5[15][1].assign({ { 1, 0 }, { 1, 4 } });
	c5[15][2].assign({ { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 } });
	c5[15][3].assign({ { 3, 0 } });
	c5[15][4].assign({ { 4, 0 } });
	/*Alpha Q*/
	c5[16][0].assign({ { 0, 1 }, { 0, 2 }, { 0, 3 } });
	c5[16][1].assign({ { 1, 0 }, { 1, 4 } });
	c5[16][2].assign({ { 2, 0 }, { 2, 4 } });
	c5[16][3].assign({ { 3, 0 }, { 3, 3 }, { 3, 4 } });
	c5[16][4].assign({ { 4, 1 }, { 4, 2 }, { 4, 3 },{ 4, 4 } });
	/*Alpha R*/
	c5[17][0].assign({ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } });
	c5[17][1].assign({ { 1, 0 }, { 1, 4 } });
	c5[17][2].assign({ { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 } });
	c5[17][3].assign({ { 3, 0 }, { 3, 3 } });
	c5[17][4].assign({ { 4, 0 }, { 4, 4 } });
	/*Alpha S*/
	c5[18][0].assign({ { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 } });
	c5[18][1].assign({ { 1, 0 } });
	c5[18][2].assign({ { 2, 1 }, { 2, 2 }, { 2, 3 } });
	c5[18][3].assign({ { 3, 4 } });
	c5[18][4].assign({ { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 } });
	/*Alpha T*/
	c5[19][0].assign({ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, {0, 4} });
	c5[19][1].assign({ { 1, 0 }, { 1, 2 }, { 1, 4 } });
	c5[19][2].assign({ { 2, 2 } });
	c5[19][3].assign({ { 3, 2 } });
	c5[19][4].assign({ { 4, 1 }, { 4, 2 }, { 4, 3 } });
	/*Alpha U*/
	c5[20][0].assign({ { 0, 0 }, { 0, 4 } });
	c5[20][1].assign({ { 1, 0 }, { 1, 4 } });
	c5[20][2].assign({ { 2, 0 }, { 2, 4 } });
	c5[20][3].assign({ { 3, 0 }, { 3, 4 } });
	c5[20][4].assign({ { 4, 1 }, { 4, 2 }, { 4, 3 } });
	/*Alpha V*/
	c5[21][0].assign({ { 0, 0 }, { 0, 4 } });
	c5[21][1].assign({ { 1, 0 }, { 1, 4 } });
	c5[21][2].assign({ { 2, 1 }, { 2, 3 } });
	c5[21][3].assign({ { 3, 1 }, { 3, 3 } });
	c5[21][4].assign({ { 4, 2 } });
	/*Alpha W*/
	c5[22][0].assign({ { 0, 0 }, { 0, 4 } });
	c5[22][1].assign({ { 1, 0 }, { 1, 4 } });
	c5[22][2].assign({ { 2, 0 }, { 2, 2 }, { 2, 4 } });
	c5[22][3].assign({ { 3, 0 }, { 3, 1 }, { 3, 3 }, { 3, 4 } });
	c5[22][4].assign({ { 4, 0 }, { 4, 4 } });
	/*Alpha X*/
	c5[23][0].assign({ { 0, 0 }, { 0, 4 } });
	c5[23][1].assign({ { 1, 1 }, { 1, 3 } });
	c5[23][2].assign({ { 2, 2 } });
	c5[23][3].assign({ { 3, 1 }, { 3, 3 } });
	c5[23][4].assign({ { 4, 0 }, { 4, 4 } });
	/*Alpha Y*/
	c5[24][0].assign({ { 0, 0 }, { 0, 4 } });
	c5[24][1].assign({ { 1, 1 }, { 1, 3 } });
	c5[24][2].assign({ { 2, 2 } });
	c5[24][3].assign({ { 3, 2 } });
	c5[24][4].assign({ { 4, 2 } });
	/*Alpha Z*/
	c5[25][0].assign({ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, {0, 4} });
	c5[25][1].assign({ { 1, 3 } });
	c5[25][2].assign({ { 2, 2 } });
	c5[25][3].assign({ { 3, 1 } });
	c5[25][4].assign({ { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 }, {4, 4} });
}

bool readInfoSuccessf(Paper& paper) {
	char str[5];
	if (EOF != scanf("%s", str)) {
		for (size_t i = 0; i < paper.size(); ++i) {
			paper[i].fill('.');
		}
		int len = strlen(str);
		for (--len; len > -1; --len) {
			ungetc(str[len], stdin);
		}
		return true;
	}
	else {
		return false;
	}
}

void drawPaper(Paper& paper) {
	int row, col;
	char *str;
	bool left_to_right, from_center;
	Command command;
	while (readCommandLine(command)) {
		row = command.row - 1;
		str = command.str + 1;
		left_to_right = true;
		from_center = false;
		switch (command.cmd[1]) {
		case 'P':
			col = command.col - 1;
			break;
		case 'L':
			col = 0;
			break;
		case 'R':
			col = paper[0].size() - 1;
			left_to_right = false;
			break;
		default:
			int len = strlen(command.str) - 2;
			if ('1' == command.font[1]) {
				col = 30 - (len >> 1);
			}
			else if (10 < len) {
				col = 0;
				str += (len - 10) >> 1;
			}
			else {
				col = 30 - ((len * 6) >> 1);
			}
			from_center = true;
			break;
		}
		if ('1' == command.font[1]) {
			drawPaperWithC1(paper, row, col, str, left_to_right);
		}
		else {
			drawPaperWithC5(paper, row, col, str, left_to_right, from_center);
		}
	}
}