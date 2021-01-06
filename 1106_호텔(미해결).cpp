#include <iostream>
#include <vector>
#include <algorithm>
#define INF 99999999
using namespace std;

int c, n,dp;
int dp[2001];
vector<pair<int, int>>v;

int main() {
	cin >> c >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	fill(dp, dp + 2000, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		auto [a, b] = v[i];
		for(int j=b;j<2000;j++){
			dp[j] = min(dp[j], dp[j -b] + a);
		}
	}
	int ans = INF;
	for (int i = c; i < 2000; i++) {
		ans = min(dp[i], ans);
	}
	cout << ans;
}