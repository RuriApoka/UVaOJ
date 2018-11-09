#define LOCAL

#include <iostream>
#include <utility>
#include <set>
#include <cstdio>
using namespace std;

typedef pair<int, int> Task;
typedef multiset<Task> TaskList;
typedef TaskList::const_iterator It;

bool ReadInfo(TaskList& tasklist);
bool IsConflict(const TaskList& tasklist);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	TaskList tasklist;
	while (ReadInfo(tasklist)) {
		cout << (IsConflict(tasklist) ? "CONFLICT\n" : "NO CONFLICT\n");
		tasklist.clear();
	}
	return 0;
}

bool ReadInfo(TaskList& tasklist) {
	int n, m;
	cin >> n >> m;
	if ((0 == n) && (0 == m)) {
		return false;
	}
	else {
		static const int MAX = 1000000;
		int start, end, interval;
		for (int i = 0; i < n; ++i) {
			cin >> start >> end;
			tasklist.insert({ start, end });
		}
		for (int i = 0; i < m; ++i) {
			cin >> start >> end >> interval;
			do {
				tasklist.insert({ start, end });
				start += interval;
				end += interval;
			} while (end < MAX);
			if (start < MAX) {
				tasklist.insert({ start, MAX });
			}
		}
		return true;
	}
}

bool IsConflict(const TaskList& tasklist) {
	It lhs = tasklist.cbegin();
	It rhs = lhs;
	It end = tasklist.cend();
	for (++rhs; rhs != end; ++lhs, ++rhs) {
		if (lhs->second > rhs->first) {
			return true;
		}
	}
	return false;
}