#define LOCAL

#include <cstdio>
#include <array>
#include <set>
using namespace std;

const int Size = 3;

typedef array<array<char, Size>, Size> Grid;
typedef set<int> HashValue;

void readGrid(Grid& grid);
void transformGrid(Grid& grid, Grid& temp);
int getHashValue(const Grid& grid);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int n;
	scanf("%d%*c", &n);
	int value;
	Grid grid, temp;
	HashValue hash_value;
	while (n--) {
		hash_value.clear();
		readGrid(grid);
		int i = 0;
		for (; 0 != (value = getHashValue(grid)); ++i) {
			if (hash_value.end() == hash_value.find(value)) {
				hash_value.insert(value);
			}
			else {
				break;
			}
			transformGrid(grid, temp);
		}
		printf("%d\n", i - 1);
	}
	return 0;
}

void readGrid(Grid& grid) {
	for (int i = 0; i < Size; ++i) {
		getchar();
		for (int j = 0; j < Size; ++j) {
			scanf("%c", &grid[i][j]);
			grid[i][j] -= '0';
		}
	}
	getchar();
}

void transformGrid(Grid& grid, Grid& temp) {
	temp = grid;
	grid[0][0] = (temp[0][1] + temp[1][0]) % 2;
	grid[0][1] = (temp[0][0] + temp[0][2] + temp[1][1]) % 2;
	grid[0][2] = (temp[0][1] + temp[1][2]) % 2;
	grid[1][0] = (temp[0][0] + temp[1][1] + temp[2][0]) % 2;
	grid[1][1] = (temp[0][1] + temp[1][0] + temp[1][2] + temp[2][1]) % 2;
	grid[1][2] = (temp[0][2] + temp[1][1] + temp[2][2]) % 2;
	grid[2][0] = (temp[1][0] + temp[2][1]) % 2;
	grid[2][1] = (temp[1][1] + temp[2][0] + temp[2][2]) % 2;
	grid[2][2] = (temp[1][2] + temp[2][1]) % 2;
}

int getHashValue(const Grid& grid) {
	int value = 0;
	for (int i = Size - 1; i > -1; --i) {
		for (int j = Size - 1; j > -1; --j) {
			value *= 10;
			value += grid[i][j];
		}
	}
	return value;
}