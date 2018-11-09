#define LOCAL

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

bool init(string& top, string& bottom);
bool inMiddle(const string& top, const string& bottom);
int lengthOfLeft(const string& top, const string& bottom);
int lengthOfRight(string& top, string& bottom);

int main(void) {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	string top, bottom;
	while (init(top, bottom)) {
		if (inMiddle(top, bottom)) {
			cout << bottom.size() << endl;
		}
		else {
			int left_len, right_len;
			left_len = lengthOfLeft(top, bottom);
			right_len = lengthOfRight(top, bottom);
			cout << min(left_len, right_len) << endl;
		}
	}
	return 0;
}

bool init(string& top, string& bottom) {
	if (cin >> top >> bottom) {
		if (top.size() > bottom.size()) {
			swap(top, bottom);
		}
		return true;
	}
	else {
		return false;
	}
}

bool inMiddle(const string& top, const string& bottom) {
	const char BOUND = '3';
	bool in_middle = false;
	for (size_t i = 0; i <= (bottom.size() - top.size()); ++i) {
		size_t j;
		for (j = 0; j < top.size(); j++) {
			if ((top[j] - '0' + bottom[i + j]) > BOUND) {
				j = top.size() + 1;
			}
		}
		if (top.size() == j) {
			in_middle = true;
			i = bottom.size() - top.size();
		}
	}
	return in_middle;
}

int lengthOfLeft(const string& top, const string& bottom) {
	const char BOUND = '3';
	for (size_t i = 1; i < top.size(); ++i) {
		size_t j;
		for (j = i; j < top.size(); ++j) {
			if ((top[j] - '0' + bottom[j - i]) > BOUND) {
				break;
			}
		}
		if (top.size() == j) {
			return i + bottom.size();
		}
	}
	return top.size() + bottom.size();
}

int lengthOfRight(string& top, string& bottom) {
	reverse(top.begin(), top.end());
	reverse(bottom.begin(), bottom.end());
	return  lengthOfLeft(top, bottom);
}
