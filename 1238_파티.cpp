#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define INF 1e9
using namespace std;

int dist[1001];
int sum[1001];
vector < vector<pair<int, int>>>v,v1;
int n, m, k;
void daic(int st) {
	dist[st] = 0;
	priority_queue<pair<int, int>>q;
	q.push({ 0,st });
	while (!q.empty()) {
		auto [cost, now] = q.top();
		q.pop();
		for (int i = 0; i < v1[now].size(); i++) {
			auto [next, ncost] = v1[now][i];
			if (dist[next] > ncost + dist[now]) {
				dist[next] = ncost + dist[now];
				q.push({ -dist[next],next });
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	v.resize(n + 1);
	v1.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b,c; cin >> a >> b>>c;
		v[a].push_back({ b,c });
		v1[b].push_back({ a,c });
	}
	fill(dist, dist + 1001, INF);
	daic(k);
	for (int i = 1; i <= n; i++) {
		sum[i] = dist[i];
	}
	//for (int i = 1; i <= n; i++)cout << sum[i] << " ";
	//cout << endl;
	for (int i = 1; i <= n; i++) {
		fill(dist, dist + 1001, INF);
		daic(i);
		sum[i] += dist[k];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, sum[i]);
	}
	cout << ans;
}