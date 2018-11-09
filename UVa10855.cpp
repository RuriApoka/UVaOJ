#define LOCAL

#include <cstdio>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<char> Line;
typedef vector<Line> Matrix;
typedef array<int, 4> Ans;
typedef vector<unsigned int> HashValue;

bool readNewCase(Matrix& a, Matrix& b);
void computeAns(const Matrix& a, Matrix& b, Ans& ans);
inline void printAns(const Ans& ans) { printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]); }
void rotateMatrix(Matrix& a);
void BKDHash(const Matrix& a, int len, HashValue& value);
unsigned int myBKDHash(const Matrix& a, const int row, const int col, const int len);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	Matrix a, b;
	a.reserve(1000);
	b.reserve(1000);
	Ans ans;
	while (readNewCase(a, b)) {
		ans.fill(0);
		computeAns(a, b, ans);
		printAns(ans);
	}
	return 0;
}

bool readNewCase(Matrix& a, Matrix& b) {
	int m, n;
	scanf("%d%d", &m, &n);
	if ((0 != m) || (0 != n)) {
		a.resize(m);
		for (int i = 0; i < m; ++i) {
			a[i].reserve(1000);
			a[i].resize(m);
			getchar();
			for (int j = 0; j < m; ++j) {
				a[i][j] = getchar();
			}
		}
		b.resize(n);
		for (int i = 0; i < n; ++i) {
			b[i].reserve(1000);
			b[i].resize(n);
			getchar();
			for (int j = 0; j < n; ++j) {
				b[i][j] = getchar();
			}
		}
		return true;
	}
	else {
		return false;
	}
}

void computeAns(const Matrix& a, Matrix& b, Ans& ans) {
	HashValue value;
	HashValue::iterator it;
	BKDHash(a, b.size(), value);
	unsigned int b_value;
	b_value = myBKDHash(b, 0, 0, b.size());
	if (((it = lower_bound(value.begin(), value.end(), b_value)) != value.end()) &&
		(*it == b_value)) {
		ans[0] = upper_bound(value.begin(), value.end(), b_value) - it;
	}
	for (int i = 1; i < 4; ++i) {
		rotateMatrix(b);
		b_value = myBKDHash(b, 0, 0, b.size());
		if (((it = lower_bound(value.begin(), value.end(), b_value)) != value.end()) &&
			(*it == b_value)) {
			ans[i] = upper_bound(value.begin(), value.end(), b_value) - it;
		}
	}
}

void rotateMatrix(Matrix& a) {
	int size = a.size();
	Matrix t = a;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			a[i][j] = t[size - 1 - j][i];
		}
	}
}

void BKDHash(const Matrix& a, int len, HashValue& value) {
	int max = a.size() - len + 1;
	value.reserve(max * max);
	for (int i = 0; i < max; ++i) {
		for (int j = 0; j < max; ++j) {
			value.push_back(myBKDHash(a, i, j, len));
		}
	}
	sort(value.begin(), value.end());
}

unsigned int myBKDHash(const Matrix& a, const int row, const int col, const int len) {
	unsigned int seed = 13131;
	unsigned int hash = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			hash = hash * seed + a[row + i][col + j];
		}
	}
	return (hash & 0x7FFFFFFF);
}