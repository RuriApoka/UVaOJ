#include <iostream>
#include <string>
#include <vector>

const int MAX = 25;
int a[MAX];
std::vector<int> b[MAX];

void reset(int x, int ax)   //��ľ��x�Ϸ���ľ��ȫ������
{
	int t, i;
	
	i = b[ax].size();       //����ȷ����һ�ѵ����ж��ٸ�ľ��
	for(t = b[ax][--i]; t != x; t = b[ax][--i])
	{
		b[ax].pop_back();   //�ӵ�ľ�Ѷ�����ľ��
		b[t].push_back(t);  //������ľ��ѹ�س�ʼλ��
		a[t] = t;           //��¼�¸�ľ���µ�λ��
	}
}

void pile(int x, int ax, int ay)    //��x��ʼ�ƶ�����ľ��
{
	int i, j;

	i = b[ax].size() - 1;   //��¼�����ľ�Ѷ�����������
	for( ; b[ax][i] != x; i--) ;    //һֱ�������ƽ�����Ҫ��ѯ��ľ��x
	for(j = i; j < b[ax].size(); j++)
	{
		b[ay].push_back(b[ax][j]);  //�������Ͻ�ax�е�ľ��ŵ�ay��
		a[b[ax][j]] = ay;           //���¼�¼�¸�ľ�����ڵ���
	}
	for( ; j > i; j--)  b[ax].pop_back();   //�������Ժ�ʣ�µ�ľ���ӵ�
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
