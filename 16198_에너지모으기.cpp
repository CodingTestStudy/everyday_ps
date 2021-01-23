#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool check[11];
vector<int>v;
int ans;
void dfs(int cnt,int sum) {
	if (cnt == v.size()-2) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i < v.size() - 1; i++) {
		if (check[i])continue;
		check[i] = true;
		int next, prev;
		for (int j = i + 1; j <= v.size() - 1; j++) {
			if (check[j])continue;
			next = j;
			break;
		}
		for (int k = i - 1; k >= 0; k--) {
			if (check[k])continue;
			prev = k;
			break;
		}
		dfs(cnt + 1, v[next] * v[prev] + sum);
		check[i] = false;
	}
}

int main() {
	int n; cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	dfs(0, 0);
	cout << ans;
}