#include <iostream>
#include <algorithm>

using namespace std;

struct pallet{
	int a, b;
}p[6];

bool comp(pallet x, pallet y)	//�Ȱ���a����a���ʱ����b���� 
{
	return ((x.a == y.a) ? (x.b > y.b) : (x.a > y.a));
}

int main(void)
{
	while(cin >> p[0].a >> p[0].b){
		if(p[0].a < p[0].b)	swap(p[0].a, p[0].b);	//ͨ��swap��֤a >= b 
		for(int i = 1; i < 6; i++){
			cin >> p[i].a >> p[i].b;
			if(p[i].a < p[i].b)	swap(p[i].a, p[i].b);
		}
		sort(p, p+6, comp);		//������������ 
		bool match = true;
		for(int i = 0; i < 6; i += 2){
			if((p[i].a != p[i+1].a) || (p[i].b != p[i+1].b)){	//��������ڵ����������ǾͲ��Գ� 
				match = false;
				break;
			}
		}
		//����ֱ�ӹ���˶���������ۣ���Ϊ��ab��˳�����У�����ֻ�п��ܻ���������� 
		if((!match) || (p[0].a != p[2].a) || (p[0].b != p[4].a) || (p[2].b != p[4].b))
			cout << "IMPOSSIBLE" << endl;
		else
			cout << "POSSIBLE" << endl;
	}
	
	return 0;
}
