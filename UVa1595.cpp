#define LOCAL

#include <iostream>
#include <utility>
#include <set>
using namespace std;

typedef pair<int, int> Dot;
typedef set<Dot> Figure;
typedef Figure::iterator It;

void initFigure(Figure& figure);
bool isLeftRightSymmetric(Figure& figure);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n--) {
		Figure figure;
		initFigure(figure);
		cout << (isLeftRightSymmetric(figure) ? "YES" : "NO") << endl;
	}
	return 0;
}

void initFigure(Figure& figure) {
	int n;
	cin >> n;
	Dot dot;
	for (int i = 0; i < n; ++i) {
		cin >> dot.first >> dot.second;
		figure.insert(dot);
	}
}

bool isLeftRightSymmetric(Figure& figure) {
	if (1 == figure.size()) {
		return true;
	}
	else {
		It it = figure.begin(), end = figure.end(), t = figure.end();
		int target_x = it->first + (--t)->first;
		while (it != end) {
			if (2 * it->first != target_x) {
				if ((t = figure.find({ target_x - it->first, it->second })) != end) {
					figure.erase(t);
					t = it++;
					figure.erase(t);
				}
				else {
					break;
				}
			}
			else {
				++it;
			}
		}
		return (it == end);
	}
}