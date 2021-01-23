#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string s;
int n;
int dp[5001][5001];
int recur(int st, int ed) {
	if (st >= ed)return 0;
	int& ret = dp[st][ed];
	if (ret != -1)return ret;
	if (s[st] == s[ed])ret = recur(st + 1, ed - 1);
	else ret = min(recur(st + 1, ed), recur(st, ed - 1)) + 1;
	return ret;
}
int main() {
	cin >> n >> s;
	memset(dp, -1, sizeof(dp));
	recur(0, n - 1);
	cout << dp[0][n - 1];
}