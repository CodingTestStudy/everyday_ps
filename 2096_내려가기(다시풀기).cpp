#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;
int dp[100001][3];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
	cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
	}
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])+dp[i][0];
		dp[i][1] = max({ dp[i - 1][0],dp[i - 1][1],dp[i - 1][2] }) + dp[i][1];
		dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + dp[i][2];
	}
	int MAX = max({ dp[n - 1][0],dp[n - 1][1],dp[n - 1][2] });
	cout << MAX << " ";
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + dp[i][0];
		dp[i][1] = min({ dp[i - 1][0],dp[i - 1][1],dp[i - 1][2] }) + dp[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + dp[i][2];
	}
	int MIN = min({ dp[n - 1][0],dp[n - 1][1],dp[n - 1][2] });
	cout << MIN;
}