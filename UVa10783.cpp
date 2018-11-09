#define LOCAL

#include <cstdio>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int cases;
	scanf("%d", &cases);

	int start, end;
	for (int i = 1; i <= cases; ++i) {
		scanf("%d%d", &start, &end);
		
		if (0== (start % 2))
			start++;
		if (0 == (end % 2))
			end--;
		printf("Case %d: %d\n", i, (start + end) / 2 * ((end - start) / 2 + 1));
	}

	return 0;
}