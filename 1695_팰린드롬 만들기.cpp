#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int dp[5001][5001];
int n;
vector<int>v;
int sol(int st, int ed) {
	if (st >= ed)return 0;// �ε������� �������ų� �Ѿ�� 0��ȯ 
	int& res = dp[st][ed];
	if (res != -1)return res;// �ʱⰪ =-1 �ε� �̹̰����ִٸ� �װ��� ��ȯ

	if (v[st] == v[ed])res = sol(st + 1, ed - 1); //�������� �ε����� ��ĭ�� ����
	//56324-> 456324
	//*   *-> v*   *
	//56324->563245  �̷��� �ΰ��� ���
	//*   *->*   *v
	else res = min(1 + sol(st + 1, ed), 1 + sol(st, ed - 1));
	return res;
}
int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	memset(dp, -1, sizeof(dp));
	cout << sol(0, n - 1);
	
}