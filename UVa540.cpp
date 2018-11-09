#define LOCAL

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

typedef map<int, int> Team;
typedef queue<int> Queue;
typedef vector<Queue> Group;

bool init(Team& team, int& nums_of_teams);
void simulate(Team& team, int nums_of_teams, int times);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int i = 1;
	Team team;
	int nums_of_teams;
	while (init(team, nums_of_teams)) {
		simulate(team, nums_of_teams, i++);
		cout << endl;
	}
	return 0;
}

bool init(Team& team, int& nums_of_teams) {
	int nums;
	cin >> nums;
	if (0 != nums) {
		nums_of_teams = nums;
		team.clear();
		for (int i = 0; i < nums; ++i) {
			int n;
			cin >> n;
			int t;
			for (int j = 0; j < n; ++j) {
				cin >> t;
				team.insert({ t, i });
			}
		}
		return true;
	}
	else {
		return false;
	}
}

void simulate(Team& team, int nums_of_teams, int times) {
	cout << "Scenario #" << times << endl;
	Group group(nums_of_teams);
	Queue order;
	string t;
	int x, team_number;
	for (cin >> t; 'S' != t[0]; cin >> t) {
		if ('E' == t[0]) {
			cin >> x;
			team_number = team[x];
			if (group[team_number].empty()) {
				order.push(team_number);
			}
			group[team_number].push(x);
		}
		else {
			team_number = order.front();
			cout << group[team_number].front() << endl;
			group[team_number].pop();
			if (group[team_number].empty()) {
				order.pop();
			}
		}
	}
}