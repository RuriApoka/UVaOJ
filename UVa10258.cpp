#define LOCAL

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const int TEAMS = 101;
const int PROBLEMS = 10;

struct Team {
	int solved_problems;
	int solved[PROBLEMS];
	int unsolved[PROBLEMS];
};

struct Result {
	int tid;
	int solved;
	int times;
	Result(int a, int b, int c) : tid(a), solved(b), times(c) {};
};

typedef vector<Result> RankList;

void readLog(Team teams[], int disappear[]);
void computeAns(const Team teams[], RankList& ranklist, const int disappear[]);
inline void printRankList(const RankList& ranklist, int kase);
bool cmp(const Result& lhs, const Result& rhs);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int kase = 0;
	Team teams[TEAMS];
	RankList ranklist;
	ranklist.reserve(TEAMS);
	int disappear[TEAMS];
	int n;
	scanf("%d%*c%*c", &n);
	while (n--) {
		ranklist.clear();
		memset(teams, 0, sizeof(teams));
		memset(disappear, 0, sizeof(disappear));
		readLog(teams, disappear);
		computeAns(teams, ranklist, disappear);
		printRankList(ranklist, kase++);
	}
	return 0;
}

void readLog(Team teams[], int disappear[]) {
	int tid, pid, time;
	char state;
	string str;
	stringstream ss;
	while (getline(cin, str) && !str.empty()) {
		ss.clear();
		ss.str(str);
		ss >> tid >> pid >> time >> state;
		disappear[tid] = 1;
		switch (state) {
		case 'C':
			if (0 == teams[tid].solved[pid]) {
				teams[tid].solved_problems++;
				teams[tid].solved[pid] = time;
			}
			break;
		case 'I':
			if (0 == teams[tid].solved[pid]) {
				teams[tid].unsolved[pid]++;
			}
			break;
		default:
			break;
		}
	}
}

void computeAns(const Team teams[], RankList& ranklist, const int disappear[]) {
	for (int tid = 1; tid < TEAMS; ++tid) {
		if (1 == disappear[tid]) {
			int times = 0;
			for (int pid = 1; pid < PROBLEMS; ++pid) {
				if (0 != teams[tid].solved[pid]) {
					times += teams[tid].solved[pid];
					times += teams[tid].unsolved[pid] * 20;
				}
			}
			ranklist.push_back(Result(tid, teams[tid].solved_problems, times));
		}
	}
	sort(ranklist.begin(), ranklist.end(), cmp);
}

void printRankList(const RankList& ranklist, int kase) {
	if (0 != kase) {
		putchar('\n');
	}
	for (size_t i = 0; i < ranklist.size(); ++i) {
		printf("%d %d %d\n", ranklist[i].tid, ranklist[i].solved, ranklist[i].times);
	}
}

bool cmp(const Result& lhs, const Result& rhs) {
	if (lhs.solved != rhs.solved) {
		return lhs.solved > rhs.solved;
	}
	else if (lhs.times != rhs.times) {
		return lhs.times < rhs.times;
	}
	else {
		return (lhs.tid < rhs.tid);
	}
}