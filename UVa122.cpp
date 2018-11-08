#define LOCAL

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

struct BTNode {
	BTNode() {
		value = 0;
		assigned = false;
		lchild = rchild = nullptr;
	}
	int value;
	bool assigned;								//�����ýڵ��Ƿ񱻸���ֵ
	BTNode *lchild, *rchild;
};

int constructBinaryTree(BTNode *root);			//-1��ʾ�����ļ���β��0��ʾ�нڵ㱻�ظ���ֵ��1��ʾ�������������(�����нڵ�δ����ֵ��
void printAndFree(BTNode *root);				//����Ԫ��δ����ֵ�����no complete����������������
int translateString(BTNode *root, string& str);	//-1��ʾ�����˸ö�������β��0��ʾĳ�ڵ㱻�ظ���ֵ��1��ʾ��������

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	BTNode *root = new BTNode;
	int result = constructBinaryTree(root);
	while (-1 != result) {
		if (0 == result) {
			cout << "not complete" << endl;
		}
		else {
			printAndFree(root);
		}
		root = new BTNode;
		result = constructBinaryTree(root);
	}
	delete root;
	return 0;
}

int constructBinaryTree(BTNode *root) {
	string str;
	cin >> str;
	if (cin.eof()) {
		return -1;
	}
	else {
		int result = 1;
		int t;
		while (-1 != (t = translateString(root, str))) {
			if (0 == t) {
				result = 0;
				while (2 != str.size()) {
					cin >> str;
				}
				break;
			}
			cin >> str;
		}
		return result;
	}
}

void printAndFree(BTNode *root) {
	queue<BTNode *> q;
	q.push(root);
	vector<int> ans;
	ans.reserve(250);
	bool all_assigned = true;
	for (BTNode *t = q.front(); !q.empty(); q.pop()) {
		t = q.front();
		if (!t->assigned) {
			all_assigned = false;
		}
		if (nullptr != t->lchild) {
			q.push(t->lchild);
		}
		if (nullptr != t->rchild) {
			q.push(t->rchild);
		}
		ans.push_back(t->value);
		delete t;
	}
	if (all_assigned) {
		cout << ans[0];
		for (size_t i = 1; i < ans.size(); ++i) {
			cout << ' ' << ans[i];
		}
		cout << endl;
	}
	else {
		cout << "not complete" << endl;
	}
}

int translateString(BTNode *root, string& str) {
	if (2 == str.size()) {
		return -1;
	}
	else {
		int value = 0;
		int i = 1;
		for (; isdigit(str[i]); ++i) {
			value *= 10;
			value += str[i] - '0';
		}
		BTNode *t = root;
		++i;
		while (')' != str[i]) {
			if ('L' == str[i]) {
				if (nullptr == t->lchild) {
					t->lchild = new BTNode;
				}
				t = t->lchild;
			}
			else {
				if (nullptr == t->rchild) {
					t->rchild = new BTNode;
				}
				t = t->rchild;
			}
			++i;
		}
		if (t->assigned) {
			return 0;
		}
		else {
			t->value = value;
			t->assigned = true;
			return 1;
		}
	}
}