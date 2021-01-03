#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[101];
int main() {
	int test; cin >> test;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;
	for (int i = 7; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	while (test--) {
		int a; cin >> a;
		cout << dp[a] << "\n";
	}
}