#define LOCAL

#include <iostream>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	ios::sync_with_stdio(false);
	int a, b, c, d;
	int ans;
	for (cin >> a >> b >> c >> d; a | b | c | d; cin >> a >> b >> c >> d) {
		ans = 0;
		ans += (a < b) ? (a - b + 40) : (a - b);		//��ʮ���ƣ�����������ʮ�ö�����ֵ��Ҳ��ָ��ת���ľ���
		ans += (c < b) ? (c - b + 40) : (c - b);		//��Ҫ������ȵ������ȡ���Ⱥŵĵط����ܼ���ʮ
		ans += (c < d) ? (c - d + 40) : (c - d);
		ans *= 9;
		ans += 1080;
		cout << ans << endl;
	}
	return 0;
}