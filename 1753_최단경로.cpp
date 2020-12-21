#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include <queue>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e9
typedef long long ll;
using namespace std;
int n, m;
int dist[20001];
vector<vector<pair<int,int>>>v;
priority_queue<pair<int, int>>q;
void diac(int st) {
	dist[st] = 0;
	q.push({ 0,st });
	while (!q.empty()) {
		auto [cost,x] = q.top();
		q.pop();
		if (dist[x] != -cost)continue;
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int ncost = v[x][i].second;
			if (dist[nx] > dist[x] + ncost) {
				dist[nx] = dist[x] + ncost;
				q.push({ -dist[nx],nx });
			}
		}
	}

}
int main() {
	int st; cin >> n >> m>>st;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	fill(dist, dist + n+1, INF);
	diac(st);
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF)cout << dist[i] << "\n";
		else cout << "INF" << "\n";
	}
}