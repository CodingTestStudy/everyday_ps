#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int dp[5001][5001];
int n;
vector<int>v;
int sol(int st, int ed) {
	if (st >= ed)return 0;// 인덱스값이 같아지거나 넘어가면 0반환 
	int& res = dp[st][ed];
	if (res != -1)return res;// 초기값 =-1 인데 이미값이있다면 그값을 반환

	if (v[st] == v[ed])res = sol(st + 1, ed - 1); //같은경우는 인덱스값 한칸씩 당긴다
	//56324-> 456324
	//*   *-> v*   *
	//56324->563245  이렇게 두가지 경우
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