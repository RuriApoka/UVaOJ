#define LOCAL

#include <iostream>
#include <string>
#include <set>
#include <stack>
#include <utility>
#include <cstdio>
using namespace std;

typedef string Word;
typedef string List;
typedef Word::const_iterator WCIt;
typedef pair<WCIt, WCIt> WPair;
typedef set<List> Answer;
typedef Answer::const_iterator ACIt;
typedef stack<char> Stack;

bool readNewCase(Word& sour, Word& dest);
void computeAnswer(WPair sour, WPair dest, Stack stack, Answer& ans, List list);
void printAnswer(const Answer& ans);

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	Answer ans;
	Stack stack;
	Word sour, dest;
	List list;
	while (readNewCase(sour, dest)) {
		ans.clear();
		computeAnswer({ sour.begin(), sour.end() }, { dest.begin(), dest.end() }, stack, ans, list);
		printAnswer(ans);
	}
	return 0;
}

bool readNewCase(Word& sour, Word& dest) {
	cin >> sour;
	if (cin.eof()) {
		return false;
	}
	else {
		cin >> dest;
		return true;
	}
}

void computeAnswer(WPair sour, WPair dest, Stack stack, Answer& ans, List list) {
	if (dest.first == dest.second) {
		list[list.size() - 1] = '\n';
		ans.insert(list);
	}
	else if (sour.first == sour.second) {
		if (stack.top() == *dest.first) {
			list += "o ";
			stack.pop();
			++dest.first;
			computeAnswer(sour, dest, stack, ans, list);
			list.erase(list.end() - 2, list.end());
		}
	}
	else {
		if (!stack.empty() &&
			(stack.top() == *dest.first)) {
			list += "o ";
			char ch = stack.top();
			stack.pop();
			++dest.first;
			computeAnswer(sour, dest, stack, ans, list);
			--dest.first;
			stack.push(ch);
			list.erase(list.end() - 2, list.end());
		}
		list += "i ";
		stack.push(*sour.first);
		++sour.first;
		computeAnswer(sour, dest, stack, ans, list);
	}
}

void printAnswer(const Answer& ans) {
	cout << "[\n";
	for (ACIt it = ans.begin(); it != ans.end(); ++it) {
		cout << *it;
	}
	cout << "]\n";
}