#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 987654321
using namespace std;
int n, m;
int dist[811];
vector<vector<pair<int, int>>>v;

void daic(int st) {
	dist[st] = 0;
	priority_queue<pair<int, int>>q;
	q.push({ 0,st });
	while (!q.empty()) {
		auto [cost, now] = q.top();
		q.pop();
		
		for (int i = 0; i < v[now].size(); i++) {
			auto [next, ncost] = v[now][i];
			if (dist[next] > dist[now] + ncost) {
				dist[next] = dist[now] + ncost;
				q.push({ -ncost,next });
			}
		}
	}
}
int main() {
	cin >> n >> m; f;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	int st, ed; cin >> st >> ed;
	bool ok = false;
	fill(dist, dist + n + 1, INF);
	daic(1);//1번부터 수행해서 st,ed 까지의 최단거리를 구한다.
	if (dist[st] == INF || dist[ed] == INF)ok = true;
	int temp1 = dist[st], temp2 = dist[ed];
	fill(dist, dist + n + 1, INF);
	daic(st);//st->ed까지의 최단거리==ed->st 까지의 최단거리
	if (dist[ed] == INF)ok = true;
	temp1 += dist[ed];
	temp2 += dist[ed];
	fill(dist, dist + n + 1, INF);
	daic(st);// st->n까지의 최단거리
	if (dist[n] == INF)ok = true;
	temp2 += dist[n];
	fill(dist, dist + n + 1, INF);
	daic(ed);
	temp1 += dist[n];
	if (ok)cout << "-1";
	else cout << min(temp1, temp2);
}