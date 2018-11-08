#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main(void)
{
	int a, b;
	int len, pos;
	vector<int> ans;
	vector<int> search;
	vector<int> copy; 
	
	while(cin >> a >> b){
		cout << a << '/' << b << " = ";
		
		ans.push_back(a / b);
		search.push_back(a % b);
		copy.push_back(a % b);
		a = (a % b) * 10;
		while(1){
			ans.push_back(a / b);
			search.push_back(a % b);
			if(true == binary_search(copy.begin(), copy.end(), a % b))	break;
			copy.push_back(a % b);
			sort(copy.begin(), copy.end());
			a = (a % b) * 10;
		}
		for(int i = 0; i < search.size() - 1; i++){
			if(search[i] == search[search.size() - 1]){
				len = search.size() - i - 1;	//通过余数查询循环节的长度 
				pos = i + 1;					//循环节在ans中的起始位置 
				break;
			}
		}
		cout << ans[0] << '.';
		if(pos < 51){
			for(int i = 1; i < pos; i++){
				cout << ans[i];
			}
			cout << '(';
			if(ans.size() <= 51){
				for(int i = pos; i < pos + len; i++){
					cout << ans[i];
				}
				cout << ")\n";
			}
			else{
				for(int i = pos; i < 51; i++){
					cout << ans[i];
				}
				cout << "...)\n";
			}
		}
		else{
			for(int i = 1; i < 51; i++){
				cout << ans[i];
			}
			cout << "(...)\n";
		}
		cout << "   " << len << " = number of digits in repeating cycle\n\n";
		ans.resize(0);			//记得要重新调整容器大小 
		search.resize(0);
		copy.resize(0);
	}
	
	return 0;
}
