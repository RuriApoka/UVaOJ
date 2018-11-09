#define LOCAL

#include <cstdio>
#include <array>
#include <utility>
using namespace std;

typedef array<char, 21> Scores;
typedef array<int, 10> Index;
typedef pair<char, char> Frame;

bool readInfoSuccess(Scores& scores, Index& index, int& sum, int& total_bonus);
int bonusScores(const Scores& scores, Index& index, int total_rolls);
void readExtraRolls(Scores& scores, int i, char& ch, int rolls);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int sum, total_bonus;
	Index index;
	Scores scores;
	while (readInfoSuccess(scores, index, sum, total_bonus)) {
		sum += bonusScores(scores, index, total_bonus);
		printf("%d\n", sum);
	}
	return 0;
}

bool readInfoSuccess(Scores& scores, Index& index, int& sum, int& total_bonus) {
	sum = 0;
	total_bonus = 0;
	char ch;
	ch = getchar();
	if ('G' != ch) {
		ungetc(ch, stdin);
		Frame frame;
		int frames = 1;
		int total_rolls = 0;
		while ('\n' != ch) {
			frame.first = getchar();
			ch = getchar();
			if ('X' == frame.first) {
				sum += 10;
				index[total_bonus++] = total_rolls;
				scores[total_rolls++] = frame.first;
				if (10 == frames) {
					readExtraRolls(scores, total_rolls, ch, 2);
				}
			}
			else {
				frame.second = getchar();
				ch = getchar();
				scores[total_rolls++] = frame.first;
				scores[total_rolls++] = frame.second;
				if ('/' == frame.second) {
					sum += 10;
					index[total_bonus++] = total_rolls - 1;
					if (10 == frames) {
						readExtraRolls(scores, total_rolls, ch, 1);
					}
				}
				else {
					sum += (frame.first - '0') + (frame.second - '0');
				}
			}
			frames++;
		}
		return true;
	}
	else {
		return false;
	}
}

int bonusScores(const Scores& scores, Index& index, int total_bonus) {
	int bonus = 0;
	for (size_t i = 0; i < total_bonus; ++i) {
		if ('X' == scores[index[i]]) {
			switch (scores[index[i] + 2]) {
			case 'X':
				bonus += 20;
				break;
			case '/':
				bonus += 10;
				break;
			default:
				bonus += (('X' == scores[index[i] + 1]) ? 10 : (scores[index[i] + 1] - '0')) + (scores[index[i] + 2] - '0');
				break;
			}
		}
		else {
			bonus += ('X' == scores[index[i] + 1]) ? 10 : (scores[index[i] + 1] - '0');
		}
	}
	return bonus;
}

void readExtraRolls(Scores& scores, int i, char& ch, int rolls) {
	for (int j = 0; j < rolls; ++j) {
		ch = getchar();
		scores[i++] = ch;
		ch = getchar();
	}
}