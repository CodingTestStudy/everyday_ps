#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
vector<tuple<int, int, int>>v;
int dp[3][1001];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	auto [a, b, c] = v[0];
	dp[0][0] = a;
	dp[1][0] = b;
	dp[2][0] = c;
	for (int i = 1; i < n; i++) {
		auto [a, b, c] = v[i];
		dp[0][i] =a+ min(dp[1][i - 1], dp[2][i - 1]);
		dp[1][i] =b+ min(dp[0][i - 1], dp[2][i - 1]);
		dp[2][i] =c+ min(dp[1][i - 1], dp[0][i - 1]);
	}
	int MAX = min({ dp[0][n - 1], dp[1][n - 1], dp[2][n - 1] });
	cout << MAX;
}