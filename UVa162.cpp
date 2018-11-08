#define LOCAL

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

typedef list<char> Type;
typedef vector<Type> MyType;

const int CARDS = 52;
const string END = "#";
map<char, int> COVER = { {'J', 1}, {'Q', 2}, {'K', 3}, {'A', 4} };

bool readNewCase(MyType& player);
void simulate(MyType& player, Type& heap);
inline void printAnswer(MyType& player, Type& heap) { printf("%d%3d\n", (player[0].empty() ? 1 : 2), (CARDS - heap.size())); }
inline bool isFace(char ch) { return (('J' == ch) || ('Q' == ch) || ('K' == ch) || ('A' == ch)); }
int dual(MyType& player, Type& heap, int cur, int need);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	Type heap;
	MyType player;			//player[0] is no_dealer£¬player[1] is dealer
	while (readNewCase(player)) {
		simulate(player, heap);
		printAnswer(player, heap);
	}
	return 0;
}

bool readNewCase(MyType& player) {
	player.clear();
	player.resize(2);
	string str;
	cin >> str;
	if (END == str) {
		return false;
	}
	else {
		player[0].push_front(str.back());
		for (int i = 1; i < CARDS; ++i) {
			cin >> str;
			player[i % 2].push_front(str.back());
		}
		return true;
	}
}

void simulate(MyType& player, Type& heap) {
	heap.clear();
	int cur = 0;
	char ch;
	while (1) {
		ch = player[cur].front();
		player[cur].erase(player[cur].begin());
		heap.push_back(ch);
		if (isFace(ch)) {
			cur = dual(player, heap, (cur + 1) % 2, COVER[ch]);
			if (player[0].empty() || player[1].empty()) {
				return;
			}
		}
		else {
			cur = (cur + 1) % 2;
			if (player[0].empty() || player[1].empty()) {
				cur = player[0].empty() ? 1 : 0;
				ch = player[cur].front();
				player[cur].erase(player[cur].begin());
				heap.push_back(ch);
				return;
			}
		}
	}
}

int dual(MyType& player, Type& heap, int cur, int need) {
	char ch;
	while (!player[cur].empty() && (need--)) {
		ch = player[cur].front();
		player[cur].erase(player[cur].begin());
		heap.push_back(ch);
		if (isFace(ch)) {
			need = COVER[ch];
			cur = (cur + 1) % 2;
		}
	}
	cur = (cur + 1) % 2;
	if (!player[(cur + 1) % 2].empty()) {
		player[cur].splice(player[cur].end(), heap);
	}
	else if (0 == need) {
		player[cur].splice(player[cur].end(), heap);
		ch = player[cur].front();
		player[cur].erase(player[cur].begin());
		heap.push_back(ch);
	}
	return cur;
}