#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long dp[2][91];
int main() {
	fastio;
	dp[1][1] = 1;
	dp[0][2] = 1;
	int n; cin >> n;
	for (int i = 3; i <= n; i++) {
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
		dp[1][i] = dp[0][i - 1];
	}
	cout << dp[0][n] + dp[1][n];
}
