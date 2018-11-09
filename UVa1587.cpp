#include <iostream>
#include <algorithm>

using namespace std;

struct pallet{
	int a, b;
}p[6];

bool comp(pallet x, pallet y)	//先按照a排序，a相等时按照b排序 
{
	return ((x.a == y.a) ? (x.b > y.b) : (x.a > y.a));
}

int main(void)
{
	while(cin >> p[0].a >> p[0].b){
		if(p[0].a < p[0].b)	swap(p[0].a, p[0].b);	//通过swap保证a >= b 
		for(int i = 1; i < 6; i++){
			cin >> p[i].a >> p[i].b;
			if(p[i].a < p[i].b)	swap(p[i].a, p[i].b);
		}
		sort(p, p+6, comp);		//对六个面排序 
		bool match = true;
		for(int i = 0; i < 6; i += 2){
			if((p[i].a != p[i+1].a) || (p[i].b != p[i+1].b)){	//排序后相邻的如果不相等那就不对称 
				match = false;
				break;
			}
		}
		//排序直接规避了多种情况讨论，因为是ab的顺序排列，所以只有可能会是这种组合 
		if((!match) || (p[0].a != p[2].a) || (p[0].b != p[4].a) || (p[2].b != p[4].b))
			cout << "IMPOSSIBLE" << endl;
		else
			cout << "POSSIBLE" << endl;
	}
	
	return 0;
}
