#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[2][100001];
int dp[100001][2][2];
int main() {
	int test; cin >> test;
	while (test--) {
		int n; cin >> n;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < 2; i++)for (int j = 0; j < n; j++)cin >> arr[i][j];
		dp[0][0][1] = arr[0][0];
		dp[0][1][1] = arr[1][0];
		for (int i = 1; i < n; i++)for (int j = 0; j < 2; j++) {
			dp[i][j][1] = max(dp[i - 1][j][0], dp[i - 1][1 - j][1]) + arr[j][i];
			dp[i][j][0] = max(dp[i - 1][j][1], dp[i - 1][1 - j][1]);
		}
		cout << max({ dp[n - 1][0][1],dp[n - 1][1][1],dp[n - 1][0][0],dp[n - 1][1][0] }) << endl;
	}
}