#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n, instructions, index;
	int postion;
	vector<int> op;
	op.reserve(100);
	string str;
	cin >> n;
	while (n--) {
		op.clear();
		postion = 0;
		cin >> instructions;
		while (instructions--) {
			cin >> str;
			if ('L' == str[0]) {
				op.push_back(-1);
				postion -= 1;
			}
			else if ('R' == str[0]) {
				op.push_back(1);
				postion += 1;
			}
			else {
				cin >> str;
				cin >> index;
				op.push_back(op[index - 1]);
				postion += op.back();
			}
		}
		cout << postion << endl;
	}
	return 0;
}