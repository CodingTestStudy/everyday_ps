#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m;
int main() {
	fastio;
	cin >> n >> m;
	string a, b; cin >> a >> b;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 0; i <= n; i++) dp[i][0] = i;
	for (int j = 0; j <= m; j++) dp[0][j] = j;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
		else if(a[i-1]=='i'&&(b[j-1]=='j'||b[j-1]=='l'))dp[i][j] = dp[i - 1][j - 1];
		else if(a[i-1]=='v'&&b[j-1]=='w')dp[i][j] = dp[i - 1][j - 1];
		else dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
	}
	cout << dp[n][m] << '\n';
}