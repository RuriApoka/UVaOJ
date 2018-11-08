#define LOCAL

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> MyType;

bool readTestSuccessful(MyType& h, MyType& v);
void computeAns(const MyType& h, const MyType& v, Vector& ans);
void printAns(int& kases, const Vector& ans);
bool haveSqual(int row, int col, const MyType& h, const MyType& v, int size);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int kases = 0;
	MyType h, v;
	Vector ans;
	while (readTestSuccessful(h, v)) {
		computeAns(h, v, ans);
		printAns(kases, ans);
	}
	return 0;
}

bool readTestSuccessful(MyType& h, MyType& v) {
	h.clear();
	v.clear();
	int m, n;
	if (cin >> n >> m) {
		h.resize(n);
		for (int i = 0; i < n; ++i) {
			h[i].resize(n - 1, 0);
		}
		v.resize(n - 1);
		for (int i = 0; i < n - 1; ++i) {
			v[i].resize(n, 0);
		}
		char ch;
		int row, col;
		for (int i = 0; i < m; ++i) {
			cin.get();
			cin.get(ch);
			cin >> row >> col;
			if ('H' == ch) {
				h[row - 1][col - 1] = 1;
			}
			else {
				v[col - 1][row - 1] = 1;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

void computeAns(const MyType& h, const MyType& v, Vector& ans) {
	ans.clear();
	ans.resize(v.size(), 0);
	int upper = v.size();
	for (int i = 0; i < upper; ++i) {
		for (int j = 0; j < upper; ++j) {
			for (int size = 0; size < upper - max(i, j); ++size) {
				if (haveSqual(i, j, h, v, size + 1)) {
					ans[size]++;
				}
			}
		}
	}
}

void printAns(int& kases, const Vector& ans) {
	size_t i;
	for (i = 0; i < ans.size(); ++i) {
		if (0 != ans[i]) {
			break;
		}
	}
	if (0 != kases++) {
		cout << endl << "**********************************" << endl << endl;
	}
	cout << "Problem #" << kases << endl << endl;
	if (ans.size() == i) {
		cout << "No completed squares can be found." << endl;
	}
	else {
		for (i = 0; i < ans.size(); ++i) {
			if (0 != ans[i]) {
				cout << ans[i] << " square (s) of size " << i + 1 << endl;
			}
		}
	}
}

bool haveSqual(int row, int col, const MyType& h, const MyType& v, int size) {
	for (int i = 0; i < size; ++i) {
		if ((1 != v[row + i][col]) || (1 != v[row + i][col + size])) {
			return false;
		}
	}
	for (int j = 0; j < size; ++j) {
		if ((1 != h[row][col + j]) || (1 != h[row + size][col + j])) {
			return false;
		}
	}
	return true;
}