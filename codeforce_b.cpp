#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool dp[40001] = { 1, };
vector<int>v;
int main() {
	int test_case; cin >> test_case;

	for (int i = 2; i <= sqrt(40000); i++) {
		if (dp[i] == 1)continue;
		for (int j = i * i; j <= 40000; j += i)dp[j] = 1;
	}
	for (int i = 0; i <= 40000; i++) {
		if (!dp[i])v.push_back(i);
	}
	while (test_case--) {
		int cur; cin >> cur;
		int idex = lower_bound(v.begin(), v.end(), cur + 1) - v.begin();
		int idex1 = lower_bound(v.begin(), v.end(), v[idex] + cur) - v.begin();
		cout << v[idex] * v[idex1] << "\n";
	}
}