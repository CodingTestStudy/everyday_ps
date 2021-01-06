#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 200001
using namespace std;
long long dp[MAX];
long long arr[MAX];
int main() {
	int n; cin >> n;
	while (n--) {
		int num; cin >> num;
		long long ans = 0;
		fill(dp, dp + MAX, 0);
		for (int i = 0; i < num; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < num; i++) {
			if(dp[i]< arr[i])dp[i]=arr[i];
			if (arr[i] + i < num)if (dp[i + arr[i]] < arr[i + arr[i]] + dp[i])dp[i + arr[i]] = arr[i + arr[i]] + dp[i];
			ans = max(ans, dp[i]);
		}
		cout << ans << "\n";
	}

}