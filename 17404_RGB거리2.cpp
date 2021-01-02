#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
int arr[3][1001];
int dp[3][1001];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)for (int j = 0; j < 3; j++) cin >> arr[i][j];
	
	int ans = 1e9;
	//처음에 1번을 선택햇다고 하자 그럼 
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[0][0];
	dp[2][0] = arr[0][0];
	for (int i = 1; i < n ; i++) {
		if (i != n - 1) {
			dp[0][i] = arr[i][0] + min(dp[1][i - 1], dp[2][i - 1]);
			dp[1][i] = arr[i][1] + min(dp[0][i - 1], dp[2][i - 1]);
			dp[2][i] = arr[i][2] + min(dp[0][i - 1], dp[1][i - 1]);
			continue;
		}
		dp[1][i] = arr[i][1] + min(dp[0][i - 1], dp[2][i - 1]);
		dp[2][i] = arr[i][2] + min(dp[0][i - 1], dp[1][i - 1]);
		ans = min(dp[1][i], dp[2][i]);
		
	}
	memset(dp, false, sizeof(dp));
	//2번째꺼 선택
	dp[0][0] = arr[0][1];
	dp[1][0] = arr[0][1];
	dp[2][0] = arr[0][1];
	for (int i = 1; i < n; i++) {
		if (i != n - 1) {
			dp[0][i] = arr[i][0] + min(dp[1][i - 1], dp[2][i - 1]);
			dp[1][i] = arr[i][1] + min(dp[0][i - 1], dp[2][i - 1]);
			dp[2][i] = arr[i][2] + min(dp[0][i - 1], dp[1][i - 1]);
			continue;
		}
		dp[0][i] = arr[i][0] + min(dp[1][i - 1], dp[2][i - 1]);
		dp[2][i] = arr[i][2] + min(dp[0][i - 1], dp[1][i - 1]);
		ans = min(ans,min(dp[0][i], dp[2][i]));
		
	}
	memset(dp, false, sizeof(dp));
	dp[0][0] = arr[0][2];
	dp[1][0] = arr[0][2];
	dp[2][0] = arr[0][2];
	for (int i = 1; i < n; i++) {
		if (i != n - 1) {
			dp[0][i] = arr[i][0] + min(dp[1][i - 1], dp[2][i - 1]);
			dp[1][i] = arr[i][1] + min(dp[0][i - 1], dp[2][i - 1]);
			dp[2][i] = arr[i][2] + min(dp[0][i - 1], dp[1][i - 1]);
			continue;
		}
		dp[0][i] = arr[i][0] + min(dp[1][i - 1], dp[2][i - 1]);
		dp[1][i] = arr[i][1] + min(dp[0][i - 1], dp[2][i - 1]);

		ans = min(ans,min(dp[1][i], dp[0][i]));
		
	}
	cout << ans;
}