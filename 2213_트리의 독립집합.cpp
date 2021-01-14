#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;
int dist[10001];
int dp[10001][2];
bool check[10001];
int cnt[10001];
vector < vector<int>>v;
vector<vector<int>>tree;

void dfs(int x) {
	check[x] = true;
	for (auto next : v[x]) {
		if (check[next])continue;
		check[next] = true;
		tree[x].push_back(next);
		dfs(next);
	}
}
int treedp(int now, bool ok) {
	int& res = dp[now][ok];
	if (res != -1)return res;
	int cost = 0;
	if (ok) {
		for (auto next : tree[now])cost += treedp(next, 0);
		 cost += dist[now];
	}
	else {
		for (auto next : tree[now]) {
			cost += max(treedp(next, 1), treedp(next, 0));
			if (treedp(next, 1) >= treedp(next, 0))cnt[next] = 1;
		}
	}
	return res=cost;
}
vector<int>ans;
void find(int now, bool ok) {
	if (ok) {
		ans.push_back(now);
		for (auto next : tree[now])find(next, 0);
	}
	else {
		for (auto next : tree[now])find(next, cnt[next]);
	}
}
int main() {
	fastio;
	cin >> n;
	v.resize(n + 10);
	tree.resize(n + 10);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)cin >> dist[i];
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	int temp= max(treedp(1, 0), treedp(1, 1));
	cout << temp << endl;
	if (treedp(1, 0) <= treedp(1, 1))cnt[1] = 1;
	find(1, cnt[1]);
	//cout << endl;
	//for (int i = 1; i <= n; i++) {
	//	cout << dp[i][1] << " ";

	//}
	//cout << endl;
	//for (int i = 1; i <= n; i++) {
	//	cout << dp[i][0] << " ";

	//}
	//cout << endl;
	sort(ans.begin(), ans.end());
	for (auto T : ans)cout << T << " ";
}