#define LOCAL

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <iterator>
using namespace std;

int ID(map<set<int>, int>& set_ID, vector<set<int> >& sets, set<int>& s);

int main(void) {
#ifdef LOCAL
	FILE *z;
	freopen_s(&z, "input.txt", "r", stdin);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int test;
	cin >> test;
	while (test--) {
		map<set<int>, int> set_ID;
		vector<set<int> > sets;
		stack<int> set_stack;
		set<int> empty_set = set<int>();
		string command;
		int commands;
		cin >> commands;
		while (commands--) {
			cin >> command;
			if ('P' == command[0]) {
				set_stack.push(ID(set_ID, sets, empty_set));
			}
			else if ('D' == command[0]) {
				set_stack.push(set_stack.top());
			}
			else {
				set<int> a = sets[set_stack.top()];
				set_stack.pop();
				set<int> b = sets[set_stack.top()];
				set_stack.pop();
				set<int> c;
				switch (command[0])
				{
				case'U':
					set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
					break;
				case'I':
					set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
					break;
				case'A':
					c = b;
					c.insert(ID(set_ID, sets, a));
					break;
				default:
					break;
				}
				set_stack.push(ID(set_ID, sets, c));
			}
			cout << sets[set_stack.top()].size() << endl;
		}
		cout << "***" << endl;
	}
}

int ID(map<set<int>, int>& set_ID, vector<set<int> >& sets, set<int>& s) {
	map<set<int>, int>::iterator it;
	if (set_ID.end() != (it = set_ID.find(s))) {
		return it->second;
	}
	else {
		sets.push_back(s);
		set_ID.insert({ s, sets.size() - 1 });
		return sets.size() - 1;
	}
}