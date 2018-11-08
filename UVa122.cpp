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
	bool assigned;								//表明该节点是否被赋过值
	BTNode *lchild, *rchild;
};

int constructBinaryTree(BTNode *root);			//-1表示读到文件结尾，0表示有节点被重复赋值，1表示二叉树创建完成(可能有节点未被赋值）
void printAndFree(BTNode *root);				//若有元素未被赋值，输出no complete，否则输出层序遍历
int translateString(BTNode *root, string& str);	//-1表示读到了该二叉树结尾，0表示某节点被重复赋值，1表示正常返回

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