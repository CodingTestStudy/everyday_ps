#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include <queue>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e9
using namespace std;
int n, m;
int path[501];
vector<vector<pair<int, int>>>v;
int dist[501];
priority_queue<pair<int, int>>q;
vector<int>ans;
void search(int st, int ed) {
	dist[st] = 0;
	q.push({ 0,st });
	while (!q.empty()) {
		auto [cost, x] = q.top();
		
		q.pop();
		if (dist[x] != -cost)continue;
		for (int i = 0; i < v[x].size(); i++) {
			auto [nx, ncost] = v[x][i];
			if (dist[nx] > dist[x] + ncost) {
				dist[nx] = dist[x] + ncost;
				path[nx] = x;
				q.push({ -dist[nx],nx });
			}
		}
	}

}
void bfs(int st,int  ed) {
	dist[st] = 0;
	q.push({ 0,st });
	while (!q.empty()) {
		auto [cost, x] = q.top();
		q.pop();
		if (dist[x] != -cost)continue;
		for (int i = 0; i < v[x].size(); i++) {
			auto [nx, ncost] = v[x][i];
			if (ans[x] == nx)continue;
			if (dist[nx] > dist[x] + ncost);
			dist[nx] = dist[x] + ncost;
			q.push({ -dist[nx],nx });
		}
	}
}
void search1(int st,int ed) {
	int T = ed;
	while (T != st) {
		int next = path[T];
		ans[next] = T;
		T = next;
	}
}
int main() {
	while (1) {
		int a, b; cin >> a >> b;
		if (a == 0 && b == 0)break;
		int st, ed; cin >> st >> ed;
		v.resize(a + 1);
		ans.resize(a + 1);
		for (int i = 0; i < b; i++) {
			int x, y, z; cin >> x >> y >> z;
			v[x].push_back({ y,z });
		}
		fill(dist, dist + a + 1, INF);
		search(st, ed);
		fill(dist, dist + a + 1, INF);
		search1(st,ed);
		bfs(st, ed);
		if (dist[ed] == INF)cout << "-1" << "\n";
		else cout << dist[ed] << "\n";
		memset(path, false, sizeof(path));
		ans.clear();
		v.clear();
		
	}
}