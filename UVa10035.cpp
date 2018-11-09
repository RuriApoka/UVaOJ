#define LOCAL

#include <iostream>
#include <string>
using namespace std;

bool have_new_case(string& first, string& second) {
	cin >> first >> second;
	return (("0" != first) || ("0" != second));
}

int get_carry_operations(const string& first, const string& second) {
	bool carry = false;
	int carry_operations = 0;
	
	int i = first.size() - 1;
	int j = second.size() - 1;
	for (; (i > -1) && (j > -1); --i, --j) {
		carry = ((first[i] - '0') + (second[j] - '0') + carry) > 9 ? true : false;
		if (carry)
			carry_operations++;
	}
	if (carry)
		if (i > -1)
			for (; (i > -1) && ('9' == first[i]); --i)
				carry_operations++;
		else if (j > -1)
			for (; (j > -1) && ('9' == second[j]); --j)
				carry_operations++;

	return carry_operations;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int carry_operations;
	string first, second;
	while (have_new_case(first, second)) {
		carry_operations = get_carry_operations(first, second);
		if (0 == carry_operations)
			cout << "No carry operation.\n";
		else if (1 == carry_operations)
			cout << "1 carry operation.\n";
		else
			cout << carry_operations << " carry operations.\n";
	}

	return 0;
}