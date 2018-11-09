#define LOCAL

#include <cstdio>
#include <array>
using namespace std;

struct Soilder {
	int left;
	int right;
};

array<Soilder, 100001> attack_line;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	int s, b, l, r;
	while ((2 == scanf("%d%d", &s, &b)) && (s || b)) {
		for (int i = 1; i < s; ++i) {
			attack_line[i].left = i - 1;
			attack_line[i].right = i + 1;
		}
		attack_line[s].left = s - 1;
		attack_line[s].right = 0;
		while (b--) {
			scanf("%d%d", &l, &r);
			if (0 == attack_line[l].left) {
				printf("* ");
			}
			else {
				printf("%d ", attack_line[l].left);
				attack_line[attack_line[l].left].right = attack_line[r].right;
			}
			if (0 == attack_line[r].right) {
				printf("*\n");
			}
			else {
				printf("%d\n", attack_line[r].right);
				attack_line[attack_line[r].right].left = attack_line[l].left;
			}
		}
		puts("-");
	}
	return 0;
}