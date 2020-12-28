#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dp[15][15];
int main() {
	for (int i = 1; i < 15; i++) {
		dp[0][i] = i;
	}
	for (int j = 1; j < 15; j++) {
		for (int k = 1; k < 15; k++) {
		int sum = 0;
			for (int i = 1; i <= k; i++) {
				sum += dp[j - 1][i];
			}
			dp[j][k] = sum;
		}
	}
	int n; cin >> n;
	while (n--) {
		int a, b; cin >> a >> b;
		cout << dp[a][b] << endl;
	}
}