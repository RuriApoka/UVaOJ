#include <iostream>
#include <map>
#include <set>
using namespace std;

typedef map<int, int> Categorie;
typedef Categorie::iterator CateIt;
typedef map<int, set<int> > Course;
typedef Course::iterator CourseIt;
typedef set<int>::const_iterator SetCIt;

bool readNewCase(Course& course, Categorie& categorie);
bool meetRequirements(Course& course, Categorie& categorie);

int main() {
	Course course;
	Categorie categorie;
	while (readNewCase(course, categorie)) {
		if (meetRequirements(course, categorie)) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}

bool readNewCase(Course& course, Categorie& categorie) {
	int k, m, c, r;
	cin >> k;
	if (0 == k) {
		return false;
	}
	else {
		cin >> m;
		course.clear();
		int t;
		for (int i = 0; i < k; ++i) {
			cin >> t;
			course.insert({ t, {} });
		}
		categorie.clear();
		CourseIt it;
		for (int i = 0; i < m; ++i) {
			cin >> c >> r;
			categorie.insert({ i, r });
			for (int j = 0; j < c; ++j) {
				cin >> t;
				if (course.end() != (it = course.find(t))) {
					it->second.insert(i);
				}
			}
		}
	}
	return true;
}

bool meetRequirements(Course& course, Categorie& categorie) {
	for (CourseIt i = course.begin(); i != course.end(); ++i) {
		for (SetCIt j = i->second.cbegin(); j != i->second.cend(); ++j) {
			categorie[*j]--;
		}
	}
	for (CateIt i = categorie.begin(); i != categorie.end(); ++i) {
		if (i->second > 0) {
			return false;
		}
	}
	return true;
}