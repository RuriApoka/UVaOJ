#include <iostream>
#include <string>
#include <vector>

const int MAX = 25;
int a[MAX];
std::vector<int> b[MAX];

void reset(int x, int ax)   //将木块x上方的木块全都移走
{
	int t, i;
	
	i = b[ax].size();       //首先确认这一堆到底有多少个木块
	for(t = b[ax][--i]; t != x; t = b[ax][--i])
	{
		b[ax].pop_back();   //扔掉木堆顶部的木块
		b[t].push_back(t);  //顶部的木块压回初始位置
		a[t] = t;           //记录下该木块新的位置
	}
}

void pile(int x, int ax, int ay)    //从x开始移动整个木堆
{
	int i, j;

	i = b[ax].size() - 1;   //记录下这个木堆顶部的纵坐标
	for( ; b[ax][i] != x; i--) ;    //一直将坐标推进到我要查询的木块x
	for(j = i; j < b[ax].size(); j++)
	{
		b[ay].push_back(b[ax][j]);  //自下往上将ax列的木块放到ay列
		a[b[ax][j]] = ay;           //重新记录下该木块所在的列
	}
	for( ; j > i; j--)  b[ax].pop_back();   //复制完以后剩下的木块扔掉
}

int main(void)
{
	using namespace std;
	
	string str1, str2;
	int n, i, j, x, y;
	cin >> n;

	for(i = 0; i < n; i++)  b[i].push_back(i);
	for(i = 0; i < n; i++)  a[i] = i;
	while((cin >> str1) && (str1 != "quit"))
	{
		cin >> x >> str2 >> y;
		if(a[x] == a[y])    continue;
		if(str1 == "move")
		{
			reset(x, a[x]);
			if(str2 == "onto")  reset(y, a[y]);
			b[a[y]].push_back(x);
			b[a[x]].pop_back();
			a[x] = a[y];
		}
		else
		{
			if(str2 == "onto")  reset(y, a[y]);
			pile(x, a[x], a[y]);
		}
	}
	for(i = 0; i < n; i++)
	{
		cout << i << ':';
		for(j = 0; j < b[i].size(); j++)    cout << ' ' << b[i][j];
		cout << endl;
	}
	
	return 0;
}
