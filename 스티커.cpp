#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#define f ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using namespace std;
int dp[100001][2][2];
int n, m;
int map[100001][2];
int main() {

	cin >> n;
	while (n--) {
		cin >> m;
		int k = 2;
		for(int j=0; j<2; j++){
			for (int i = 0; i < m; i++) {
				cin >> dp[i][j][1];
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < m; j++) {
				dp[j][i][1] = dp[j - 1][i][0] + dp[j][i - 1][0];
				dp[j][i][0] = dp[j - 1][i][1] + dp[j][i - 1][1];
			}
		}
	}
}