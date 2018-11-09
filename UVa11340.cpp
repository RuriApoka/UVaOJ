#define LOCAL

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

const int Len = 10000;

typedef pair<char, unsigned long long> Character;
typedef vector<Character> Characters;

void initCharacterTable(Characters& characters);
unsigned long long computeAns(const Characters& characters);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	int n;
	scanf("%d", &n);
	Characters characters;
	characters.reserve(100);
	unsigned long long ans;
	while (n--) {
		initCharacterTable(characters);
		ans = computeAns(characters);
		printf("%llu.%02llu$\n", ans / 100, ans % 100);
	}
	return 0;
}

void initCharacterTable(Characters& characters) {
	int k;
	scanf("%d", &k);
	characters.resize(k);
	for (int i = 0; i < k; ++i) {
		scanf("%*c%c%llu", &characters[i].first, &characters[i].second);
	}
	sort(characters.begin(), characters.end());
}

unsigned long long computeAns(const Characters& characters) {
	int m;
	scanf("%d%*c", &m);
	string str;
	str.reserve(Len);
	pair<string::iterator, string::iterator> range;
	unsigned long long ans = 0;
	while (m--) {
		getline(cin, str);
		sort(str.begin(), str.end());
		range.first = range.second = str.begin();
		for (size_t i = 0; (i < characters.size()) && (range.second != str.end()); ++i) {
			range = equal_range(range.second, str.end(), characters[i].first);
			ans += (range.second - range.first) * characters[i].second;
		}
	}
	return ans;
}