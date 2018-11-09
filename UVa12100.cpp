#define LOCAL

#include <iostream>
#include <queue>
#include <map>
#include <utility>
using namespace std;

typedef pair<int, bool> Job;
typedef map<int, int> PriorityNumbers;
typedef queue<Job> PrintQueue;

int readJobs(PrintQueue& tasks, PriorityNumbers& numbers);
int waitMinuts(PrintQueue& tasks, PriorityNumbers& numbers, int target);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	int n;
	cin >> n;
	while (n--) {
		PrintQueue tasks;
		PriorityNumbers numbers;
		int target = readJobs(tasks, numbers);
		cout << waitMinuts(tasks, numbers, target) << endl;
	}
	return 0;
}

int readJobs(PrintQueue& tasks, PriorityNumbers& numbers) {
	for (int i = 1; i < 10; ++i) {
		numbers.insert({ i, 0 });
	}

	int n, m, priority, target;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> priority;
		if (i == m) {
			target = priority;
			tasks.push({ priority, true });
		}
		else {
			tasks.push({ priority, false });
		}
		numbers[priority]++;
	}

	return target;
}

int waitMinuts(PrintQueue& tasks, PriorityNumbers& numbers, int target) {
	int minuts = 0;
	Job job;
	for (int i = 9; i > target; --i) {
		while (numbers[i] > 0) {
			job = tasks.front();
			tasks.pop();
			if (job.first == i) {
				minuts++;
				numbers[i]--;
			}
			else {
				tasks.push(job);
			}
		}
	}
	while (1) {
		job = tasks.front();
		tasks.pop();
		if (job.first == target) {
			if (job.second == true) {
				return ++minuts;
			}
			else {
				++minuts;
			}
		}
		else {
			tasks.push(job);
		}
	}
}