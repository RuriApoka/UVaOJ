#define LOCAL

#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

typedef pair<int, int> Martix;
typedef map<char, Martix> Martices;

void initMartices(Martices& martices);
int computeLine(Martices& martices, Martix& temp, int& ans);		//����һ�����ʽ��0��ʾ�޽⣬1��ʾ�н�
inline void myClear() { while (('\n' != cin.get()) && !cin.eof()); }

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	Martices martices;
	initMartices(martices);
	char ch;
	cin.get(ch);
	while (!cin.eof()) {
		if ('(' != ch) {
			cout << 0 << endl;
		}
		else {
			Martix temp;
			int ans = 0;
			if (1 == computeLine(martices, temp, ans)) {
				cout << ans << endl;
			}
			else {
				cout << "error" << endl;
			}
		}
		myClear();
		cin.get(ch);
	}
	return 0;
}

void initMartices(Martices& martices) {
	int n;
	cin >> n;
	char ch;
	int row, col;
	for (int i = 0; i < n; ++i) {
		cin >> ch >> row >> col;
		martices.insert({ ch, {row, col} });
		cin.get();
	}
}

int computeLine(Martices& martices, Martix& temp, int& ans) {
	char ch;
	vector<Martix> martix;
	while (')' != (ch = cin.get())) {
		if ('(' == ch) {
			if (0 == computeLine(martices, temp, ans)) {
				return 0;
			}
			else {
				martix.push_back(temp);				//�ɹ�����Ľ������temp��
			}
		}
		else {
			martix.push_back(martices[ch]);
		}
	}
	if (martix.empty()) {
		return 0;
	}
	else if (1 == martix.size()) {
		temp = martix[0];
		return 1;
	}
	else {
		temp = martix[0];
		for (size_t i = 1; i < martix.size(); ++i) {
			if (temp.second != martix[i].first) {
				return 0;
			}
			else {
				ans += temp.first * temp.second * martix[i].second;
				temp.second = martix[i].second;
			}
		}
		return 1;
	}
}