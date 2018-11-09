#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s, t;
	while(cin >> s >> t){
		int i, j;
		for(i = j = 0; (i < s.size()) && (j < t.size()); j++){
			if(s[i] == t[j])	i++;
		}
		cout << (i == s.size() ? "Yes" : "No") << endl;
	}
	
	return 0;
}
