#define LOCAL

#include <cstdio>
#include <array>
#include <string>
#include <utility>
#include <cstdlib>
using namespace std;

typedef array<int, 3> Bin;
typedef array<Bin, 3> Bins;
typedef pair<string, int> Answer;

bool has_new_case(Bins& bins) {
	for (size_t i = 0; i < bins.size(); ++i)
		for (size_t j = 0; j < bins[i].size(); ++j)
			if (EOF == scanf("%d", &bins[i][j]))
				return false;
	return true;
}

Answer get_answer(const Bins& bins) {
	Answer answer = { "BGC", 0x7fffffff };
	string color = "BGC";

	Answer temp = { "XXX", 0 };
	for (size_t i = 0; i < color.size(); ++i) {
		temp.first[0] = color[i];
		temp.second = bins[1][i] + bins[2][i];

		for (size_t j = 0; j < color.size(); ++j) {
			if (i != j) {
				temp.first[1] = color[j];
				temp.second += bins[0][j] + bins[2][j];

				for (size_t k = 0; k < color.size(); ++k) {
					if ((i != k) && (j != k)) {
						temp.first[2] = color[k];
						temp.second += bins[0][k] + bins[1][k];

						if (temp.second < answer.second)
							answer = temp;
						else if (temp.second == answer.second)
							if (temp.first < answer.first)
								answer.first = temp.first;

						temp.second -= bins[0][k] + bins[1][k];
					}
				}

				temp.second -= bins[0][j] + bins[2][j];
			}
		}
	}

	return answer;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif // LOCAL

	Bins bins;
	Answer answer;

	while (has_new_case(bins)) {
		answer = get_answer(bins);
		printf("%s %d\n", answer.first.c_str(), answer.second);
	}

	return 0;
}