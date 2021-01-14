#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int>v;
int n;
int dp[501][501];
int sum[501];
int topdown(int st, int ed) {
	if (st == ed)return 0;
	int& ret = dp[st][ed];
	if (ret != -1)return ret;
	for (int i = st; i < ed; i++) {
		int temp= topdown(st, i) + topdown(i + 1, ed)+sum[ed]-sum[st-1];
		if (ret == -1)ret = temp;
		else ret = min(ret, temp);
	}
	return ret;
}
int main() {
	int num; cin >> num;
	while (num--) {
		cin >> n; 
		v.clear();
		v.resize(n+1);
		memset(dp, -1, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			sum[i] = sum[i - 1] + v[i];
		}

		cout << topdown(1, n) << endl;
	}
}