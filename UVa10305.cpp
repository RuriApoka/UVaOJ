#define LOCAL

#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

void init(vector<int>& nums_of_last_tasks, vector<list<int> >& next_tasks, int edges);
void bfs(vector<int>& nums_of_last_tasks, vector<list<int> >& next_tasks, vector<int>& ans, int ans_index);
void printAnswer(vector<int>& ans);
void setQueue(vector<int>& nums_of_last_tasks, vector<bool>& visited, queue<int>& next_node);

int main(void) {
#ifdef LOCAL
	FILE *a, *b;
	freopen_s(&a, "input.txt", "r", stdin);
	freopen_s(&b, "output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int n, m;
	while ((cin >> n >> m) && (n || m)) {
		vector<int> nums_of_last_tasks(n + 1, 0);
		vector<list<int> > next_tasks(n + 1);
		init(nums_of_last_tasks, next_tasks, m);
		vector<int> ans(n);
		bfs(nums_of_last_tasks, next_tasks, ans, 0);
		printAnswer(ans);
	}
	return 0;
}

void init(vector<int>& nums_of_last_tasks, vector<list<int> >& next_tasks, int edges) {
	int x, y;
	for (int i = 0; i < edges; ++i) {
		cin >> x >> y;
		nums_of_last_tasks[y]++;
		next_tasks[x].push_back(y);
	}
}

void bfs(vector<int>& nums_of_last_tasks, vector<list<int> >& next_tasks, vector<int>& ans, int ans_index) {
	vector<bool> visited(nums_of_last_tasks.size(), false);
	queue<int> next_node;
	setQueue(nums_of_last_tasks, visited, next_node);
	while (!next_node.empty()) {
		int t = next_node.front();
		next_node.pop();
		ans[ans_index++] = t;
		for (list<int>::iterator it = next_tasks[t].begin(); it != next_tasks[t].end(); ++it) {
			nums_of_last_tasks[*it]--;
		}
		if (next_node.empty()) {
			setQueue(nums_of_last_tasks, visited, next_node);
		}
	}
}

void printAnswer(vector<int>& ans) {
	for (size_t i = 0; i < ans.size(); i++) {
		if (0 != i) {
			cout.put(' ');
		}
		cout << ans[i];
	}
	cout.put('\n');
}

void setQueue(vector<int>& nums_of_last_tasks, vector<bool>& visited, queue<int>& next_node) {
	for (size_t i = 1; i < nums_of_last_tasks.size(); ++i) {
		if (!visited[i] && (0 == nums_of_last_tasks[i])) {
			visited[i] = true;
			next_node.push(i);
		}
	}
}