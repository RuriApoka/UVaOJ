#define LOCAL

#include <iostream>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> Student;
typedef int	Power;
typedef pair<Student, Power> Info;
typedef map<Student, Power> MyType;
typedef MyType::iterator MyIt;
typedef MyType::const_iterator MyCIt;

void readInfo(MyType& match, int n);
void printAns(const MyType& match);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	int n;
	cin >> n;
	MyType match;
	while (n != 0) {
		readInfo(match, n);
		printAns(match);
		match.clear();
		cin >> n;
	}
	return 0;
}

void readInfo(MyType& match, int n) {
	Info info;
	MyIt it;
	for (int i = 0; i < n; ++i) {
		cin >> info.first.first >> info.first.second;
		if (info.first.first > info.first.second) {
			swap(info.first.first, info.first.second);
			info.second = -1;
		}
		else {
			info.second = 1;
		}
		if (match.end() == (it = match.find(info.first))) {
			match.insert(info);
		}
		else {
			it->second += info.second;
		}
	}
}

void printAns(const MyType& match) {
	MyCIt cit = match.cbegin();
	while ((cit != match.cend()) && (0 == cit->second)) {
		++cit;
	}
	if (match.cend() == cit) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}