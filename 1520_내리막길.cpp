#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int n, m;
int arr[501][501];
int dp[501][501];
int recurse(int x, int y) {
	if (x == 0 && y == 0)return 1;
	int& ret = dp[x][y];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x - dx[i];
		int ny = y - dy[i];
		if (nx >= n || ny >= m || nx < 0 || ny < 0)continue;
		if (arr[nx][ny] <= arr[x][y])continue;
		ret += recurse(nx, ny);
	}
	return ret;
}
int main() {
	fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> arr[i][j];
	memset(dp, -1, sizeof(dp));
	cout<<recurse(n - 1, m - 1);
}