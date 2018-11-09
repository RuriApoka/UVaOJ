#include <cstdio>
using namespace std;

int main() {
	int n, sum, difference;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &sum, &difference);
		if ((sum < difference) ||
			(1 == ((sum - difference) % 2))) {
			puts("impossible");
		}
		else {
			printf("%d %d\n", ((sum - difference) >> 1) + difference, ((sum - difference) >> 1));
		}
	}
	return 0;
}