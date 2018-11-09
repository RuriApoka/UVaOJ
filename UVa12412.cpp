#define LOCAL

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Student {
	long long SID;
	int CID;
	string name;
	int chinese;
	int mathematics;
	int english;
	int programming;
	int total_score;
	double average_score;
};

struct Class {
	vector<int> total_scores;
	vector<int> pass_nums;
	int total_students;
	vector<int> pass_over_n_nums;
	int total_students;
};

bool programRun();
int mainMenu();
void addStudent();
void removeStudent();
void queryStudent();
void showRanklist();
void showStatistics();

vector<Student> students;
vector<int> per_student_total_score;
vector<int> per_class_total_score(21);
set<long long> SID;
const double eps = 1e-5;

int main(void) {
#ifdef LOCAL
	FILE *a;
	freopen_s(&a, "input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	cout.precision(2);
	cout.setf(ios::fixed);
	while (programRun()) {
		;
	}
	return 0;
}